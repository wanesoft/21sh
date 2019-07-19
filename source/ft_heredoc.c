/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draynor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 17:05:12 by draynor           #+#    #+#             */
/*   Updated: 2019/07/06 17:05:14 by draynor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/twenty_one_sh.h"

static char			*ft_get_target(char *iter)
{
	int				i;
	char			*res;

	i = 0;
	while (*iter && *iter == ' ')
		++iter;
	while (iter[i] && iter[i] != '\n' && iter[i] != ' ' && iter[i] != '<')
		++i;
	res = ft_strndup(iter, i);
	return (res);
}

static int			ft_heredoc_solver(char *target, char **arr, int mode)
{
	if (*arr && mode == 1)
		++arr;
	while (*arr)
	{
		if (ft_strequ(target, *arr))
			return (1);
		++arr;
	}
	return (0);
}

static int			ft_heredoc(char *iter)
{
	char			**arr;
	int				res;
	char			*target;
	char			*tmp;
	int				i;

	res = 1;
	if (iter)
		iter += 2;
	else
		return (0);
	target = ft_get_target(iter);
	i = 0;
	while (iter[i] && iter[i] != '<' && iter[i] != '|' && iter[i] != ';' && iter[i] != '>' && iter[i] != '&')
		++i;
	tmp = ft_strndup(iter, i);
	arr = ft_strsplit(tmp, '\n');
	res = ft_heredoc_solver(target, arr, 1);
	ft_strdel(&tmp);
	ft_get_mygv(NULL)->target = target;
	ft_del_arr(&arr);
	return (!res);
}

static void			ft_should_go(t_mygv *mygv, int mode)
{
	if (mode == 1)
	{
		mygv->g_j = mygv->cur_her + 2;
		while (mygv->g_str[mygv->g_j] && !ft_is_delim(mygv->g_str[mygv->g_j], mygv->g_str[mygv->g_j + 1]))
			++mygv->g_j;
	}
}

int					ft_pre_heredoc(t_mygv *mygv)
{
	int				tmp;

	mygv->g_kos = 0;
	while (mygv->g_str[mygv->cur_her])
	{
		if (mygv->g_str[mygv->cur_her] == '<')
		{
			if (mygv->g_str[mygv->cur_her + 1] == '<')
			{
				ft_should_go(mygv, 1);
				tmp = ft_heredoc(&(mygv->g_str[mygv->cur_her]));
				if (!tmp)
				{
					ft_change_heredoc(mygv);
					mygv->cur_her++;
					ft_should_go(mygv, 1);
					return ((int)(ft_strstr(&mygv->g_str[mygv->cur_her], "<<")));
				}
				ft_strdel(&mygv->target);
				return (tmp);
			}
		}
		++mygv->cur_her;
	}
	return (0);
}
