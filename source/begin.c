/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 14:01:32 by udraugr-          #+#    #+#             */
/*   Updated: 2019/06/18 13:38:50 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/twenty_one_sh.h"

t_vector		**g_env;

void			ft_hello(void)
{
	write(1, "\033[32mMishinshell:\033[0m ", 22);
}

void			ft_restart(int sign)
{
	write(1, "\n", 1);
	//ft_hello();
	ft_init_screen();
	//ft_clear_mygv(ft_get_mygv(NULL));
	if (sign == SIGINT)
	{
		ft_init_screen();
		//ft_clear_mygv(ft_get_mygv(NULL));
		ft_prompt_line(ft_get_mygv(NULL));
		signal(SIGINT, ft_restart);
	}
}

void			begin(t_vector **env)
{
	char		*str;
	char		*tmp;
	char		**arr_str;
	int			i;

	signal(SIGINT, ft_restart);
	g_env = env;
	//str = ft_input();
	
	/* *** TEST *** */
	static int p = 0;
	str = ft_strdup("cd ;cd ;");
	ft_printf("%d\n", p);
	++p;
	/* *** TEST *** */
	
	arr_str = ft_strsplit(str, ';');
	i = 0;
	while (arr_str[i])
	{
		tmp = ft_strjoin("_=", arr_str[i]);
		ft_setenv(tmp, env);
		ft_strdel(&tmp);
		ft_prossesing(&arr_str[i], env);
		++i;
	}
	ft_strdel(&str);
	ft_clear_mygv(ft_get_mygv(NULL));
	ft_del_arr(&arr_str);
}
