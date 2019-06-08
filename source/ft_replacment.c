 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replacment.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 16:08:49 by udraugr-          #+#    #+#             */
/*   Updated: 2019/06/02 15:28:42 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

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
	int		j;
	int		z;

	if (!(tmp = ft_memalloc(ft_strlen(*str) - len_var +
					ft_strlen(replace) + 2)))
		return ;
//	tmp = (char *)malloc(2048); //allo
//	bzero(tmp, 2048);
	j = -1;
	z = -1;
    ft_strncpy(tmp, *str, i);
    ft_strcpy(&tmp[i], replace);
    ft_strcpy(&tmp[i + ft_strlen(replace)], &(*str)[i + len_var]);
    /*while (j < i)
		tmp[++j] = (*str)[++z];
	z += len_var;
	while (*replace)
		tmp[j++] = *(replace++);
	while ((*str)[z])
		tmp[j++] = (*str)[z++];*/
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
		//ft_printf("\n{______%s________}\n", &(*str)[i]);
		while (ft_check((*str)[i + j]))
		{
			//ft_printf("\n{________%s________}\n", &(*str)[i + j]);
			++j;
		}
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
	char *tmp;
	
	i = 0;
	tmp = ft_strdup(*str);
//	while (tmp[i])
//	{
//		if ((*str)[i] == '~'
//			|| ((*str)[i] == '$' && (*str)[i + 1]
//				&& (ft_check((*str)[i + 1]))))
//		{
//			ft_variab(str, env, i, (*str)[i]);
//			--i;
//		}
//		++i;
//	}
	while (tmp[i])
	{
		if ((tmp)[i] == '~'
			|| ((tmp)[i] == '$' && (tmp)[i + 1]
				&& (ft_check((tmp)[i + 1]))))
		{
			ft_variab(str, env, i, (tmp)[i]);
			//--i;
		}
		++i;
	}
	free(tmp);
}
