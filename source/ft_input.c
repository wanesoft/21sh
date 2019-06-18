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
 ** cr - cursor <-- move to left side
 ** up - cursor up 1 line
 ** le - cursor left 1 char
 ** nd - cursor right 1 char

*/
 
static int		ft_input_proc(unsigned i, t_mygv *mygv)
{
	if (i == K_ENTER)
		return (ft_i_enter(mygv));
	else if (i == K_DEL || i == K_BACKSP)
		ft_del_letter(i, mygv);
    else if (i == K_TAB)
        ft_autocompl(mygv);
	else if (i == K_ESC)
		exit(1); //ft_clear_mygv(&mygv);
	else if (i == K_LEFT || i == K_RIGHT)
		ft_i_arrow_l_r(i, mygv);
	else if (i == K_UP || i == K_DOWN || i == K_HOME || i == K_END)
		ft_i_arrow_u_d(i, mygv);
	else if (i == K_PGUP || i == K_PGDOWN)
		ft_i_pgup_pgdown(mygv);
	else if (ft_isprint(i))
		ft_put_letter(i, mygv);
	return (0);
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
		//ft_printf("\n\n%d\n\n", input);
		if (ft_input_proc(input, mygv))
		{
			write(mygv->g_fd, ft_itoa(mygv->g_n_his), ft_strlen(ft_itoa(mygv->g_n_his)));
			write(mygv->g_fd, ":", 1);
			write(mygv->g_fd, mygv->g_str, ft_strlen(mygv->g_str));
			write(mygv->g_fd, "\n", 1);
			++mygv->g_n_his;
			break;
		}
	}
	return (ft_strdup(mygv->g_str)); // a nado li malloc???
}
