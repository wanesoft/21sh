/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replacment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 16:08:49 by udraugr-          #+#    #+#             */
/*   Updated: 2019/06/18 12:16:10 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/twenty_one_sh.h"

static int	ft_check(char c)
{
	if ((c >= 65 && c <= 90) ||
		(c >= 97 && c <= 122) ||
		(c >= 48 && c <= 57) ||
		c == '_')
		return (1);
	return (0);
}

static void	ft_replace(char **str, int i, char *replace, int len_var)
{
	char	*tmp;

	if (!(tmp = ft_memalloc(ft_strlen(*str) +
					ft_strlen(replace) + 1)))
		return ;
	ft_strncpy(tmp, *str, i);
	ft_strcpy(&tmp[i], replace);
	ft_strcpy(&tmp[i + ft_strlen(replace)], &(*str)[i + len_var]);
	ft_strdel(str);
	*str = tmp;
}

static void	ft_variab(char **str, t_vector **env, int i, char mod)
{
	char	*replace;
	char	*tmp;
	int		j;
	int		len_var;

	replace = 0;
	if (mod == '~')
	{
		replace = ft_take_value_env("HOME", env);
		len_var = 1;
	}
	else
	{
		j = 1;
		while (ft_check((*str)[i + j]))
			++j;
		tmp = ft_strndup(&(*str)[i + 1], j - 1);
		len_var = (int)ft_strlen(tmp) + 1;
		replace = ft_take_value_env(tmp, env);
		ft_strdel(&tmp);
	}
	ft_replace(str, i, replace, len_var);
	ft_strdel(&replace);
}

void		ft_replacment(char **str, t_vector **env)
{
	int		i;

	i = 0;
	while ((*str)[i])
	{
		if ((*str)[i] == '~'
			|| ((*str)[i] == '$' && (*str)[i + 1]
				&& (ft_check((*str)[i + 1]))))
		{
			ft_variab(str, env, i, (*str)[i]);
		}
		++i;
	}
}
