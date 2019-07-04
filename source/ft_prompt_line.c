/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 15:13:57 by udraugr-          #+#    #+#             */
/*   Updated: 2019/07/04 15:14:42 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/twenty_one_sh.h"

static void		ft_prompt_line_3(t_mygv *mygv)
{
	if (mygv->g_j == ft_strlen(mygv->g_str) && !mygv->g_y_pos)
		ft_putstr_fd("\033[7m \033[0m", STDIN_FILENO);
}

static void		ft_prompt_line_2(t_mygv *mygv)
{
	int			stage;
	int			i;

	i = 0;
	stage = 0;
	while (mygv->g_str[i])
	{
		if (i == mygv->g_j && mygv->g_str[i] != '\n' && !mygv->g_y_pos)
		{
			ft_printf("\033[7m%c\033[0m", mygv->g_str[i]);
			++i;
		}
		if (i == mygv->g_j && mygv->g_str[i] == '\n' && !mygv->g_y_pos)
			ft_putstr_fd("\033[7m \033[0m", STDIN_FILENO);
		write(STDOUT_FILENO, &mygv->g_str[i], 1);
		if (mygv->g_str[i] == '\n')
		{
//            ft_printf("\033[33m[line_");
//            (stage > 9) ? 0 : write(1, "0", 1);
//            ft_printf("%d]> \033[0m", stage);
			ft_printf("\033[33m[line_%02d]> \033[0m", stage);
			++stage;
		}
		++i;
	}
}

//static void		ft_test_width(t_mygv *mygv)
//{
//	int			line_test;
//
//	line_test = ft_get_max_line(mygv->g_str) + 11;
//	ft_get_tty_col_ros();
////	if (line_test > mygv->col)
////	{
////		mygv->g_stage = line_test / (mygv->col);
////	}
//}

void			ft_prompt_line(t_mygv *mygv)
{
	int			y;

	//ft_test_width(mygv);
	y = mygv->g_stage;
	while (y >= 0)
	{
		if (y)
//			ft_putstr_fd(tgetstr("up", NULL), STDOUT_FILENO);
		ft_putstr_fd(tgetstr("dl", NULL), STDOUT_FILENO);
		ft_putstr_fd(tgetstr("cr", NULL), STDOUT_FILENO);
		--y;
	}
	ft_putstr_fd("\033[36m[Welcome]> \033[0m", STDOUT_FILENO);
	ft_prompt_line_2(mygv);
	ft_prompt_line_3(mygv);
}
