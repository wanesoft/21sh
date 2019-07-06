/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_screen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 13:59:46 by udraugr-          #+#    #+#             */
/*   Updated: 2019/07/04 15:06:37 by udraugr-         ###   ########.fr       */
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

static void				ft_init_history_2(t_mygv *mygv, char *str)
{
	char				**arr;

	arr = ft_strsplit(str, ':');
	if (arr && arr[0])
		mygv->g_n_his = ft_atoi(arr[0]);
	else
		mygv->g_n_his = 0;
	ft_del_arr(&arr);
}

static void				ft_init_history(t_mygv *mygv)
{
	char				*tmp2;
	char				*tmp3;

	tmp2 = 0;
	tmp3 = (char *)malloc(sizeof(char) * BUF_G_STR);
	mygv->g_fd_w = open("/goinfre/.21sh", O_WRONLY | O_APPEND | O_CREAT, S_IRWXU);
	mygv->g_fd_r = open("/goinfre/.21sh", O_RDONLY | O_CREAT, S_IRWXU);
	if (mygv->g_fd_w < 0 || mygv->g_fd_r < 0)
	{
		ft_printf("Error open/create %s\n", "/goinfre/.21sh");
		exit(EXIT_FAILURE);
	}
	while (ft_gnl_pro(mygv->g_fd_r, &tmp2, '\t') > 0)
	{
		ft_memcpy(tmp3, tmp2, ft_strlen(tmp2));
		ft_strdel(&tmp2);
	}
	ft_init_history_2(mygv, tmp3);
	close(mygv->g_fd_r);
	ft_strdel(&tmp2);
	free(tmp3);
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
		exit(EXIT_FAILURE);
	}
	ft_putstr_fd(tgetstr("vi", NULL), STDIN_FILENO);
	ft_init_history(mygv);
}
