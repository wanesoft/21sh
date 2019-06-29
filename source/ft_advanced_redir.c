/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_redir.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 15:45:37 by udraugr-          #+#    #+#             */
/*   Updated: 2019/06/24 15:45:39 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/twenty_one_sh.h"

static int  ft_check(char *numb)
{
	int		i;
	int		ans;
	
	i = 0;
    while (numb[i])
	{
		if (numb[i] < 48 || numb[i] > 57)
			return (EXEC_FAIL);
		++i;
	}
	ans = ft_atoi(numb);
	if (ans != 1 && ans != 2)
		return (EXEC_FAIL);
	return (EXEC_SUCC);
}

static int	ft_adv_out(int std, t_stream *stream, char ***arr_string, int i)
{
	int		fd;
	char	*file;
	
	file = (*arr_string)[i + 2];
	if (ft_strequ(file, "-"))
		file = "/dev/null";
	else if (!file ||
		(!access(file, F_OK) && file_check(file, BIN, W_OK, file) == 0))
		return (EXEC_FAIL);
	if ((fd = open(file, O_CREAT | O_WRONLY | O_TRUNC,
				   S_IRWXU)) == -1)
		return (EXEC_FAIL);
	if (std == -1)
	{
		if (stream->std_now[1] != -1)
			close(stream->std_now[1]);
		if (stream->std_now[2] != -1)
			close(stream->std_now[2]);
		stream->std_now[1] = fd;
		stream->std_now[2] = fd;
	}
	else
	{
		if (stream->std_now[std] != -1)
			close(stream->std_now[std]);
		stream->std_now[std] = fd;
	}
	return (EXEC_SUCC);
}

int			ft_advanced_redir(char ***arr_string, int i,
							t_stream *stream, int check)
{
	int		ans;
    int     std;
    
    std = -1;
    ans = EXEC_SUCC;
    if (ft_check((*arr_string)[i]) == EXEC_SUCC)
        std = ft_atoi((*arr_string)[i]);
	if ((ans = ft_adv_out(std, stream,
						  arr_string, i)) == EXEC_SUCC)
	{
		if (std != -1)
		{
			ft_strdel(&(*arr_string)[i]);
			(*arr_string)[i] = ft_strdup("");
		}
		ft_strdel(&(*arr_string)[i + 1]);
		ft_strdel(&(*arr_string)[i + 2]);
		(*arr_string)[i + 1] = ft_strdup("");
		(*arr_string)[i + 2] = ft_strdup("");
	}
	return (ans);
}
