/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 18:31:12 by udraugr-          #+#    #+#             */
/*   Updated: 2019/07/08 15:01:58 by udraugr-         ###   ########.fr       */
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
									char ***param, int count)
{
	pid_t		main;
	t_vector	*tmp;

	tmp = ft_get_myproc(0, 0);
	while (((t_stream *)tmp->content)->now_pipe != count)
		tmp = tmp->next;
	if (ft_get_redir(turn_str, ((t_stream *)tmp->content)) == EXEC_FAIL)
		return (EXEC_FAIL);
	*param = ft_strsplit(*turn_str, ' ');
	ft_ungrab_arr(*param);
	if ((main = fork()) == -1)
		return (EXEC_FAIL);
	if (!main)
	{
//		ft_back_screen(0);
		ft_change_std((t_stream *)tmp->content);
		ft_close_std(ft_get_myproc(0, 0));
//		close(ft_get_mygv(NULL)->g_fd_r);
//		close(ft_get_mygv(NULL)->g_fd_w);
		if (ft_forward(*turn_str, arr_env) == EXEC_FAIL)
			ft_exec(arr_env, *param);
		exit(EXEC_SUCC);
	}
	((t_stream *)tmp->content)->proc = main;
	return (EXEC_SUCC);
}

static void		ft_wait(int	left_proc)
{
	pid_t		tmp;
	t_vector	*my_proc;
	t_vector	*my_proc_to_beg;
	//t_stream	**ok;
	//t_vector	*tmp_v;
	
	while (left_proc > 0)
	{
		my_proc = ft_get_myproc(0, 0);
		while (my_proc)
		{
			tmp = waitpid(((t_stream *)my_proc->content)->proc, 0, WNOHANG);
			if (tmp)
			{
				my_proc_to_beg = my_proc;
				my_proc = my_proc->next;
				while (my_proc_to_beg)
				{
					tmp = waitpid(((t_stream *)my_proc_to_beg->content)->proc, 0, WNOHANG);
					if (!tmp)
						kill(((t_stream *)my_proc_to_beg->content)->proc, SIGKILL);
					//ok = (t_stream **)(&my_proc_to_beg->content);
					//ft_destroy_t_stream(ok);
					//tmp_v = my_proc_to_beg;
					my_proc_to_beg = my_proc_to_beg->previous;
					//ft_del_vector(&tmp_v);
					--left_proc;
				}
				ft_get_myproc(my_proc, 1);
			}
			if (my_proc)
				my_proc = my_proc->next;
		}
	}
}

void			ft_execute(char *str, t_vector **env)
{
	char		**turn;
	char		**arr_env;
	char		**param;
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
		param = 0;
		if (ft_prep_for_execute(&turn[i], arr_env, &param, i + 1) == EXEC_FAIL)
		{
			ft_error(REDICTFAIL, "");
			ft_del_arr(&arr_env);
			ft_del_arr(&param);
			break ;
		}
		ft_del_arr(&arr_env);
		ft_del_arr(&param);
	}
	ft_close_std(ft_get_myproc(0, 0));
	ft_wait(arr_len);
	ft_del_arr(&turn);
}
