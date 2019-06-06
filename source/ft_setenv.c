/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 17:25:16 by udraugr-          #+#    #+#             */
/*   Updated: 2019/06/05 15:16:15 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void		ft_setenv(char *param, t_vector **env)
{
	t_vector	*tmp;
	t_var_env	*new;

	tmp = *env;
	while (*param &&
			(*param == ' ' || *param == '\t' || *param == '\n'))
		++param;
	if (!*param)
		return ;
	new = ft_take_info(param);
	while (tmp)
	{
		//ft_strlen(((t_var_env *)tmp->content)->key);
		//ft_printf("%s %s\n", (char *)((t_var_env *)tmp->content)->key, (char *)new->key); // EDIT!!! DELETE!!!
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
		ft_add_vector(*env, new);
}
