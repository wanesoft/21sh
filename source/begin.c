/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 14:01:32 by udraugr-          #+#    #+#             */
/*   Updated: 2019/06/20 19:40:01 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/twenty_one_sh.h"

t_vector		**g_env;

void			ft_restart(int sign)
{
	write(1, "\n", 1);
	ft_init_screen();
	//ft_clear_mygv(ft_get_mygv(NULL));
	if (sign == SIGINT)
	{
		ft_init_screen();
		//ft_clear_mygv(ft_get_mygv(NULL));
		ft_prompt_line(ft_get_mygv(NULL));
		signal(SIGINT, ft_restart);
	}
	if (sign == SIGTSTP)
	{
		exit(EXIT_SUCCESS);
	}
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

void			begin(t_vector **env)
{
	char		*str;
	char		*tmp;
	char		**arr_str;
	int			i;
	t_mygv		*mygv;

	mygv = ft_get_mygv(NULL);
	signal(SIGINT, ft_restart);
	g_env = env;
	ft_input();
	ft_put_history(mygv);
	
	/* *** TEST *** */
	signal(SIGTSTP, ft_restart);
	static int p = 0;
	//str = ft_strdup("cd; cd; cd -; cd ~; cd /; pwd");
	//str = ft_strdup("cd| cd| cd -| cd ~| cd /| pwd");
	//str = ft_strdup("cd; cd; cd -; cd ~; cd /;    pwd;  ls;  env   ;");
	//str = ft_strdup("cd /;pwd;env;ls;cd -;pwd;env;ls;");
	ft_printf("%d\n", p);
	++p;
	//arr_str = ft_strsplit(str, ';');
	/* *** TEST *** */
	
	arr_str = ft_strsplit(mygv->g_str, ';');
	i = 0;
	while (arr_str[i])
	{
		tmp = ft_strjoin("_=", arr_str[i]);
		ft_setenv(tmp, env);
		ft_strdel(&tmp);
		tmp = arr_str[i];
		arr_str[i] = ft_strtrim(arr_str[i]);
		ft_strdel(&tmp);
		ft_prossesing(&arr_str[i], env);
		++i;
	}
	//ft_strdel(&str);
	ft_del_arr(&arr_str);
	ft_clear_mygv(ft_get_mygv(NULL));
}
