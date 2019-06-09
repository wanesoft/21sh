/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prossesing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 15:09:32 by udraugr-          #+#    #+#             */
/*   Updated: 2019/06/09 13:26:08 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static void	ft_help(void)
{
	ft_printf("env      - показать переменные окружения\n");
	ft_printf("env -s   - показать переменные окружения по алфавиту\n");
	ft_printf("setenv   - установить переменную окружения\n");
	ft_printf("unsetenv - удалить переменную окружения\n");
	ft_printf("сd       - поменять рабочую директорию\n");
	ft_printf("echo     - вывести текст\n");
	ft_printf("addenv   - добавить к переменной окружения одно значение\n");
	ft_printf("exit     - выйти из программы\n");
}

static int	ft_forward(char *str, t_vector **env, char *command)
{
	if (ft_strequ(command, "cd"))
		ft_cd(str, env);
	else if (ft_strequ(command, "setenv"))
		ft_setenv(str + 6, env);
	else if (ft_strequ(command, "unsetenv"))
		ft_unsetenv(str + 8, env);
	else if (ft_strequ(command, "exit"))
		ft_bye(env);
	else if (ft_strequ(command, "--help"))
		ft_help();
	else if (ft_strequ(command, "addenv"))
		ft_addenv(str + 6, env);
	else if (ft_strequ(command, "echo"))
		ft_echo(str);
	else if (ft_strequ(command, "env"))
		ft_env(env, str + 3);
	else
		return (0);
	return (1);
}

void		ft_prossesing(char *str, t_vector **env)
{
	char	**param;
	char	*path;
	char	*command;

	str = ft_divide(str, " \t\n");
	ft_replacment(&str, env);
	param = ft_strsplit(str, ' ');
	ft_strtolower((command = ft_strdup(param[0])));
	if (command && !ft_forward(str, env, command))
	{
		if (ft_strlen(str) == 1 && str[0] == '.')
			write(1, ".: usage: ./path [arguments]\n", 29);
		else if (ft_strchr(command, '/') &&
				file_check(command, BIN, 1, command))
			ft_execute(command, param, env);
		else if (!ft_strchr(command, '/') &&
				ft_search(env, command, &path))
		{
			ft_execute(path, param, env);
			ft_strdel(&path);
		}
	}
	ft_strdel(&str);
	ft_strdel(&command);
	ft_del_arr(&param);
}
