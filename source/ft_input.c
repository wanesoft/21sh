/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:01:20 by udraugr-          #+#    #+#             */
/*   Updated: 2019/06/10 16:58:30 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/twenty_one_sh.h"

/*
 
 ** dl - delete line
 ** cr - cursor <-- left side
 ** up - cursos up 1 line

*/
 
static int		ft_input_proc(unsigned i, t_mygv *mygv)
{
	if (i == K_ENTER)
		return (ft_i_enter(mygv));
	else if (i == K_DEL || i == K_BACKSP)
		ft_del_letter(i, mygv);
	else if (i == K_ESC)
		exit(1); //ft_clear_mygv(&mygv);
	else if (i == K_LEFT || i == K_RIGHT)
		ft_i_arrow_l_r(i, mygv);
	else if (ft_isprint(i))
		ft_put_letter(i, mygv);
	return (0);
}

static void		ft_prompt_line_2(t_mygv *mygv)
{
	int			stage;
	int			i;
	
	i = 0;
	stage = 0;
	ft_putstr_fd("\033[36mWelcome> \033[0m", STDOUT_FILENO);
	while (mygv->g_str[i])
	{
		write(STDOUT_FILENO, &mygv->g_str[i], 1);
		if (mygv->g_str[i] == '\n')
		{
			ft_putstr_fd("\033[33mquotes_", STDOUT_FILENO);
			ft_putnbr(stage);
			ft_putstr_fd("> \033[0m", STDOUT_FILENO);
			++stage;
		}
		++i;
	}
}

static void		ft_prompt_line(t_mygv *mygv)
{
	int			y;
	
	y = mygv->g_stage;
	while (y >= 0)
	{
		if (y)
			ft_putstr_fd(tgetstr("up", NULL), STDOUT_FILENO);
		ft_putstr_fd(tgetstr("dl", NULL), STDOUT_FILENO);
		ft_putstr_fd(tgetstr("cr", NULL), STDOUT_FILENO);
		--y;
	}
	ft_prompt_line_2(mygv);
}

char			*ft_input(void)
{
	unsigned	input;
	t_mygv		*mygv;
	
	mygv = ft_get_mygv(NULL);
	while (1)
	{
		input = 0;
		ft_prompt_line(mygv);
		read(STDIN_FILENO, &input, 8);
		if (ft_input_proc(input, mygv))
			break;
	}
	return (ft_strdup(mygv->g_str)); // a nado li malloc???
}
