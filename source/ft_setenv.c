/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 17:25:16 by udraugr-          #+#    #+#             */
/*   Updated: 2019/07/04 15:37:24 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/twenty_one_sh.h"

void		ft_setenv(char *param, t_vector **env)
{
	t_vector	*tmp;
	t_var_env	*new;
	char		**arr;

	tmp = *env;
	ft_strsplit(param, ' ');
	if (!arr[0])
		return ;
	new = ft_take_info(arr[0]);
	while (tmp)
	{
		if (tmp->content &&
				ft_strequ(((t_var_env *)tmp->content)->key, new->key))
		{
			ft_del_content_var_env(tmp->content);
			free(tmp->content);
			tmp->content = new;
			break ;
		}
		tmp = tmp->next;
	}
	if (!tmp)
		*env = ft_add_vector(*env, new);
	ft_del_arr(&arr);
}
