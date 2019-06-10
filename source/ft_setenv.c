/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 17:25:16 by udraugr-          #+#    #+#             */
/*   Updated: 2019/06/10 14:06:25 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/21sh.h"

void		ft_setenv(char *param, t_vector **env)
{
	t_vector	*tmp;
	t_var_env	*new;
	int			fl;

	tmp = *env;
	fl = 0;
	while (*param &&
			(*param == ' ' || *param == '\t' || *param == '\n'))
		++param;
	if (!*param)
		return ;
	new = ft_take_info(param);
	while (tmp)
	{
		if (tmp->content && ft_strequ(((t_var_env *)tmp->content)->key, new->key))
		{
			fl = 1;
			ft_del_content_var_env(tmp->content);
			free(tmp->content);
			tmp->content = new;
			break ;
		}
		tmp = tmp->next;
	}
	if (!fl)
		ft_add_vector(*env, new);
}
