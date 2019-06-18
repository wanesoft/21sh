/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vect_to_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 15:07:44 by udraugr-          #+#    #+#             */
/*   Updated: 2019/06/18 12:29:41 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/twenty_one_sh.h"

char			**ft_vector_to_arr(t_vector **env)
{
	char		**arr_env;
	t_vector	*tmp;
	int			i;

	if (!(arr_env = (char **)malloc(sizeof(char *) *
					(ft_count_vector(*env) + 1))))
		return (0);
	tmp = *env;
	i = 0;
	while (tmp)
	{
		arr_env[i] = ft_strdup(((t_var_env *)tmp->content)->full_line);
		tmp = tmp->next;
		++i;
	}
	arr_env[i] = 0;
	return (arr_env);
}
