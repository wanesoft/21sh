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
	write(1, "CTRL+C\n", 7);
	if (sign == SIGINT)
	{
		ft_clear_mygv(ft_get_mygv(NULL));
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
	char		*tmp;
	char		**arr_str;
	int			i;
	int			j;
	t_mygv		*mygv;

	mygv = ft_get_mygv(NULL);
	signal(SIGINT, ft_restart);
	signal(SIGTSTP, ft_restart);
	ft_input();
	ft_put_history(mygv);
	
	/* *** */
	
//	ft_printf("VOT ITOG --> %s\n", mygv->g_str);
	
	/* *** */
	
	arr_str = ft_strsplit(mygv->g_str, ';');
	i = 0;
	j = ft_arrlen(arr_str);
	while (i < j)
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
	ft_del_arr(&arr_str);
	ft_clear_mygv(ft_get_mygv(NULL));
}
