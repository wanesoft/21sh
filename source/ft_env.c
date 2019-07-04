/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 11:55:35 by udraugr-          #+#    #+#             */
/*   Updated: 2019/07/04 15:38:56 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/twenty_one_sh.h"

static void		ft_sort_and_print_arr(char **arr)
{
	int			i;
	int			j;

	if (!arr || !(*arr))
		return ;
	i = 0;
	while (arr[i])
	{
		j = i + 1;
		while (arr[j])
		{
			if (ft_strcmp(arr[i], arr[j]) > 0)
				ft_swap_str(&arr[i], &arr[j]);
			++j;
		}
		++i;
	}
	i = 0;
	while (arr[i])
	{
		write(1, arr[i], ft_strlen(arr[i]));
		write(1, "\n", 1);
		++i;
	}
}

void			ft_env(t_vector **env, char *str)
{
	t_vector	*tmp;
	char		**arr;
	char		**arr_tmp;

	arr_tmp = ft_strplit(str, ' ');
	if (arr_tmp[0] && ft_strequ(arr_tmp[0], "-s"))
	{
		arr = ft_vector_to_arr(env);
		ft_sort_and_print_arr(arr);
		ft_del_arr(&arr);
	}
	else
	{
		tmp = *env;
		while (tmp)
		{
			write(1,
					((t_var_env *)tmp->content)->full_line,
					ft_strlen(((t_var_env *)tmp->content)->full_line));
			write(1, "\n", 1);
			tmp = tmp->next;
		}
	}
	ft_del_arr(&arr_tmp);
}
