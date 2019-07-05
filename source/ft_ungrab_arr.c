/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ungrab_arr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 16:23:32 by udraugr-          #+#    #+#             */
/*   Updated: 2019/07/05 16:24:28 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/twenty_one_sh.h"

void			ft_ungrab_arr(char **param)
{
	int			i;
	char		*back;

	i = -1;
	while (param[++i])
	{
		back = param[i];
		param[i] = ft_ungrab(param[i], 0);
		ft_strdel(&back);
	}
}
