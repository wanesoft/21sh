/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_letter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:03:36 by udraugr-          #+#    #+#             */
/*   Updated: 2019/06/10 14:39:30 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/twenty_one_sh.h"

void		ft_put_letter(unsigned i, t_mygv *mygv)
{
	ft_memmove(&mygv->g_str[mygv->g_j + 1], &mygv->g_str[mygv->g_j], ft_strlen(&mygv->g_str[mygv->g_j]));
	mygv->g_str[mygv->g_j] = (char)i;
	++mygv->g_j;
	++mygv->g_x_pos;
}
