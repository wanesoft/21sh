/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctrl_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: draynor <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/19 17:14:23 by draynor           #+#    #+#             */
/*   Updated: 2019/07/19 17:14:25 by draynor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/twenty_one_sh.h"

static void		ft_ctrl_d_3(char *iter)
{
	while (iter && *iter && *iter != '<' && *iter != '|' && *iter != '>' && *iter != ';')
		++iter;
	if (iter && *iter)
	{
		ft_memmove(iter + 1, iter, ft_strlen(iter));
		*iter = '"';
	}
	else
	{
		*iter = '"';
	}
}

static int		ft_ctrl_d_2(char *iter)
{
	ft_printf("CTRL+D\n");
	iter += 2;
	while (*iter && *iter == ' ')
		ft_memmove(iter, iter + 1, ft_strlen(iter) + 1);
	while (*iter && *iter != '\n')
		ft_memmove(iter, iter + 1, ft_strlen(iter) + 1);
	if (*iter && *iter == '\n')
		*iter = '"';
	else
	{
		++iter;
		ft_memmove(iter + 1, iter, ft_strlen(iter));
		*iter = '"';
	}
	ft_ctrl_d_3(iter);
	while (*iter)
		++iter;
	
	--iter;
	if (*iter && *iter == '\n')
		ft_memmove(iter, iter + 1, ft_strlen(iter) + 1);
	return (1);
}

int				ft_ctrl_d(t_mygv *mygv)
{
	char		*iter;
	
	if (mygv->g_str[0] == 0)
	{
		write(STDOUT_FILENO, "\n", 1);
		ft_bye(&mygv->env);
	}
	iter = ft_strstr(mygv->g_str, "<<");
	if (!iter)
		return (0);
	if (ft_strchr(iter, '\n'))
		return (ft_ctrl_d_2(iter));
	else
		return (0);
}
