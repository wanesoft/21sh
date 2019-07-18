/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:01:20 by udraugr-          #+#    #+#             */
/*   Updated: 2019/07/04 15:08:43 by udraugr-         ###   ########.fr       */
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
	int			ck;

	ck = (int)ft_strlen(mygv->g_str);
	i = 0;
	while (buf[i])
	{
		if ((i + ck) == BUF_G_STR - 1)
			return ;
		ft_put_letter(buf[i], mygv);
		++i;
	}
}

static void		ft_ctrl_d_3(char *iter)
{
	while (iter && *iter && *iter != '<' && *iter != '|' && *iter != '>' && *iter != ';')
		++iter;
	if (iter && *iter)
	{
		ft_memmove(iter + 1, iter, ft_strlen(iter));
		*iter = '"';
	}
}

static int		ft_ctrl_d_2(char *iter)
{
	ft_printf("CTRL+D\n");
	iter += 2;
	while (*iter && *iter == ' ')
		ft_memmove(iter, iter + 1, ft_strlen(iter) + 1);
	while (*iter && *iter != '\n')
		ft_memmove(iter, iter + 1, ft_strlen(iter) + 1);
	if (*iter && *iter == '\n')
		*iter = '"';
	else
	{
		++iter;
		ft_memmove(iter + 1, iter, ft_strlen(iter));
		*iter = '"';
	}
	ft_ctrl_d_3(iter);
	while (*iter)
		++iter;

	--iter;
	if (*iter && *iter == '\n')
		ft_memmove(iter, iter + 1, ft_strlen(iter) + 1);
	return (1);
}

static int		ft_ctrl_d(t_mygv *mygv)
{
	char		*iter;
	
	if (mygv->g_str[0] == 0)
	{
		write(STDOUT_FILENO, "\n", 1);
		ft_bye(&mygv->env);
	}
	iter = ft_strstr(mygv->g_str, "<<");
	if (!iter)
		return (0);
	if (ft_strchr(iter, '\n'))
		return (ft_ctrl_d_2(iter));
	else
		return (0);
}

static int		ft_input_proc(unsigned i, char *buf, t_mygv *mygv)
{
	if (i == 4)
		return (ft_ctrl_d(mygv));
	else if (i == K_ENTER)
		return (ft_i_enter(mygv));
	else if (i == K_DEL || i == K_BACKSP)
		ft_del_letter(i, mygv);
	else if (i == K_TAB)
		ft_autocompl(mygv);
	else if (i == K_ESC)
	{
		write(STDOUT_FILENO, "\n", 1);
		ft_bye(&(mygv->env));
	}
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
		if (ft_input_proc(*temp, buf, mygv))
			break ;
	}
	return (NULL);
}
