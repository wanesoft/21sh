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
	char		**tmp2;
//	int			i;

	if (!str || !(tmp = (t_var_env *)malloc(sizeof(t_var_env))))
		return (0);
	tmp->full_line = ft_strdup(str);
	tmp2 = ft_strsplit(str, '=');
	/*i = 0;
	while (str[i] && str[i] != '=')
		++i;
	tmp->key = ft_strndup(str, i);
	if (str[i] && str[i + 1])
		tmp->value = ft_strdup(&str[i + 1]);
	else
		tmp->value = ft_strdup("\0");
	++i;*/
	tmp->key = ft_strdup(tmp2[0]);
	if (tmp2[1])
		tmp->value = ft_strdup(tmp2[1]);
	else
		tmp->value = ft_strdup("\0");
	ft_del_arr(&tmp2);
	return (tmp);
}

void			ft_del_content_var_env(t_var_env *cur)
{
	if (!cur)
		return ;
	free(cur->key);
	cur->key = 0;
	free(cur->value);
	cur->value = 0;
	free(cur->full_line);
	cur->full_line = 0;
}
