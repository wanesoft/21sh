/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 11:23:54 by udraugr-          #+#    #+#             */
/*   Updated: 2019/06/10 14:40:32 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/twenty_one_sh.h"

static t_vector		*ft_arr_to_vector(char **env)
{
	t_vector		*begin;

	if (!env || !*env)
		return (0);
	begin = 0;
	while (*env)
	{
		begin = ft_add_vector(begin, ft_take_info(*env));
		++env;
	}
	return (begin);
}

int					main(int argc, char **argv, char **env)
{
	t_vector		*env_copy;
	t_mygv			*mygv;

	++argc;
	++argv;
	write(1, "\033[31m___________________________\n", 34);
	write(1, "Welcome to mishinshell!\n", 24);
	write(1, "for help, enter --help\n\033[0m", 27);
	env_copy = ft_arr_to_vector(env);
	if (!(mygv = (t_mygv *)malloc(sizeof(t_mygv))))
		exit(EXIT_FAILURE);
	tcgetattr(STDIN_FILENO, &(mygv->old));
	ft_clear_mygv(mygv);
	ft_get_mygv(mygv);
	ft_init_screen();
	while (1)
	{
		mygv->env = env_copy;
		begin(&env_copy);
		
		//char cmd[]="\033[6n";
		char buf[1024];
		ft_bzero(buf, 1024);
		//write(1, cmd, ft_strlen(cmd));
		ft_putstr_fd("\033[6n", 1);
		read(0, &buf, 1024);
//		ft_printf("%d\n", res);
		int i;
		for (i = 0; buf[i] != ';' && buf[i]; ++i) {}
		++i;
		int pos = ft_atoi(&buf[i]);
//		ft_printf("pos is %d\n", pos);
		if (pos > 1) {
			ft_putstr_fd("\033[31m %\033[0m\n", 1);
		}
	}
	return (0);
}
