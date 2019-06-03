/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 11:55:35 by udraugr-          #+#    #+#             */
/*   Updated: 2019/06/02 16:23:52 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void		ft_sort_and_print_arr(char **arr)
{
	int			i;
	int			j;
	char		*tmp;

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

	while (*str &&
			(*str == ' ' || *str == '\t' || *str == '\n'))
		++str;
	if (ft_strequ(str, "-s"))
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
}
