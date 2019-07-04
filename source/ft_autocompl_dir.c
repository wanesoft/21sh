/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_autocompl_dir.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 14:01:03 by udraugr-          #+#    #+#             */
/*   Updated: 2019/07/04 14:01:32 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/twenty_one_sh.h"

static int			ft_count_files(void)
{
	DIR				*d1;
	struct dirent	*f1;
	int				count;

	count = 0;
	d1 = opendir(".");
	while ((f1 = readdir(d1)))
		++count;
	closedir(d1);
	return (count);
}

char				**ft_autocompl_dir(void)
{
	DIR				*d1;
	char			**arr;
	struct dirent	*f1;
	int				i;

	i = 0;
	arr = (char **)malloc(sizeof(char *) * (ft_count_files() + 1));
	arr[ft_count_files()] = NULL;
	d1 = opendir(".");
	while ((f1 = readdir(d1)))
	{
		arr[i] = ft_strdup(f1->d_name);
		++i;
	}
	closedir(d1);
	return (arr);
}
