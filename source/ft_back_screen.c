/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_back_screen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 14:01:55 by udraugr-          #+#    #+#             */
/*   Updated: 2019/07/04 14:02:19 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/twenty_one_sh.h"

void				ft_foo_2(t_mygv *mygv)
{
	int				ii;
	int				j;

	ii = 0;
	j = 0;
	while (mygv->g_str[ii])
	{
		if (mygv->g_str[ii] == '\n')
			++j;
		++ii;
	}
	mygv->g_stage = j;
	mygv->g_stage += mygv->g_kos;
}

void				ft_foo_3(t_mygv *mygv)
{
	int			ii;
	int			j;

	ii = 0;
	j = 0;
	while (mygv->g_str[ii])
	{
		if (mygv->g_str[ii] == '\n')
			++j;
		++ii;
	}
	while (j)
	{
//		ft_putstr_fd(tgetstr("up", NULL), STDOUT_FILENO);
		ft_putstr_fd(tgetstr("dl", NULL), STDOUT_FILENO);
		ft_putstr_fd(tgetstr("cr", NULL), STDOUT_FILENO);
		--j;
	}
}

void				ft_back_screen(void)
{
	t_mygv			*mygv;

	mygv = ft_get_mygv(NULL);
	tcsetattr(STDIN_FILENO, TCSANOW, &mygv->old);
	ft_putstr_fd(tgetstr("ve", NULL), STDIN_FILENO);
	ft_putstr_fd("\033[0m", STDIN_FILENO);
	close(mygv->g_fd_w); //zakryl!
}
