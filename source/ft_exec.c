/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 16:19:53 by udraugr-          #+#    #+#             */
/*   Updated: 2019/06/26 12:04:56 by udraugr-         ###   ########.fr       */
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

//static void	prepare(t_stream *stream, char **old_res, int pipe_fd[2])
//{
//	int		fd;
//
//	if (stream->now_pipe != 1 && stream->std_now[0] == -1)
//	{
//		if ((fd = open("/goinfre/.tmp", O_CREAT | O_RDWR | O_TRUNC,
//					   S_IRWXU)) == -1)
//			return ;
//		write(fd, *old_res, ft_strlen(*old_res));
//		close (fd);
//		if ((fd = open("/goinfre/.tmp", O_RDWR)) == -1)
//			return ;
//
//		stream->std_now[0] = fd;
//	}
//	if (stream->now_pipe != stream->all_pipe &&
//		stream->std_now[1] == -1)
//		stream->std_now[1] = pipe_fd[1];
//	ft_strdel(old_res);
//}
//
//static void	ft_change_std(t_stream *stream)
//{
//	if (stream->std_now[0] != -1)
//		dup2(stream->std_now[0], 0);
//	if (stream->std_now[1] != -1)
//		dup2(stream->std_now[1], 1);
//	if (stream->std_now[2] != -1)
//		dup2(stream->std_now[2], 2);
//}

void		ft_exec(char *str, char **arr_env,
					   char **old_result, t_stream *stream)
{
	char		**param;
	int			pipefd[2];
	pid_t		father;
	char		*back;
	int			i;
	
	param = ft_strsplit(str, ' ');
	i = -1;
	while (param[++i])
	{
		back = param[i];
		param[i] = ft_ungrab(param[i], 0);
		ft_strdel(&back);
	}
//	pipe(pipefd);
//	prepare(stream, old_result, pipefd);
//	ft_change_std(stream);
	//ft_printf("\n\n%d %d %d\n\n", stream->std_now[0], stream->std_now[1], stream->std_now[2]);
	//ft_printf("\n\n%d %d %d\n\n", stream->std_now[0], stream->std_now[1], stream->std_now[2]);
	father = fork();
	if (!father)
	{
//		if (ft_strequ(param[0], "/bin/cat"))
//		{
//			int fd = open("/goinfre/.tmp", O_RDONLY);
//			dup2(fd, 0);
//		}
		if ((execve(param[0], param, arr_env) == -1))
			return ;
	}
	else
	{
		wait(0);
		*old_result = ft_strdup("");
		if (stream->now_pipe != stream->all_pipe)
        {
            out(pipefd[0], old_result, stream);
//			ssize_t		bits;
//			char		buff[STDMES];
//			int			sd;
//			while (ioctl(pipefd[0], FIONREAD, &sd) == 0 && sd > 0)
//			{
//				bits = read(pipefd[0], buff, STDMES - 1);
//				buff[bits] = 0;
//				*old_result = ft_strjoin_pro(*old_result, buff, ONLY_FIRST);
//			}
        }

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
