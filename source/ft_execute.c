/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 18:31:12 by udraugr-          #+#    #+#             */
/*   Updated: 2019/06/18 13:07:33 by udraugr-         ###   ########.fr       */
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
	long long	bits;
	char		*tmp;
	char		buff[STDMES];

	while ((bits = (long long)read(fd, buff, STDMES - 1)) > 0)
	{
		buff[STDMES - 1] = 0;
		tmp = *old_result;
		*old_result = ft_strjoin(*old_result, buff);
		ft_strdel(&tmp);
	}
}

static void		pipe_redir(char *str, char **arr_env, char **old_result)
{
	char		**param;
	int			pipefd[2];
	pid_t		father;
	int			tmp;
//	char		**tmp2;

	param = ft_strsplit(str, ' ');
	if ((tmp = open("/goinfre/.tmp", O_CREAT | O_RDWR, S_IRWXU)) == -1)
		return ;
	write(tmp, *old_result, ft_strlen(*old_result));
	ft_strdel(old_result);
	pipe(pipefd);
	father = fork();
	if (!father)
	{
		dup2(tmp, 0);
		dup2(pipefd[1], 1);
		if ((execve(param[0], param, arr_env) == -1))
			return ;
	}
	else
	{
		*old_result = ft_strdup("\0");
		out(pipefd[0], old_result);
		wait(0);
		close(pipefd[1]);
		close(pipefd[0]);
	}
	close(tmp);
	/*tmp2 = ft_strsplit("/bin/rm /goinfre/.tmp", ' ');
	father = fork();
	if (!father)
		execve(tmp2[0], tmp2, arr_env);
	else
		wait(0);
	ft_del_arr(&tmp2);*/
	ft_del_arr(&param);
}

static int		ft_prep_for_execute(char **turn_str, t_stream *stream,
									char **old_result, t_vector **env)
{
	char		**arr_env;
	
	arr_env = ft_vector_to_arr(env);
	//str = ft_divide(str, " \t\n");
	//if (ft_get_redir(turn_str, stream) == EXEC_FAIL)
	//	return (EXEC_FAIL);
	//ft_input_redirect(&redirs, old_result);
	if (ft_forward(*turn_str, env) == EXEC_FAIL)
		pipe_redir(*turn_str, arr_env, old_result);
	//ft_output_redirect(&stream->output, old_result);
	ft_del_arr(&arr_env);
	return (EXEC_SUCC);
}

void			ft_execute(char *str, t_vector **env)
{
	char		**turn;
	char		*old_result;
	t_stream	*stream;
	int			i;
	int			arr_len;
	
	signal(SIGINT, ft_abort);
	turn = ft_strsplit(str, '|');
	i = 0;
	old_result = ft_strdup("");
	stream = ft_create_stream();
	arr_len = ft_arrlen(turn);
	while (i < arr_len)
	{
		if (ft_prep_for_execute(&turn[i], stream,
								&old_result, env) == EXEC_FAIL)
		{
			ft_get_back(stream);
			break ;
		}
		++i;
		if (!turn[i])
			write(1, old_result, ft_strlen(old_result));
		ft_get_back(stream);
	}
	ft_strdel(&old_result);
	ft_del_arr(&turn);
	destroy_t_stream(&stream);
}
