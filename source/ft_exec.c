/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 16:19:53 by udraugr-          #+#    #+#             */
/*   Updated: 2019/07/06 20:42:20 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/twenty_one_sh.h"

static void		out(char **old_result, t_stream *stream)
{
	ssize_t			bits;
	char			buff[STDMES];
	int				sd;

	while (ioctl(stream->pipefd[0], FIONREAD, &sd) == 0 && sd > 0)
	{
		bits = read(stream->pipefd[0], buff, STDMES - 1);
		buff[bits] = 0;
		*old_result = ft_strjoin_pro(*old_result, buff, ONLY_FIRST);
	}
}

void			ft_exec(char *str, char **arr_env,
						char **old_result, t_stream *stream)
{
	char		**param;
	pid_t		father;

	param = ft_strsplit(str, ' ');
	ft_ungrab_arr(param);
	father = fork();
	if (!father)
	{
		if ((execve(param[0], param, arr_env) == -1))
			return ;
	}
	else
	{
		wait(0);
		*old_result = ft_strdup("");
		if (stream->now_pipe != stream->all_pipe)
			out(old_result, stream);
		(stream->pipefd[1] != -1) ? close(stream->pipefd[1]) : 0;
		(stream->pipefd[0] != -1) ? close(stream->pipefd[0]) : 0;
	}
	ft_putstr_fd(tgetstr("vi", NULL), STDIN_FILENO);
	ft_del_arr(&param);
}
