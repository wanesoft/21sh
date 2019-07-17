/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 18:31:12 by udraugr-          #+#    #+#             */
/*   Updated: 2019/07/17 15:44:07 by udraugr-         ###   ########.fr       */
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
	if (sign == SIGCHLD)
	{
		signal(SIGCHLD, ft_abort);
		wait(0);
	}
}

static int		ft_prep_for_execute(char **turn_str, char **arr_env,
									int count)
{
	t_vector	*tmp;
	char		**param;

	tmp = ft_get_myproc(0, 0);
	while (((t_stream *)tmp->content)->now_pipe != count)
		tmp = tmp->next;
	if (ft_get_redir(turn_str, ((t_stream *)tmp->content)) == EXEC_FAIL)
		return (EXEC_FAIL);
	param = ft_strsplit(*turn_str, ' ');
	ft_ungrab_arr(param);
	if ((((t_stream *)tmp->content)->proc = fork()) == -1)
		return (EXEC_FAIL);
	if (!((t_stream *)tmp->content)->proc)
	{
		ft_change_std((t_stream *)tmp->content);
		ft_close_std(ft_get_myproc(0, 0));
		if (ft_forward(*turn_str, arr_env) == EXEC_FAIL)
			ft_exec(arr_env, param);
		else
			exit(EXEC_SUCC);
		exit(EXEC_FAIL);
	}
	ft_del_arr(&param);
	return (EXEC_SUCC);
}

void			ft_execute(char *str, t_vector **env)
{
	char		**turn;
	char		**arr_env;
	int			i;
	int			arr_len;

	signal(SIGINT, ft_abort);
	signal(SIGCHLD, ft_abort);
	turn = ft_strsplit(str, '|');
	i = -1;
	arr_len = ft_arrlen(turn);
	ft_get_myproc(create_vect_for_pipes(arr_len), 1);
	while (++i < arr_len)
	{
		arr_env = ft_vector_to_arr(env);
		if (ft_prep_for_execute(&turn[i], arr_env, i + 1) == EXEC_FAIL)
		{
			ft_error(REDICTFAIL, "");
			ft_del_arr(&arr_env);
			break ;
		}
		ft_del_arr(&arr_env);
	}
	ft_close_std(ft_get_myproc(0, 0));
	ft_wait(arr_len);
	ft_del_arr(&turn);
}
