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

*/
 
static int		ft_input_proc(unsigned i, t_mygv *mygv)
{
	if (i == K_ENTER)
		return (ft_i_enter(mygv));
	else if (i == K_DEL || i == K_BACKSP)
		ft_del_letter(i, mygv);
	else if (i == K_ESC)
		exit(1); //ft_clear_mygv(&mygv);
	else if (ft_isprint(i))
		ft_put_letter(i, mygv);
	return (0);
}

static void		ft_prompt_line(t_mygv *mygv)
{
	ft_putstr_fd(tgetstr("dl", NULL), STDOUT_FILENO);
	ft_putstr_fd(tgetstr("cr", NULL), STDOUT_FILENO);
	ft_putstr_fd("\033[36mWelcome> \033[0m", STDOUT_FILENO);
	ft_putstr_fd(mygv->g_str, STDOUT_FILENO);
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
		//ft_printf("\n\n %u\n", input);
		if (ft_input_proc(input, mygv))
			break;
	}
	return (ft_strdup(mygv->g_str)); // a nado li malloc???
}
