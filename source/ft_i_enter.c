/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_i_enter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 16:58:03 by udraugr-          #+#    #+#             */
/*   Updated: 2019/07/04 15:05:21 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/twenty_one_sh.h"

static int	ft_is_quo(char c)
{
	if (c == '\'' || c == '\"')
		return (1);
	return (0);
}

static int	ft_check_quotes(t_mygv *mygv)
{
	int		fl;
	char	cur_q;
	int		i;

	fl = 0;
	cur_q = 0;
	i = 0;
	while (mygv->g_str[i])
	{
		if (ft_is_quo(mygv->g_str[i]) && !fl)
		{
			cur_q = mygv->g_str[i];
			fl = 1;
		}
		else if (mygv->g_str[i] == cur_q)
		{
			fl = 0;
			cur_q = 0;
		}
		++i;
	}
	return (fl);
}

int			ft_i_enter(t_mygv *mygv)
{
	if (ft_check_quotes(mygv) || ft_pre_heredoc(mygv))
	{
		ft_put_letter('\n', mygv);
		++mygv->g_stage;
		write(STDOUT_FILENO, "\n", 1);
		ft_input();
	}
	else
	{
		mygv->g_y_pos = 1;
		ft_prompt_line(mygv);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (2);
}
