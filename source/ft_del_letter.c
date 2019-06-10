/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_letter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 16:57:43 by udraugr-          #+#    #+#             */
/*   Updated: 2019/06/10 16:57:45 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/twenty_one_sh.h"

void			ft_del_letter(unsigned i, t_mygv *mygv)
{
	if (i == K_DEL)
	{
		return;
	}
	else if (i == K_BACKSP && mygv->g_j > 0)
	{
		--mygv->g_j;
		mygv->g_str[mygv->g_j] = '\0';
	}
}
