/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bye.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 15:01:30 by udraugr-          #+#    #+#             */
/*   Updated: 2019/06/10 14:35:39 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/twenty_one_sh.h"

static void		ft_bye_mes(void)
{
	write(1, "\033[032m___________________________\n", 34);
	write(1, "    _                      \n", 28);
	write(1, "  /   \\             _      \n", 28);
	write(1, "  \\ _   /\\ /\\  \\_| / \\ | | \n", 28);
	write(1, "      \\ \\/ \\/    | | | | | \n", 28);
	write(1, "  \\ _ /  \\  \\  _/  \\_/ \\_/ \n", 28);
	write(1, "   _                       \n", 28);
	write(1, "  | |     _    |     |/\\   \n", 28);
	write(1, "  | |   /   \\ -+- /\\ |\\/   \n", 28);
	write(1, "  | |  |     | |  \\/ |\\    \n", 28);
	write(1, "  |_|__ \\ _ /\\ |_  \\ | \\   \n", 28);
	write(1, "___________________________\n", 28);
	write(1, "\033[0m", 4);
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
	
	exit(0);
}
