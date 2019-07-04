/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 16:19:53 by udraugr-          #+#    #+#             */
/*   Updated: 2019/07/04 16:20:54 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/twenty_one_sh.h"

static void		out(int fd, char **old_result, t_stream *stream)
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

static void		ft_ungrab_arr(char **param)
{
	int			i;
	char		*back;

	i = -1;
	while (param[++i])
	{
		back = param[i];
		param[i] = ft_ungrab(param[i], 0);
		ft_strdel(&back);
	}
}

void			ft_exec(char *str, char **arr_env,
					char **old_result, t_stream *stream)
{
	char		**param;
	int			pipefd[2];
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
			out(pipefd[0], old_result, stream);
		close(stream->pipefd[1]);
		close(stream->pipefd[0]);
	}
//	tmp2 = ft_strsplit("/bin/rm /goinfre/.tmp", ' ');
//	father = fork();
//	if (!father)
//		execve(tmp2[0], tmp2, arr_env);
//	else
//		wait(0);
//	ft_del_arr(&tmp2);
//	ft_get_back(stream);
//	ft_printf("\n\n\n%s\n\n\n", *old_result);
	ft_del_arr(&param);
}
