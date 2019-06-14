/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 18:31:12 by udraugr-          #+#    #+#             */
/*   Updated: 2019/06/14 17:18:12 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/twenty_one_sh.h"

void			ft_abort(int sign)
{
	if (sign == SIGINT)
	{
		signal(SIGINT, ft_restart);
		write(1, "\n\033[31mABORT\n\033[0m", 16);
	}
}

static void		out(int fd, char **old_result)
{
	int			bits;
	char		*tmp;
	char		*buff;

	if (!(buff = ft_memalloc(STDMES)))
		return ;
	while ((bits = read(fd, buff, STDMES)) > 0)
	{
		tmp = *old_result;
		*old_result = ft_strjoin(*old_result, buff);
		ft_strdel(&tmp);
	}
	ft_strdel(&buff);
}

static void		pipe_redir(char *str, char **arr_env, char **old_result)
{
	char		**param;
	int			pipefd[2];
	int			savestd[2];
	pid_t		father;
	int			tmp;

	param = ft_strsplit(str, ' ');
	pipe(pipefd);
	write(1, param[0], ft_strlen(param[0]));
	father = fork();
	if (!father)
	{
		savestd[0] = dup(0);
		savestd[1] = dup(1);
		dup2(pipefd[0], 0);
		dup2(pipefd[1], 1);
		if ((execve(param[0], param, arr_env) == -1))
			return ;
	}
	else
	{
		write(pipefd[1], *old_result, ft_strlen(*old_result));
		close(pipefd[1]);
		ft_strdel(old_result);
		*old_result = ft_strdup("\0");
		out(pipefd[0], old_result);
		wait(0);
		close(pipefd[0]);
		dup2(savestd[0], 0);
		dup2(savestd[1], 1);
		close(savestd[0]);
		close(savestd[1]);
	}
	ft_del_arr(&param);
}

void			ft_execute(char *str, t_vector **env)
{
	char		**arr_env;
	char		**turn;
	char		*old_result;
	int			i;

	arr_env = ft_vector_to_arr(env);
	signal(SIGINT, ft_abort);
	turn = ft_strsplit(str, '|');
	i = 0;
	old_result = ft_strdup("\0");
	while (turn[i])
	{
		pipe_redir(turn[i], arr_env, &old_result);
		++i;
	}
	write(1, old_result, ft_strlen(old_result));
	ft_del_arr(&turn);
	ft_del_arr(&arr_env);
}
