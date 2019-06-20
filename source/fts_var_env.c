/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_var_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 13:27:43 by udraugr-          #+#    #+#             */
/*   Updated: 2019/06/10 14:40:24 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/twenty_one_sh.h"

t_var_env		*ft_take_info(char *str)
{
	t_var_env	*tmp;
	char		**arr;

	if (!str || !(tmp = (t_var_env *)malloc(sizeof(t_var_env))))
		return (0);
	tmp->full_line = 0;
	tmp->key = 0;
	tmp->value = 0;
	tmp->full_line = ft_strdup(str);
	arr = ft_strsplit(str, '=');
	tmp->key = ft_strdup(arr[0]);
	if (arr[1])
		tmp->value = ft_strdup(arr[1]);
	else
		tmp->value = ft_strdup("\0");
	ft_del_arr(&arr);
	return (tmp);
}

void			ft_del_content_var_env(t_var_env *cur)
{
	if (!cur)
		return ;
	ft_strdel(&cur->key);
	ft_strdel(&cur->value);
	ft_strdel(&cur->full_line);
}
