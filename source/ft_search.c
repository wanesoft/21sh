/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 19:11:21 by udraugr-          #+#    #+#             */
/*   Updated: 2019/06/02 14:10:26 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	look_in_dir(char *dir, char *file, char **path)
{
	DIR				*cur_dir;
	struct dirent	*cur_file;
	char			*full_name;
	int				flag;

	if (!(cur_dir = opendir(dir)))
		return (0);
	flag = 0;
	while ((cur_file = readdir(cur_dir)))
	{
		if (ft_strequ(cur_file->d_name, file))
		{
			full_name = ft_strjoin(dir, "/");
			*path = ft_strjoin(full_name, file);
			ft_strdel(&full_name);
			flag = 1;
			if (file_check(*path, BIN, 1, file))
				break ;
			else
				ft_strdel(path);
			flag = -1;
		}
	}
	closedir(cur_dir);
	return (flag);
}

static int	ft_is_here(char *var_path, char *file, char **path)
{
	char	**dirs;
	int		i;
	int		ans;
	int		error;

	dirs = ft_strsplit(var_path, ':');
	i = 0;
	error = 0;
	while (dirs[i])
	{
		if ((ans = look_in_dir(dirs[i], file, path)) == 1)
		{
			ft_del_arr(&dirs);
			return (1);
		}
		if (!error && ans == -1)
			error = -1;
		++i;
	}
	if (!error)
		ft_error(NOTFOUND, file);
	ft_del_arr(&dirs);
	return (0);
}

int			ft_search(t_vector **env, char *file, char **path)
{
	t_vector		*tmp;

	*path = 0;
	tmp = *env;
	while (tmp)
	{
		if (ft_strequ(((t_var_env *)tmp->content)->key, "PATH"))
		{
			return (ft_is_here(((t_var_env *)tmp->content)->value, file, path));
		}
		tmp = tmp->next;
	}
	ft_error(NOTFOUND, file);
	return (0);
}
