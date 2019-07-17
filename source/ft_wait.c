/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wait.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 14:03:41 by udraugr-          #+#    #+#             */
/*   Updated: 2019/07/17 14:34:16 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/twenty_one_sh.h"

static void		ft_close_already_done_work_process(t_vector *my_proc_to_beg,
													int *left_proc)
{
	pid_t		tmp;
	t_stream	**ok;
	t_vector	*tmp_v;

	while (my_proc_to_beg)
	{
		tmp = waitpid(((t_stream *)my_proc_to_beg->content)->proc, 0, WNOHANG);
		if (!tmp)
			kill(((t_stream *)my_proc_to_beg->content)->proc, SIGKILL);
		ok = (t_stream **)(&my_proc_to_beg->content);
		ft_destroy_t_stream(ok);
		tmp_v = my_proc_to_beg;
		my_proc_to_beg = my_proc_to_beg->previous;
		ft_del_vector(&tmp_v);
		--(*left_proc);
	}
}

void			ft_wait(int left_proc)
{
	pid_t		tmp;
	t_vector	*my_proc;
	t_vector	*my_proc_to_beg;

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
				ft_get_myproc(my_proc, 1);
				ft_close_already_done_work_process(my_proc_to_beg, &left_proc);
			}
			if (my_proc)
				my_proc = my_proc->next;
		}
	}
}
