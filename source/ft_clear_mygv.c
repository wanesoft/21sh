/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_mygv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 13:56:43 by udraugr-          #+#    #+#             */
/*   Updated: 2019/06/10 14:36:07 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/twenty_one_sh.h"

void			ft_clear_mygv(t_mygv *mygv)
{
	ft_bzero(mygv->g_str, BUF_G_STR);
	mygv->g_j = 0;
	mygv->g_stage = 0;
	mygv->g_y_pos = 0;
	mygv->g_c_his = 0;
	ft_del_stack(&mygv->grab);
	mygv->grab = NULL;
	mygv->cur_her = 0;
	mygv->g_kos = 0;
}
