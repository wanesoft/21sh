/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space_for_redirs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 16:02:51 by udraugr-          #+#    #+#             */
/*   Updated: 2019/06/18 12:31:08 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/twenty_one_sh.h"

static int	check(char c)
{
	if (c == '>' ||
			c == '<' ||
			c == '&')
		return (EXEC_SUCC);
	return (EXEC_FAIL);
}

static void	ft_fill_redir(char *str, char *tmp_str, int *i_new, int *i_old)
{
	char	c;
	char	d;

	tmp_str[*i_new] = ' ';
	++(*i_new);
	tmp_str[*i_new] = str[*i_old];
	tmp_str[*i_new + 1] = ' ';
	(*i_new) += 2;
	++(*i_old);
	if (str[*i_old] && str[*i_old - 1])
	{
		c = str[*i_old - 1];
		d = str[*i_old];
		if ((c == '>' && (d == '>' || d == '&')) ||
				(c == '<' && (d == '<' || d == '&')) ||
				(c == '&' && (d == '>' || d == '<')))
		{
			tmp_str[*i_new - 1] = d;
			tmp_str[*i_new] = ' ';
			++(*i_new);
			++(*i_old);
		}
	}
}

void		ft_space_for_redirs(char **str)
{
	char	*new_str;
	char	*tmp_str;
	int		i_old;
	int		i_new;

	if (!(tmp_str = ft_memalloc(ft_strlen(*str) * 3 + 1))) //sho za 3??
		return ;
	i_old = 0;
	i_new = 0;
	while ((*str)[i_old])
	{
		if (check((*str)[i_old]) == EXEC_SUCC)
			ft_fill_redir(*str, tmp_str, &i_new, &i_old);
		else
		{
			tmp_str[i_new] = (*str)[i_old];
			++i_new;
			++i_old;
		}
	}
	new_str = ft_strdup(tmp_str);
	ft_strdel(str);
	ft_strdel(&tmp_str);
	*str = new_str;
}
