/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prep_for_pipes.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 12:53:36 by udraugr-          #+#    #+#             */
/*   Updated: 2019/06/14 18:19:35 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/twenty_one_sh.h"

static int	path_bins(char **str, t_vector **env)
{
	int		i;
	int		fl;
	char	*command;
	char	*path;
	char	*tmp;
	char	*back;

	i = 0;
	path = 0;
	back = *str;
	while ((*str)[i] &&  (*str)[i] == ' ')
		++(*str);
	while ((*str)[i] && (*str)[i] != ' ')
		++i;
	command = ft_strndup(*str, i);
	fl = 0;
	if (ft_strlen(*str) == 1 && command[0] == '.')
	{
		write(1, ".: usage: ./path [arguments]\n", 29);
		return (EXEC_FAIL);
	}
	else if (ft_strchr(command, '/') &&
			file_check(command, BIN, 1, command))
		fl = 1;
	else if (!ft_strchr(command, '/') &&
			ft_search(env, command, &path))
	{
		fl = 1;
		if ((*str)[i])
			tmp = ft_strjoin(path, &(*str)[i]);
		else
			tmp = ft_strdup(path);
		ft_strdel(&path);
		ft_strdel(&back);
		*str = tmp;
	}
	ft_strdel(&command);
	return ((fl) ? EXEC_SUCC : EXEC_FAIL);
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
		if (path_bins(&tmp[i], env))
			return (EXEC_FAIL);
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
