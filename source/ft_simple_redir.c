/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 19:01:50 by udraugr-          #+#    #+#             */
/*   Updated: 2019/07/19 22:00:23 by draynor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/twenty_one_sh.h"

static void	ft_small_simple(char *file, int fd)
{
	char	*tmp;

	tmp = ft_ungrab(file, 0);
	ft_putendl_fd(tmp, fd);
	ft_strdel(&tmp);
}

static int	simple_in(char ***arr_string, int i,
						t_stream *stream, int check)
{
	int		fd;
	char	*file;

	if (!(file = (*arr_string)[i + 2]))
		return (EXEC_FAIL);
	if (check == 0 || check == 4)
	{
		if ((file_check(file, BIN, R_OK, file) == 0) ||
			((fd = open(file, O_RDONLY)) == -1))
			return (EXEC_FAIL);
	}
	else
	{
		if ((fd = open("/goinfre/.tmp", O_CREAT | O_WRONLY |
										O_TRUNC, S_IRWXU)) == -1)
			return (EXEC_FAIL);
		ft_small_simple(file, fd);
		close(fd);
		if ((fd = open("/goinfre/.tmp", O_RDONLY)) == -1)
			return (EXEC_FAIL);
	}
	my_reopen(&(stream->std_now[0]), fd);
	return (EXEC_SUCC);
}

static int	simple_out(char ***arr_string, int i,
						t_stream *stream, int check)
{
	int		fd;
	char	*file;

	file = (*arr_string)[i + 2];
	if (!file || (!access(file, F_OK) &&
				file_check(file, BIN, W_OK, file) == 0))
		return (EXEC_FAIL);
	if (check == 2)
	{
		if ((fd = open(file, O_CREAT | O_WRONLY | O_TRUNC,
						S_IRWXU)) == -1)
			return (EXEC_FAIL);
	}
	else
	{
		if ((fd = open(file, O_CREAT | O_WRONLY | O_APPEND,
						S_IRWXU)) == -1)
			return (EXEC_FAIL);
	}
	if (stream->std_now[1] != -1)
		close(stream->std_now[1]);
	stream->std_now[1] = fd;
	return (EXEC_SUCC);
}

int			ft_simple_redir(char ***arr_string, int i,
							t_stream *stream, int check)
{
	int		ans;

	if (check == 2 || check == 3)
		ans = simple_out(arr_string, i, stream, check);
	else
		ans = simple_in(arr_string, i, stream, check);
	if (ans == EXEC_SUCC)
	{
		ft_strdel(&(*arr_string)[i + 1]);
		ft_strdel(&(*arr_string)[i + 2]);
		(*arr_string)[i + 1] = ft_strdup("");
		(*arr_string)[i + 2] = ft_strdup("");
	}
	return (ans);
}
