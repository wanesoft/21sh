/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_take_value_env.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 15:04:29 by udraugr-          #+#    #+#             */
/*   Updated: 2019/06/02 15:27:11 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char			*ft_take_value_env(char *key, t_vector **env)
{
	t_vector	*tmp;
	char		*value;

	tmp = *env;
	value = 0;
	while (tmp)
	{
		if (ft_strequ(key, ((t_var_env *)tmp->content)->key))
		{
			value = ft_strdup(((t_var_env *)tmp->content)->value);
			break ;
		}
		tmp = tmp->next;
	}
	if (!value)
		value = ft_memalloc(1);
	return (value);
}
