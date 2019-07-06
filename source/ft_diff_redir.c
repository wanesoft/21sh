/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_difficult_redir.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 15:45:47 by udraugr-          #+#    #+#             */
/*   Updated: 2019/07/05 16:16:09 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/twenty_one_sh.h"

static int		ft_check(char *numb)
{
	int			i;
	int			ans;

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

static int		ft_adv_out(int std_beg, int std_end, t_stream *stream)
{
	if (stream->std_now[std_beg] != -1)
	{
		close(stream->std_now[std_beg]);
	}
	if (std_end != -1)
		stream->std_now[std_beg] = dup(stream->std_now[std_end]);
	else
	{
		if ((stream->std_now[std_beg] = open("/dev/null", O_WRONLY)) == -1)
			return (EXEC_FAIL);
	}
	return (EXEC_SUCC);
}

static void		ft_del_str_from_array(char ***arr_string, int i)
{
	ft_strdel(&(*arr_string)[i]);
	ft_strdel(&(*arr_string)[i + 1]);
	ft_strdel(&(*arr_string)[i + 2]);
	(*arr_string)[i] = ft_strdup("");
	(*arr_string)[i + 1] = ft_strdup("");
	(*arr_string)[i + 2] = ft_strdup("");
}

int				ft_difficult_redir(char ***arr_string, int i, t_stream *stream)
{
	int			ans;
	int			std_beg;
	int			std_end;

	std_beg = -1;
	std_end = -1;
	ans = EXEC_SUCC;
	if (ft_check((*arr_string)[i]) == EXEC_SUCC &&
			(ft_check((*arr_string)[i + 2]) == EXEC_SUCC ||
			ft_strequ((*arr_string)[i + 2], "-")))
	{
		std_beg = ft_atoi((*arr_string)[i]);
		if (ft_strequ((*arr_string)[i + 2], "-"))
			std_end = -1;
		else
			std_end = ft_atoi((*arr_string)[i + 2]);
	}
	else
		return (EXEC_FAIL);
	if ((ans = ft_adv_out(std_beg, std_end, stream)) == EXEC_SUCC)
		ft_del_str_from_array(arr_string, i);
	return (ans);
}
