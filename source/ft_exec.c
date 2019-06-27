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

static void		out(int fd, char **old_result)
{
	ssize_t		bits;
	char		buff[STDMES];
	
	while ((bits = read(fd, buff, STDMES - 1)) > 0)
	{
		buff[bits] = 0;
		*old_result = ft_strjoin_pro(*old_result, buff, ONLY_FIRST);
	}
}

static void	prepare(t_stream *stream, char **old_res, int pipe_fd[2])
{
	int		fd;
	
	if (stream->now_pipe != 1 && stream->std_now[0] == -1)
	{
		if ((fd = open("/goinfre/.tmp", O_CREAT | O_RDWR, S_IRWXU)) == -1)
			return ;
		stream->std_now[0] = fd;
		write(fd, *old_res, ft_strlen(*old_res));
	}
	if (stream->now_pipe != stream->all_pipe &&
		stream->std_now[1] == -1)
		stream->std_now[1] = pipe_fd[1];
	ft_strdel(old_res);
}

static void	ft_change_std(t_stream *stream)
{
	if (stream->std_now[0] != -1)
		dup2(stream->std_now[0], 0);
	if (stream->std_now[1] != -1)
		dup2(stream->std_now[1], 1);
	if (stream->std_now[2] != -1)
		dup2(stream->std_now[2], 2);
}

void		ft_exec(char *str, char **arr_env,
					   char **old_result, t_stream *stream)
{
	char		**param;
	int			pipefd[2];
	pid_t		father;
	char		**tmp2;
	
	param = ft_strsplit(str, ' ');
	pipe(pipefd);
	//prepare(stream, old_result, pipefd);
	//ft_change_std(stream);
	dup2(pipefd[0], 0);
	dup2(pipefd[1], 1);
	father = fork();
	if (!father)
	{
		close(pipefd[0]);
		if ((execve(param[0], param, arr_env) == -1))
			return ;
	}
	else
	{
		close(pipefd[1]);
		wait(0);
		*old_result = ft_strdup("");
		if (stream->now_pipe != stream->all_pipe)
        {
            //out(pipefd[0], old_result);
			ssize_t        bits;
            char        buff[STDMES];
			int sd;
//            while (ioctl(pipefd[0], FIONREAD, &sd) == 0 && read(pipefd[0], buff, STDMES - 1))
			while (ioctl(pipefd[0], FIONREAD, &sd) == 0 && sd > 0)
            {
//                buff[bits] = 0;
				bits = read(pipefd[0], buff, STDMES - 1);
				buff[bits] = 0;
                *old_result = ft_strjoin_pro(*old_result, buff, ONLY_FIRST);
//				close(pipefd[0]);
            }
        }
       // wait(0);
		close(pipefd[0]);
	}
//	tmp2 = ft_strsplit("/bin/rm /goinfre/.tmp", ' ');
//	father = fork();
//	if (!father)
//		execve(tmp2[0], tmp2, arr_env);
//	else
//		wait(0);
//	ft_del_arr(&tmp2);
	ft_del_arr(&param);
}
