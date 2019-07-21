/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_back_screen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 14:01:55 by udraugr-          #+#    #+#             */
/*   Updated: 2019/07/20 12:32:13 by draynor          ###   ########.fr       */
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
		ft_putstr_fd(tgetstr("up", NULL), STDOUT_FILENO);
		ft_putstr_fd(tgetstr("dl", NULL), STDOUT_FILENO);
		ft_putstr_fd(tgetstr("cr", NULL), STDOUT_FILENO);
		--j;
	}
}

void				ft_back_screen(int signo)
{
	t_mygv			*mygv;

	mygv = ft_get_mygv(NULL);
	ft_del_stack(&mygv->grab);
	ft_strdel(&mygv->target);
	tcsetattr(STDIN_FILENO, TCSANOW, &mygv->old);
	ft_putstr_fd(tgetstr("ve", NULL), STDIN_FILENO);
	ft_putstr_fd("\033[0m", STDIN_FILENO);
	close(mygv->g_fd_w);
	if (signo != SIGTSTP)
		free(mygv);
	if (signo == SIGTSTP)
	{
		signal(SIGTSTP, SIG_DFL);
		ioctl(STDERR_FILENO, TIOCSTI, "\x1A");
	}
}
