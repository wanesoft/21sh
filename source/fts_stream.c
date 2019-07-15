/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_stream.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 15:30:32 by udraugr-          #+#    #+#             */
/*   Updated: 2019/07/07 09:56:00 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/twenty_one_sh.h"

void			my_reopen(int *fd, int new_fd)
{	
	if (*fd != -1)
	{
		close(*fd);
	}
	*fd = new_fd;
}

t_stream		*ft_create_t_stream(int now_pipe, int all_pipe)
{
	t_stream	*ans;
	
	if (!(ans = (t_stream *)malloc(sizeof(t_stream))))
		return (0);
	ans->now_pipe = now_pipe;
	ans->all_pipe = all_pipe;
	if (!(ans->std_now = (int *)malloc(sizeof(int) * 3)))
	{
		ans->now_pipe = 0;
		ans->all_pipe = 0;
		free(ans);
		ans = 0;
		return (ans);
	}
	ans->std_now[0] = -1;
	ans->std_now[1] = -1;
	ans->std_now[2] = -1;
	ans->proc = 0;
	return (ans);
}

void			ft_destroy_t_stream(t_stream **stream)
{
	if (!*stream)
		return ;
	(*stream)->now_pipe = 0;
	(*stream)->all_pipe = 0;
	(*stream)->proc = 0;
	(*stream)->std_now[0] = 0;
	(*stream)->std_now[1] = 0;
	(*stream)->std_now[2] = 0;
	free((*stream)->std_now);
	(*stream)->std_now = 0;
	free(*stream);
	*stream = 0;
}
