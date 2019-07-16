/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 11:23:54 by udraugr-          #+#    #+#             */
/*   Updated: 2019/07/07 10:05:40 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/twenty_one_sh.h"

t_vector			*ft_arr_to_vector(char **env)
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

	remove("/goinfre/.21sh"); // ALLOOOOOOOOOO
	
	++argc;
	++argv;
	write(1, "\033[31m___________________________\n", 34);
	write(1, "Welcome to mishinshell!\n", 24);
	write(1, "for help, enter --help\n\033[0m", 27);
	env_copy = ft_arr_to_vector(env);
	if (!(mygv = (t_mygv *)malloc(sizeof(t_mygv))))
		exit(EXIT_FAILURE);
	mygv->grab = NULL;
	tcgetattr(STDIN_FILENO, &(mygv->old));
	ft_clear_mygv(mygv);
	ft_get_mygv(mygv);
	ft_init_screen(1);
	while (1)
	{
		mygv->env = env_copy;
		begin(&env_copy);
		ft_clear_mygv(ft_get_mygv(NULL));
	}
	return (0);
}
