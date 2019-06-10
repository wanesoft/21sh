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
	if (ft_strlen(params) > 4)
		write(1, params + 5, ft_strlen(params + 5));
	write(1, "\n", 1);
	return ;
}
