/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_mygv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 13:59:17 by udraugr-          #+#    #+#             */
/*   Updated: 2019/07/04 14:59:33 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/twenty_one_sh.h"

t_mygv					*ft_get_mygv(t_mygv *mygv)
{
	static t_mygv		*mygv_here;

	if (mygv == NULL)
		return (mygv_here);
	else
		mygv_here = mygv;
	return (0);
}
