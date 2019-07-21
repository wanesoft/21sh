/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_i_arrow_l_r.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 15:03:29 by udraugr-          #+#    #+#             */
/*   Updated: 2019/07/19 22:11:50 by draynor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/twenty_one_sh.h"

static void		ft_go_left(t_mygv *mygv)
{
	if (mygv->g_j && mygv->g_str[mygv->g_j] != ' ' &&
			mygv->g_str[mygv->g_j - 1] == ' ')
		--mygv->g_j;
	if (mygv->g_j && mygv->g_str[mygv->g_j] != '\n' &&
			mygv->g_str[mygv->g_j - 1] == '\n')
		--mygv->g_j;
	while (mygv->g_j && (mygv->g_str[mygv->g_j] == ' ' ||
				mygv->g_str[mygv->g_j] == '\n'))
		--mygv->g_j;
	while (mygv->g_j && mygv->g_str[mygv->g_j] != ' ' &&
			mygv->g_str[mygv->g_j] != '\n')
		--mygv->g_j;
	if (mygv->g_j)
		++mygv->g_j;
}

static void		ft_go_right(t_mygv *mygv)
{
	if (!mygv->g_j && mygv->g_str[mygv->g_j + 1])
		++mygv->g_j;
	while (mygv->g_str[mygv->g_j] && (mygv->g_str[mygv->g_j] == ' ' ||
				mygv->g_str[mygv->g_j] == '\n'))
		++mygv->g_j;
	while (mygv->g_str[mygv->g_j] && mygv->g_str[mygv->g_j] != ' ' &&
			mygv->g_str[mygv->g_j] != '\n')
		++mygv->g_j;
}

void			ft_i_arrow_l_r(unsigned i, t_mygv *mygv)
{
	ft_foo_2(mygv);
	if (i == K_RIGHT && mygv->g_j < (int)ft_strlen(mygv->g_str))
	{
		++mygv->g_j;
	}
	else if (i == K_LEFT && mygv->g_j > 0)
	{
		--mygv->g_j;
	}
	else if (i == K_OPT_L)
		ft_go_left(mygv);
	else if (i == K_OPT_R)
		ft_go_right(mygv);
}
