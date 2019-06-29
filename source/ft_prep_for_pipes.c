/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prep_for_pipes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 12:53:36 by udraugr-          #+#    #+#             */
/*   Updated: 2019/06/22 15:45:38 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/twenty_one_sh.h"

static int	check_builts(char *command)
{
	if (ft_strequ("cd", command) ||
			ft_strequ("setenv", command) ||
			ft_strequ("unsetenv", command) ||
			ft_strequ("exit", command) ||
			ft_strequ("--help", command) ||
			ft_strequ("addenv", command) ||
			ft_strequ("echo", command) ||
			ft_strequ("env", command))
		return (EXEC_SUCC);
	return (EXEC_FAIL);
}

static int	take_command(char **str, char **command)
{
	int		i;
	int		j;
    char    *back;
	
	j = 0;
	while ((*str)[j] && (*str)[j] == ' ')
		++j;
	i = j;
	while ((*str)[i] && (*str)[i] != ' ')
		++i;
	*command = ft_strndup(&(*str)[j], i - j);
    back = *command;
    *command = ft_ungrab(*command, 0);
    ft_strdel(&back);
	ft_strtolower(*command);
	return (i);
}

static int	path_bins(char **str, t_vector **env)
{

	int		ans;
	char	*command;
	char	*path;
	char	*tmp;
	int		i;

	path = 0;
	command = 0;
	i = take_command(str, &command);
	ans = EXEC_FAIL;
	if (ft_strlen(command) == 1 && command[0] == '.')
		write(1, ".: usage: ./path [arguments]\n", 29);
	else if (check_builts(command) == EXEC_SUCC ||
			(ft_strchr(command, '/') && file_check(command, BIN, X_OK, command)))
		ans = EXEC_SUCC;
	else if (!ft_strchr(command, '/') && ft_search(env, command, &path))
	{
		ans = EXEC_SUCC;
		tmp = ft_strjoin_pro(path, &(*str)[i], ONLY_FIRST);
		ft_strdel(str);
		*str = tmp;
	}
	ft_strdel(&command);
	return (ans);
}

int			ft_prep_for_pipes(char *str, char **prep_for_pipes, t_vector **env)
{
	char	**tmp;
	int		i;

	tmp = ft_strsplit(str, '|');
	i = 0;
	while (tmp[i])
	{
		if (path_bins(&tmp[i], env) == EXEC_FAIL)
		{
			ft_del_arr(&tmp);
			return (EXEC_FAIL);
		}
		++i;
	}
	i = 0;
	while (tmp[i])
	{
		*prep_for_pipes = ft_strjoin_pro(*prep_for_pipes, tmp[i], ONLY_FIRST);
		*prep_for_pipes = ft_strjoin_pro(*prep_for_pipes, "|", ONLY_FIRST);
		++i;
	}
	ft_del_arr(&tmp);
	return (EXEC_SUCC);
}
