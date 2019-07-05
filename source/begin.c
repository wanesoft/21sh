/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 14:01:32 by udraugr-          #+#    #+#             */
/*   Updated: 2019/07/05 15:17:59 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/twenty_one_sh.h"

void			ft_restart(int sign)
{
	if (sign == SIGINT)
	{
		write(1, "CTRL+C\n", 7);
		ft_clear_mygv(ft_get_mygv(NULL));
		ft_prompt_line(ft_get_mygv(NULL));
		signal(SIGINT, ft_restart);
	}
	if (sign == SIGTSTP)
	{
		write(1, "CTRL+D\n", 7);
		ft_clear_mygv(ft_get_mygv(NULL));
		ft_prompt_line(ft_get_mygv(NULL));
		signal(SIGINT, ft_restart);
	}
	if (sign == SIGABRT || sign == SIGSTOP || sign == SIGKILL || sign == SIGQUIT)
		ft_back_screen();
}

static void		ft_put_history(t_mygv *mygv)
{
	if (mygv->g_str[0] == '\0')
		return;
	if (mygv->g_n_his == 0)
	{
		write(mygv->g_fd_w, ft_itoa(mygv->g_n_his), ft_strlen(ft_itoa(mygv->g_n_his)));
		write(mygv->g_fd_w, ":", 1);
	}
	write(mygv->g_fd_w, mygv->g_str, ft_strlen(mygv->g_str));
	write(mygv->g_fd_w, "\t", 1);
	++mygv->g_n_his;
	write(mygv->g_fd_w, ft_itoa(mygv->g_n_his), ft_strlen(ft_itoa(mygv->g_n_his)));
	write(mygv->g_fd_w, ":", 1);
}

static void ft_handle_signal(void)
{
	signal(SIGINT, ft_restart);
	signal(SIGTSTP, ft_restart);
	signal(SIGTSTP, ft_restart);
	signal(SIGCONT, ft_restart);
	signal(SIGWINCH, ft_restart);
	signal(SIGABRT, ft_restart);
	signal(SIGSTOP, ft_restart);
	signal(SIGKILL, ft_restart);
	signal(SIGQUIT, ft_restart);
}

static void ft_check_n(void)
{
	char buf[1024];
	ft_bzero(buf, 1024);
	ft_putstr_fd("\033[6n", 1);
	read(0, &buf, 1024);
	int i;
	for (i = 0; buf[i] != ';' && buf[i]; ++i) {}
	++i;
	int pos = ft_atoi(&buf[i]);
	if (pos > 1) {
		ft_putstr_fd("\033[31;1;7m%\033[0m\n", 1);
	}
}

void			begin(t_vector **env)
{
	char		*tmp;
	char		**arr_str;
	int			i;
	t_mygv		*mygv;

	mygv = ft_get_mygv(NULL);
	ft_handle_signal();
	ft_input();
	ft_put_history(mygv);
	arr_str = ft_strsplit(mygv->g_str, ';');
	i = 0;
	while (i < ft_arrlen(arr_str))
	{
		tmp = ft_strjoin("_=", arr_str[i]);
		ft_setenv(tmp, env);
		ft_strdel(&tmp);
		tmp = arr_str[i];
		arr_str[i] = ft_strtrim(arr_str[i]);
		ft_strdel(&tmp);
		ft_prossesing(&arr_str[i], env);
		ft_check_n();
		++i;
	}
	ft_del_arr(&arr_str);
}
