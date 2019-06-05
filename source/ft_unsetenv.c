/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 14:43:44 by udraugr-          #+#    #+#             */
/*   Updated: 2019/06/02 15:58:33 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_unsetenv(char *param, t_vector **env)
{
	t_vector	*tmp;

	tmp = *env;
	while (*param &&
			(*param == ' ' || *param == '\t' || *param == '\n'))
		++param;
	if (!*param)
		return ;
	while (tmp)
	{
		if (ft_strequ(((t_var_env *)tmp->content)->key, param))
		{
			ft_del_content_var_env(tmp->content);
			ft_del_vector(&tmp);
			break ;
		}
		tmp = tmp->next;
	}
}
