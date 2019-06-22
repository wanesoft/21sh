/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 11:21:30 by udraugr-          #+#    #+#             */
/*   Updated: 2019/06/18 14:21:33 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/twenty_one_sh.h"

static int		ft_check(char *str_tmp)
{
	char		*redirs[9] = {"<", "<<", "<&", "&<",
								">", ">>", ">&", "&>",(void *)0};
	int			i;
	
	i = 0;
	while (redirs[i])
	{
		if (ft_strequ(str_tmp, redirs[i]) == 1)
			return (i);
		++i;
	}
	return (-1);
}

int				ft_get_redir(char **string, t_stream *stream)
{
	char		**arr_string;
	int			i;
	char		*ans;
	
	arr_string = ft_strsplit(*string, ' ');
	ans = ft_strdup("");
	i = 0;
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
