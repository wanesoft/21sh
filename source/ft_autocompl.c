/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_autocompl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draynor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/15 15:07:09 by draynor           #+#    #+#             */
/*   Updated: 2019/07/04 13:57:06 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/twenty_one_sh.h"

static char		**ft_autocompl_path(t_mygv *mygv)
{
	char		**arr;
	t_vector	*tmp;
	char		**ret;

	tmp = mygv->env;
	while (tmp)
	{
		if (ft_strequ(((t_var_env *)tmp->content)->key, "PATH"))
			break ;
		tmp = tmp->next;
	}
	if (!tmp)
		return (NULL);
	arr = ft_strsplit(((t_var_env *)tmp->content)->value, ':');
	ret = ft_get_path_bins(arr);
	ft_del_arr(&arr);
	return (ret);
}

static int		ft_number_of_word(char *s, int cur)
{
	int			vol;

	vol = 0;
	--cur;
	while (cur >= 0)
	{
		if (s[cur] == ' ' || s[cur] == '\n')
			++vol;
		--cur;
	}
	return (vol);
}

void			ft_autocompl(t_mygv *mygv)
{
	char		**arr;

	arr = NULL;
	if (ft_number_of_word(mygv->g_str, mygv->g_j))
		arr = ft_autocompl_dir();
	else
		arr = ft_autocompl_path(mygv);
	ft_autocompl_2(arr, mygv);
	ft_del_arr(&arr);
}
