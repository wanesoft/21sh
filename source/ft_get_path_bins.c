/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path_bins.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 14:59:47 by udraugr-          #+#    #+#             */
/*   Updated: 2019/07/20 12:54:08 by draynor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/twenty_one_sh.h"

static int			ft_count_files(char **dirs)
{
	int				i;
	int				count;
	DIR				*d1;
	struct dirent	*f1;

	i = 0;
	count = 0;
	while (dirs[i])
	{
		if ((d1 = opendir(dirs[i])) != 0)
		{
			while ((f1 = readdir(d1)))
			{
				if ((f1->d_name)[0] != '.' && f1->d_type == '\b')
					count++;
			}
			closedir(d1);
		}
		i++;
	}
	return (count);
}

char				**ft_get_path_bins(char **arr)
{
	int				i;
	DIR				*d1;
	struct dirent	*f1;
	char			**ret;

	if (!arr || !arr[0])
		return (NULL);
	i = 0;
	ret = (char **)malloc(sizeof(char *) * (ft_count_files(arr) + 2));
	while (*arr)
	{
		if ((d1 = opendir(*arr)) != 0)
		{
			while ((f1 = readdir(d1)))
			{
				if ((f1->d_name)[0] != '.' && f1->d_type == '\b')
					ret[i++] = ft_strdup(f1->d_name);
			}
			closedir(d1);
		}
		++arr;
	}
	ret[i] = NULL;
	return (ret);
}
