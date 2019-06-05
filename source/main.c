/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 11:23:54 by udraugr-          #+#    #+#             */
/*   Updated: 2019/06/01 19:25:15 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

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

	++argc;
	++argv;
	write(1, "\033[31m___________________________\n", 34);
	write(1, "Welcome to mishinshell!\n", 24);
	write(1, "for help, print --help\n", 23);
	write(1, "\033[0m", 4);
	env_copy = ft_arr_to_vector(env);
	begin(&env_copy);
	return (0);
}
