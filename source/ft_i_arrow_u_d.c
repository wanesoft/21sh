/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_i_arrow_u_d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 15:03:44 by udraugr-          #+#    #+#             */
/*   Updated: 2019/07/04 15:04:46 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/twenty_one_sh.h"

static void		ft_strlen_pro(int *arr, int j, char *str, int flag)
{
	j += flag;
	while (j >= 0 && str[j] && str[j] != '\n')
	{
		j += flag;
		++arr[0];
	}
	j += flag;
	while (j >= 0 && str[j] && str[j] != '\n')
	{
		j += flag;
		++arr[1];
	}
}

static void		ft_up(unsigned i, t_mygv *mygv)
{
	int			arr[2];

	arr[0] = 0;
	arr[1] = 0;
	ft_strlen_pro(arr, mygv->g_j, mygv->g_str, -1);
	if (!arr[0] && !arr[1] && mygv->g_j > 0)
		--mygv->g_j;
	else if (arr[0] <= arr[1])
		mygv->g_j = mygv->g_j - arr[0] - arr[1] + arr[0] - 1;
	else
		mygv->g_j = mygv->g_j - arr[0] - 1;
	return ;
}

static void		ft_down(unsigned i, t_mygv *mygv)
{
	int			arr[2];

	arr[0] = 0;
	arr[1] = 0;
	ft_strlen_pro(arr, mygv->g_j, mygv->g_str, -1);
	while (mygv->g_str[mygv->g_j] && mygv->g_str[mygv->g_j] != '\n')
		++mygv->g_j;
	if (mygv->g_str[mygv->g_j])
		++mygv->g_j;
	while (mygv->g_str[mygv->g_j] && mygv->g_str[mygv->g_j] != '\n' && arr[0])
	{
		++mygv->g_j;
		--arr[0];
	}
}

void			ft_i_arrow_u_d(unsigned i, t_mygv *mygv)
{
	ft_foo_2(mygv);
	if (i == K_UP)
		ft_up(i, mygv);
	else if (i == K_DOWN)
		ft_down(i, mygv);
	else if (i == K_HOME)
	{
		while (mygv->g_j > 0 && mygv->g_str[mygv->g_j - 1] != '\n')
			--mygv->g_j;
	}
	else if (i == K_END)
	{
		while (mygv->g_str[mygv->g_j] && mygv->g_str[mygv->g_j] != '\n')
			++mygv->g_j;
	}
	if (mygv->g_j < 0)
		mygv->g_j = 0;
	if (mygv->g_j > ft_strlen(mygv->g_str))
		mygv->g_j = (int)ft_strlen(mygv->g_str);
}
