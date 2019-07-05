/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_letter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:03:36 by udraugr-          #+#    #+#             */
/*   Updated: 2019/07/04 15:16:32 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/twenty_one_sh.h"

int			ft_get_max_line(char *str)
{
	//str = "123456789\n1234\n123454697889\n34";
	int		i;
	int		count;
	int		max;

	i = 0;
	count = 0;
	max = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			if (count > max)
				max = count;
			count = 0;
		}
		++count;
		++i;
	}
	if (!max)
		max = count;
	return (max);
}

void		ft_put_letter(unsigned i, t_mygv *mygv)
{
	ft_foo_2(mygv);
	ft_memmove(&mygv->g_str[mygv->g_j + 1],
				&mygv->g_str[mygv->g_j],
				ft_strlen(&mygv->g_str[mygv->g_j]));
	mygv->g_str[mygv->g_j] = (char)i;
	++mygv->g_j;
	++mygv->g_x_pos;
}
