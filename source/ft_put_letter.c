/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_letter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:03:36 by udraugr-          #+#    #+#             */
/*   Updated: 2019/06/10 14:39:30 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/twenty_one_sh.h"

int			ft_get_max_line(char *str)
{
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
	int		line_test;
	
	ft_memmove(&mygv->g_str[mygv->g_j + 1], &mygv->g_str[mygv->g_j], ft_strlen(&mygv->g_str[mygv->g_j]));
	mygv->g_str[mygv->g_j] = (char)i;
	++mygv->g_j;
	++mygv->g_x_pos;
	line_test = ft_get_max_line(mygv->g_str) + 11;
	ft_get_tty_col_ros();
	if (line_test > mygv->col)
	{
		mygv->g_stage = line_test / mygv->col;
		write(1, "\n>=(\nIDI V PIZDU, TESTER\n\n", 30);
		exit(1);
	}
}
