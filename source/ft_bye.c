/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bye.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 15:01:30 by udraugr-          #+#    #+#             */
/*   Updated: 2019/07/04 14:04:14 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/twenty_one_sh.h"

static void		ft_bye_mes(void)
{
	ft_putstr("\033[032m------------------\n");
	ft_putstr("| |\n");
	ft_putstr("| |__  _   _  ___\n");
	ft_putstr("| '_ \\| | | |/ _ \\\n");
	ft_putstr("| |_) | |_| |  __/\n");
	ft_putstr("|_.__/ \\__, |\\___|\n");
	ft_putstr("        __/ |\n");
	ft_putstr("       |___/\n");
	ft_putstr("------------------\033[0m\n");
}

void			ft_bye(t_vector **env)
{
	t_vector	*tmp;

	tmp = *env;
	while (tmp)
	{
		if (tmp->content)
		{
			ft_del_content_var_env(((t_var_env *)tmp->content));
			free(tmp->content);
			tmp->content = 0;
		}
		tmp = tmp->next;
	}
	ft_delall_vector(env);
	ft_bye_mes();
	ft_back_screen();
	//do free mygv
	exit(EXIT_SUCCESS);
}
