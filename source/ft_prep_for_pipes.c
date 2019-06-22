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

static char	*take_command(char **str)
{
	int		i;
	int		j;
	char	*command;
	
	j = 0;
	while ((*str)[j] && (*str)[j] == ' ')
		++j;
	i = j;
	while ((*str)[i] && (*str)[i] != ' ')
		++i;
	command = ft_strndup(&(*str)[j], i - j);
	ft_strtolower(command);
	return (command);
}

static int	path_bins(char **str, t_vector **env)
{

	int		ans;
	char	*command;
	char	*path;
	char	*tmp;
	char	*back;

	path = 0;
	back = *str;
	command = take_command(str);
	ans = EXEC_FAIL;
	if (ft_strlen(*str) == 1 && command[0] == '.')
		write(1, ".: usage: ./path [arguments]\n", 29);
	else if (check_builts(command) == EXEC_SUCC ||
			(ft_strchr(command, '/') && file_check(command, BIN, 1, command)))
		ans = EXEC_SUCC;
	else if (!ft_strchr(command, '/') && ft_search(env, command, &path))
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
	*prep_for_pipes = ft_strdup("");
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
