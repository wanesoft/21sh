/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_work_equ.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draynor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 22:18:06 by draynor           #+#    #+#             */
/*   Updated: 2019/07/19 22:23:48 by draynor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/twenty_one_sh.h"

int				ft_size_equ(char *str, char **arr, int len)
{
	int			i;
	int			count;

	i = 0;
	count = 0;
	while (arr && arr[i])
	{
		if (ft_strnequ(str, arr[i], len))
			++count;
		++i;
	}
	return (count);
}

void			ft_put_equ(char ***equ, char *str, char **arr, int len)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (arr && arr[i])
	{
		if (ft_strnequ(str, arr[i], len))
		{
			(*equ)[j] = ft_strdup(arr[i]);
			++j;
		}
		++i;
	}
}

void			ft_print_equ(char **equ, int stage)
{
	ft_printf("\n");
	while (*equ)
	{
		ft_printf("%s ", *equ);
		++equ;
	}
	while (stage)
	{
		ft_printf("\n");
		--stage;
	}
	ft_printf("\n");
}
