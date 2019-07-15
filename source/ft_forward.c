/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_forward.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 15:33:51 by udraugr-          #+#    #+#             */
/*   Updated: 2019/07/07 10:11:15 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/twenty_one_sh.h"

static void		ft_help(void)
{
	ft_printf("setenv   - установить переменную окружения\n");
	ft_printf("unsetenv - удалить переменную окружения\n");
	ft_printf("сd       - поменять рабочую директорию\n");
	ft_printf("addenv   - добавить к переменной окружения одно значение\n");
	ft_printf("exit     - выйти из программы\n");
	ft_printf("env      - показать переменные окружения\n");
	ft_printf("env -s   - показать переменные окружения по алфавиту\n");
	ft_printf("echo     - вывести текст\n");
}

static int		ft_distribution(char *command, char *str, t_vector **env)
{
	if (ft_strequ(command, "cd"))
		ft_cd(str, env);
	else if (ft_strequ(command, "setenv"))
		ft_setenv(str + 6, env);
	else if (ft_strequ(command, "unsetenv"))
		ft_unsetenv(str + 8, env);
	else if (ft_strequ(command, "--help"))
		ft_help();
	else if (ft_strequ(command, "addenv"))
		ft_addenv(str + 6, env);
	else if (ft_strequ(command, "echo"))
		ft_echo(str);
	else if (ft_strequ(command, "env"))
		ft_env(env, str + 3);
	else
		return (EXEC_FAIL);
	return (EXEC_SUCC);
}

int				ft_forward(char *str, char **arr_env)
{
	char		*command;
	char		*back;
	int			i;
	int			ans;
	t_vector	*env;

	i = 0;
	while (str[i] && str[i] != ' ')
		++i;
	command = ft_strndup(str, i);
	back = command;
	command = ft_ungrab(command, 0);
	ft_strtolower(command);
	env = ft_arr_to_vector(arr_env);
	ans = ft_distribution(command, str, &env);
	ft_strdel(&back);
	ft_strdel(&command);
	ft_delall_vector(&env);
	return (ans);
}
