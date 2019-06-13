/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_screen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 13:59:46 by udraugr-          #+#    #+#             */
/*   Updated: 2019/06/10 14:37:43 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/twenty_one_sh.h"

void					ft_get_tty_col_ros(void)
{
	struct winsize		w;
	t_mygv				*mygv;
	
	mygv = ft_get_mygv(NULL);
	ioctl(STDERR_FILENO, TIOCGWINSZ, &w);
	if (w.ws_col == 0 || w.ws_row == 0)
	{
		mygv->col = 64;
		mygv->row = 64;
	}
	else
	{
		mygv->col = w.ws_col;
		mygv->row = w.ws_row;
	}
}

void					ft_init_screen(void)
{
	struct termios		new;
	t_mygv				*mygv;
	
	mygv = ft_get_mygv(NULL);
	tcgetattr(STDIN_FILENO, &new);
	new.c_lflag &= ~(ICANON);
	new.c_lflag &= ~(ECHO);
	new.c_cc[VMIN] = 1;
	new.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSADRAIN, &new);
	if (tgetent(NULL, getenv("TERM")) <= 0)
	{
		ft_printf("Error load TERMCAP\n");
		ft_bye(&(mygv->env));
		exit(0);
	}
	ft_putstr_fd(tgetstr("vi", NULL), STDIN_FILENO);
}
