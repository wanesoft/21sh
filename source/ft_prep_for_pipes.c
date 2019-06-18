/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prep_for_pipes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 12:53:36 by udraugr-          #+#    #+#             */
/*   Updated: 2019/06/18 13:29:49 by udraugr-         ###   ########.fr       */
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

static int	path_bins(char **str, t_vector **env)
{
	int		i;
	int		ans;
	char	*command;
	char	*command2;
	char	*path;
	char	*tmp;
	char	*back;

	i = 0;
	path = 0;
	back = *str;
	while ((*str)[i] && (*str)[i] == ' ')
		++(*str);
	while ((*str)[i] && (*str)[i] != ' ')
		++i;
	command = ft_strndup(*str, i);
	command2 = ft_strdup(command);
	ft_strtolower(command2);
	ans = EXEC_FAIL;
	if (ft_strlen(*str) == 1 && command2[0] == '.')
		write(1, ".: usage: ./path [arguments]\n", 29);
	else if (check_builts(command2) == EXEC_SUCC ||
			(ft_strchr(command2, '/') && file_check(command2, BIN, 1, command)))
		ans = EXEC_SUCC;
	else if (!ft_strchr(command2, '/') && ft_search(env, command2, &path))
	{
		ans = EXEC_SUCC;
		if ((*str)[i])
			tmp = ft_strjoin(path, &(*str)[i]);
		else
			tmp = ft_strdup(path);
		ft_strdel(&path);
		ft_strdel(&back);
		*str = tmp;
	}
	ft_strdel(&command);
	ft_strdel(&command2);
	return (ans);
}

int			ft_prep_for_pipes(char *str, char **prep_for_pipes, t_vector **env)
{
	char	**tmp;
	char	*trash;
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
	*prep_for_pipes = ft_strdup("\0");
	while (tmp[i])
	{
		trash = *prep_for_pipes;
		*prep_for_pipes = ft_strjoin(*prep_for_pipes, tmp[i]);
		ft_strdel(&trash);
		trash = *prep_for_pipes;
		*prep_for_pipes = ft_strjoin(*prep_for_pipes, "|");
		ft_strdel(&trash);
		++i;
	}
	ft_del_arr(&tmp);
	return (EXEC_SUCC);
}
