/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_bins.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 12:41:08 by udraugr-          #+#    #+#             */
/*   Updated: 2019/06/01 17:29:33 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

extern t_vector	**g_env;

static void		ft_join_all_files(char **all_files, char *dir, const char *text)
{
	DIR				*cur_dir;
	struct dirent	*cur_file;
	char			*tmp;
	char			*tmp2;
	char			*backup;

	if (!(cur_dir = opendir(dir)))
		return ;
	backup = ft_memalloc(1);
	while ((cur_file = readdir(cur_dir)))
	{
		if (ft_strnequ(text, cur_file->d_name, ft_strlen(text)))
		{
			tmp = backup;
			tmp2 = ft_strjoin(cur_file->d_name, "\n");
			backup = ft_strjoin(backup, tmp2);
			ft_strdel(&tmp);
			ft_strdel(&tmp2);
		}
	}
	closedir(cur_dir);
	tmp = *all_files;
	*all_files = ft_strjoin(*all_files, backup);
	ft_strdel(&tmp);
	ft_strdel(&backup);
}

static char		**ft_list_create(char *all_dirs, const char *text)
{
	char		**dirs;
	char		**ans;
	char		*all_files;
	int			i;

	dirs = ft_strsplit(all_dirs, ':');
	i = 0;
	all_files = ft_memalloc(1);
	while (dirs[i])
	{
		ft_join_all_files(&all_files, dirs[i], text);
		++i;
	}
	ft_del_arr(&dirs);
	ans = ft_strsplit(all_files, '\n');
	ft_strdel(&all_files);
	return (ans);
}

char			*ft_list_bins(const char *text, int state)
{
	t_vector	*tmp;
	char		**ans;
	static int	len;
	static int	list_index;

	tmp = *g_env;
	if (!state)
	{
		len = ft_strlen(text);
		list_index = 0;
	}
	while (tmp)
	{
		if (ft_strequ(((t_var_env *)tmp->content)->key, "PATH"))
		{
			ans = ft_list_create((((t_var_env *)tmp->content)->value), text);
			break ;
		}
		tmp = tmp->next;
	}
	if (list_index >= ft_arrlen(ans))
		return (0);
	else
		return (ft_strdup(ans[list_index++]));
}

char			**ft_complete(const char *text, int start, int end)
{
	(void)start;
	(void)end;
	if (!ft_strlen(text))
		return (0);
	rl_attempted_completion_over = 1;
	return (rl_completion_matches(text, ft_list_bins));
}
