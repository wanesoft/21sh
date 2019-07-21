/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 13:57:40 by udraugr-          #+#    #+#             */
/*   Updated: 2019/07/19 22:15:34 by draynor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/twenty_one_sh.h"

void		ft_echo(char *params)
{
	char	**tmp;
	int		i;

	tmp = ft_strsplit(params, ' ');
	ft_ungrab_arr(tmp);
	i = 0;
	while (tmp[++i])
	{
		write(1, tmp[i], ft_strlen(tmp[i]));
		if (tmp[i + 1])
			write(1, " ", 1);
	}
	write(1, "\n", 1);
	ft_del_arr(&tmp);
	return ;
}
