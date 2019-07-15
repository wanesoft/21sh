/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helen_and_friends.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 20:57:37 by udraugr-          #+#    #+#             */
/*   Updated: 2019/07/15 20:57:42 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/twenty_one_sh.h"

void			ft_check_n(void)
{
	char		buf[1024];
	int			i;
	int			pos;

	i = 0;
	ft_bzero(buf, 1024);
	ft_putstr_fd("\033[6n", 1);
	read(0, &buf, 1024);
	while (buf[i] != ';' && buf[i])
		++i;
	++i;
	pos = ft_atoi(&buf[i]);
	if (pos > 1) {
		ft_putstr_fd("\033[31;1;7m%\033[0m\n", 1);
	}
}
