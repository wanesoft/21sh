/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_i_enter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 16:58:03 by udraugr-          #+#    #+#             */
/*   Updated: 2019/06/10 16:58:06 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/twenty_one_sh.h"

static int	ft_check_quotes(char *str)
{
	int		i;
	int		count;
	
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '"')
			++count;
		++i;
	}
	if (count % 2 != 0)
		return (1);
	return (0);
}

int			ft_i_enter(t_mygv *mygv)
{
	if (ft_check_quotes(mygv->g_str))
	{
		ft_put_letter('\n', mygv);
		ft_input();
	}
	else
		write(STDOUT_FILENO, "\n", 1);
	return (1);
}
