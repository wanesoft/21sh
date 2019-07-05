/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 14:43:44 by udraugr-          #+#    #+#             */
/*   Updated: 2019/07/05 17:23:40 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/twenty_one_sh.h"

void	ft_unsetenv(char *param, t_vector **env)
{
	t_vector	*tmp;
	char		**arr;

	tmp = *env;
	arr = ft_strsplit(param, ' ');
	ft_ungrab_arr(arr);
	if (!arr[0])
		return ;
	while (tmp)
	{
		if (ft_strequ(((t_var_env *)tmp->content)->key, arr[0]))
		{
			if (*env == tmp)
				*env = (*env)->next;
			ft_del_content_var_env(tmp->content);
			ft_del_vector(&tmp);
			break ;
		}
		tmp = tmp->next;
	}
	ft_del_arr(&arr);
}
