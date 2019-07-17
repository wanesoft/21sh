/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 13:57:40 by udraugr-          #+#    #+#             */
/*   Updated: 2019/07/04 14:17:58 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/twenty_one_sh.h"

void		ft_echo(char *params)
{
	char	**tmp;
	int		i;

	tmp = ft_strsplit(params, ' ');
//	tmp = ft_ungrab(params, 0);
	ft_ungrab_arr(tmp);
	i = 0;
	while (tmp[++i])
		write(1, tmp[i], ft_strlen(tmp[i]));
	write(1, "\n", 1);
	ft_del_arr(&tmp);
	return ;
}
