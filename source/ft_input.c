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


static void		ft_put_ctrl_v(char *buf, t_mygv *mygv)
{
	int			i;
	
	i = 0;
	while (buf[i])
	{
		ft_put_letter(buf[i], mygv);
		++i;
	}
}

static int		ft_input_proc(unsigned i, char *buf, t_mygv *mygv)
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
		ft_i_pgup_pgdown(i, mygv);
	else if (buf[1])
		ft_put_ctrl_v(buf, mygv);
	else if (ft_isprint(i))
		ft_put_letter(i, mygv);
	return (0);
}

char			*ft_input(void)
{
	char		buf[BUF_G_STR];
	unsigned	*temp;
	t_mygv		*mygv;

	mygv = ft_get_mygv(NULL);
	while (1)
	{
		ft_prompt_line(mygv);
		ft_bzero(buf, BUF_G_STR);
		read(STDIN_FILENO, buf, BUF_G_STR);
		temp = (unsigned int*)buf;
		//ft_printf("\n\n%d\n\n", *temp);
		if (ft_input_proc(*temp, buf, mygv))
			break;
//		else if (buf[1])
//			ft_put_ctrl_v(buf, mygv);
//		else if (buf[0])
//			ft_put_letter(buf[0], mygv);
	}
	//ft_printf("\n\nKOKO\n\n");
	//return (ft_strdup(mygv->g_str)); // a nado li malloc???
	return (NULL);
}
