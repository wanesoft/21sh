/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_i_arrow_l_r.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 15:03:29 by udraugr-          #+#    #+#             */
/*   Updated: 2019/07/04 15:03:32 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/twenty_one_sh.h"

void			ft_i_arrow_l_r(unsigned i, t_mygv *mygv)
{
	ft_foo_2(mygv);
	if (i == K_RIGHT && mygv->g_j < ft_strlen(mygv->g_str))
	{
		++mygv->g_x_pos;
		++mygv->g_j;
	}
	else if (i == K_LEFT && mygv->g_j > 0)
	{
		--mygv->g_x_pos;
		--mygv->g_j;
	}
}
