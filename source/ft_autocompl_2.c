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

static int		ft_size_equ(char *str, char **arr, int len)
{
	int			i;
	int			count;

	i = 0;
	count = 0;
	while (arr && arr[i])
	{
		if (ft_strnequ(str, arr[i], len))
			++count;
		++i;
	}
	return (count);
}

static void		ft_put_equ(char ***equ, char *str, char **arr, int len)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (arr && arr[i])
	{
		if (ft_strnequ(str, arr[i], len))
		{
			(*equ)[j] = ft_strdup(arr[i]);
			++j;
		}
		++i;
	}
}

static void		ft_print_equ(char **equ, int stage)
{
	ft_printf("\n");
	while (*equ)
	{
		ft_printf("%s ", *equ);
		++equ;
	}
	while (stage)
	{
		ft_printf("\n");
		--stage;
	}
	ft_printf("\n");
}

static void		ft_put_last(t_mygv *mygv, char **arr, int len)
{
	while (arr[0][len])
	{
		ft_put_letter(arr[0][len], mygv);
		++len;
	}
	ft_put_letter(' ', mygv);
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
	{
		ft_autocompl_3(equ, mygv, count);
		ft_print_equ(equ, mygv->g_stage);
	}
	ft_del_arr(&equ);
	free(str);
}
