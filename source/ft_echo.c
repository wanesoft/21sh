/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 13:57:40 by udraugr-          #+#    #+#             */
/*   Updated: 2019/06/10 14:36:26 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/twenty_one_sh.h"

void		ft_echo(char *params)
{
    char    *tmp;
    
    tmp = ft_ungrab(params, 0);
	if (ft_strlen(tmp) > 4)
		write(1, tmp + 5, ft_strlen(tmp + 5));
	write(1, "\n", 1);
    ft_strdel(&tmp);
	return ;
}
