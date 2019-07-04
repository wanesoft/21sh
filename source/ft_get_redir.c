/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 11:21:30 by udraugr-          #+#    #+#             */
/*   Updated: 2019/07/04 18:25:06 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/twenty_one_sh.h"

static int		ft_check(char *str_tmp)
{
	char		*redirs[9];
	int			i;

	redirs[0] = "<";
	redirs[1] = "<<";
	redirs[2] = ">";
	redirs[3] = ">>";
	redirs[4] = "&<";
	redirs[5] = "&>";
	redirs[6] = ">&";
	redirs[7] = "<&";
	redirs[8] = 0;
	i = 0;
	while (redirs[i])
	{
		if (ft_strequ(str_tmp, redirs[i]) == 1)
			return (i);
		++i;
	}
	return (-1);
}

static int		ft_fill_redirs(char **arr_string, int i,
									t_stream *stream)
{
	int			check;
	int			res;

	res = EXEC_SUCC;
	check = ft_check(arr_string[i + 1]);
	if (check != -1 && ft_check(arr_string[i + 2]) != -1)
		return (EXEC_FAIL);
	if (check == 6)
		res = ft_difficult_redir(&arr_string, i, stream, check);
	else if (check == 5)
		res = ft_advanced_redir(&arr_string, i, stream, check);
	else if (check >= 0)
		res = ft_simple_redir(&arr_string, i, stream, check);
	return (res);
}

int				ft_get_redir(char **string, t_stream *stream)
{
	char		**arr_string;
	int			i;
	char		*ans;

	arr_string = ft_strsplit(*string, ' ');
	i = -1;
	while (arr_string[++i])
	{
		if (arr_string[i + 1])
			if (ft_fill_redirs(arr_string, i, stream) == EXEC_FAIL)
				return (EXEC_FAIL);
	}
	ans = ft_strdup("");
	i = -1;
	while (arr_string[++i])
	{
		ans = ft_strjoin_pro(ans, arr_string[i], ONLY_FIRST);
		ans = ft_strjoin_pro(ans, " ", ONLY_FIRST);
	}
	ft_del_arr(&arr_string);
	ft_strdel(string);
	*string = ans;
	return (EXEC_SUCC);
}
