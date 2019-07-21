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

static void			ft_help(void)
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

static void			ft_hash(t_vector **env)
{
	char			*tmp;
	char			**arr;
	int				i;
	DIR				*d1;
	struct dirent	*f1;

	tmp = ft_take_value_env("PATH", env);
	if (tmp[0] != 0)
	{
		arr = ft_strsplit(tmp, ':');
		i = -1;
		while (arr && arr[++i])
		{
			if ((d1 = opendir(arr[i])) != 0)
			{
				while ((f1 = readdir(d1)) != 0)
				{
					if (f1->d_name[0] != '.')
						ft_printf("%s=%s/%s\n", f1->d_name, arr[i], f1->d_name);
				}
				closedir(d1);
			}
		}
	}
	ft_strdel(&tmp);
}

static int			ft_distribution(char *command, char *str, t_vector **env)
{
	if (ft_strequ(command, "cd"))
		return (EXEC_SUCC);
	else if (ft_strequ(command, "setenv"))
		return (EXEC_SUCC);
	else if (ft_strequ(command, "unsetenv"))
		return (EXEC_SUCC);
	else if (ft_strequ(command, "--help"))
		ft_help();
	else if (ft_strequ(command, "addenv"))
		return (EXEC_SUCC);
	else if (ft_strequ(command, "exit"))
		return (EXEC_SUCC);
	else if (ft_strequ(command, "echo"))
		ft_echo(str);
	else if (ft_strequ(command, "hash"))
		ft_hash(env);
	else if (ft_strequ(command, "env"))
		ft_env(env, str + 3);
	else
		return (EXEC_FAIL);
	return (EXEC_SUCC);
}

int					ft_forward(char *str, char **arr_env)
{
	char			*back;
	char			**arr;
	int				ans;
	t_vector		*env;

	arr = ft_strsplit(str, ' ');
	back = arr[0];
	arr[0] = ft_ungrab(arr[0], 0);
	ft_strtolower(arr[0]);
	env = ft_arr_to_vector(arr_env);
	ans = ft_distribution(arr[0], str, &env);
	ft_strdel(&back);
	ft_del_arr(&arr);
	ft_delall_vector(&env);
	return (ans);
}
