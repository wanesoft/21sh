/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_letter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 16:57:43 by udraugr-          #+#    #+#             */
/*   Updated: 2019/07/04 14:10:50 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/twenty_one_sh.h"

void			ft_del_letter(unsigned i, t_mygv *mygv)
{
	ft_foo_2(mygv);
	if (i == K_DEL)
	{
		return ;
	}
	else if (i == K_BACKSP && mygv->g_j > 0)
	{
		--mygv->g_j;
		if (mygv->g_str[mygv->g_j] == '\n')
		{
			ft_putstr_fd(tgetstr("up", NULL), STDOUT_FILENO);
			ft_putstr_fd(tgetstr("dl", NULL), STDOUT_FILENO);
			ft_putstr_fd(tgetstr("cr", NULL), STDOUT_FILENO);
			--mygv->g_stage;
		}
		ft_memmove(&mygv->g_str[mygv->g_j],
					&mygv->g_str[mygv->g_j + 1],
					ft_strlen(&mygv->g_str[mygv->g_j]));
	}
}
