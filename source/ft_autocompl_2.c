/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_autocompl_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 13:57:29 by udraugr-          #+#    #+#             */
/*   Updated: 2019/07/04 13:59:49 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/twenty_one_sh.h"

static void		ft_put_last(t_mygv *mygv, char **arr, int len)
{
	while (arr[0][len])
	{
		ft_put_letter(arr[0][len], mygv);
		++len;
	}
	ft_put_letter(' ', mygv);
}

static void		ft_autocompl_2_2(char **equ, int count, t_mygv *mygv)
{
	ft_autocompl_3(equ, mygv, count);
	ft_print_equ(equ, mygv->g_stage);
}

void			ft_autocompl_2(char **arr, t_mygv *mygv)
{
	int			i;
	int			count;
	char		*str;
	char		**equ;

	count = 0;
	i = mygv->g_j - 1;
	while (i >= 0 && mygv->g_str[i] != ' ' && mygv->g_str[i] != '\n')
	{
		++count;
		--i;
	}
	i = i < 0 ? 0 : i + 1;
	str = ft_strndup(&mygv->g_str[i], count);
	equ = (char **)malloc(sizeof(char *) * (ft_size_equ(str, arr, count) + 1));
	equ[ft_size_equ(str, arr, count)] = NULL;
	ft_put_equ(&equ, str, arr, count);
	if (ft_arrlen(equ) == 1)
		ft_put_last(mygv, equ, count);
	else if (ft_arrlen(equ) == 0)
		++i;
	else
		ft_autocompl_2_2(equ, count, mygv);
	ft_del_arr(&equ);
	free(str);
}
