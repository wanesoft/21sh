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
		write(1, "CTRL+Z\n", 7);
		ft_back_screen(sign);
		signal(SIGTSTP, SIG_DFL);
		exit(EXIT_FAILURE);
		ioctl(STDERR_FILENO, TIOCSTI, "\x1A");
	}
	if (sign == SIGCONT)
	{
		ft_init_screen();
		ft_prompt_line(ft_get_mygv(NULL));
		signal(SIGCONT, ft_restart);
	}
	if (sign == SIGABRT || sign == SIGSTOP || sign == SIGKILL || sign == SIGQUIT)
		ft_back_screen(0);
}

static void		ft_put_history(t_mygv *mygv)
{
	char		*tmp;

	if (mygv->g_str[0] == '\0')
		return ;
	if (mygv->g_n_his == 0)
	{
		tmp = ft_itoa(mygv->g_n_his);
		write(mygv->g_fd_w, tmp, ft_strlen(tmp));
		write(mygv->g_fd_w, ":", 1);
		ft_strdel(&tmp);
	}
	write(mygv->g_fd_w, mygv->g_str, ft_strlen(mygv->g_str));
	write(mygv->g_fd_w, "\t", 1);
	++mygv->g_n_his;
	tmp = ft_itoa(mygv->g_n_his);
	write(mygv->g_fd_w, tmp, ft_strlen(tmp));
	write(mygv->g_fd_w, ":", 1);
	ft_strdel(&tmp);
}

static void ft_handle_signal(void)
{
	signal(SIGINT, ft_restart);
	signal(SIGTSTP, ft_restart);
	signal(SIGCONT, ft_restart);
	signal(SIGWINCH, ft_restart);
	signal(SIGABRT, ft_restart);
	signal(SIGSTOP, ft_restart);
	signal(SIGKILL, ft_restart);
	signal(SIGQUIT, ft_restart);
}

static void		ft_pre_begin(char **arr_str, t_vector **env, int i)
{
	char		*tmp;
	t_mygv		*mygv;
	
	mygv = ft_get_mygv(NULL);
	tmp = ft_strjoin("_=", arr_str[i]);
	ft_setenv(tmp, env);
	ft_strdel(&tmp);
	tmp = arr_str[i];
	arr_str[i] = ft_strtrim(arr_str[i]);
	ft_strdel(&tmp);
	ft_prossesing(&arr_str[i], env);
	ft_clear_mygv(mygv);
	ft_init_screen();
	ft_check_n();
}

void			begin(t_vector **env)
{
	char		**arr_str;
	int			i;
	t_mygv		*mygv;
	char		*tmp;

	mygv = ft_get_mygv(NULL);
	ft_handle_signal();
	ft_input();
	ft_put_history(mygv);
	arr_str = ft_strsplit(mygv->g_str, ';');
	i = 0;
	while (i < ft_arrlen(arr_str))
	{
		tmp = arr_str[i];
		arr_str[i] = ft_strtrim(arr_str[i]);
		ft_strdel(&tmp);
		if (ft_strequ(arr_str[i], "exit"))
		{
			ft_del_arr(&arr_str);
			ft_bye(env);
		}
		char **name = ft_vector_to_arr(env);
		ft_forward(arr_str[i], name);
		ft_pre_begin(arr_str, env, i);
		++i;
	}
	ft_clear_mygv(mygv);
	ft_init_screen();
	ft_del_arr(&arr_str);
}
