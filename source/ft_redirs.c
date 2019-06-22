/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 19:01:50 by udraugr-          #+#    #+#             */
/*   Updated: 2019/06/20 19:05:57 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/twenty_one_sh.h"

void			ft_input_redirect(t_vector **redirs, char **old_result)
{
	t_vector	*tmp;
	
	tmp = *redirs;
	while (tmp)
	{
		tmp = tmp->next;
	}
}

void			ft_output_redirect(t_vector **redirs, char **old_result)
{
	t_vector	*tmp;
	int			fd;
	
	tmp = *redirs;
	while (tmp)
	{
		if ((((t_stream *)tmp->content)->type_stream == 4) &&
			((fd = open(((t_stream *)tmp->content)->file,
						   O_CREAT | O_WRONLY, S_IRWXU)) != -1))
		{
			write(fd, *old_result, ft_strlen(*old_result));
			close(fd);
		}
		else if ((((t_stream *)tmp->content)->type_stream == 5) &&
			((fd = open(((t_stream *)tmp->content)->file,
						O_CREAT | O_APPEND | O_WRONLY, S_IRWXU)) != -1))
		{
			write(fd, *old_result, ft_strlen(*old_result));
			close(fd);
		}
		tmp = tmp->next;
	}
}
