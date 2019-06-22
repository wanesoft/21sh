/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_stream.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 15:30:32 by udraugr-          #+#    #+#             */
/*   Updated: 2019/06/20 15:30:57 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/twenty_one_sh.h"

static void		ft_fill_save(t_stream *tmp)
{
	tmp->save_std[0] = dup(0);
	tmp->save_std[1] = dup(1);
	tmp->save_std[2] = dup(2);
	tmp->std_now[0] = -1;
	tmp->std_now[1] = -1;
	tmp->std_now[2] = -1;
}

t_stream		*ft_create_stream(void)
{
	t_stream	*tmp;
	
	if (!(tmp = (t_stream *)malloc(sizeof(t_stream))))
		return (0);
	ft_fill_save(tmp);
	tmp->output = 0;
	tmp->input = 0;
	return (tmp);
}

void			ft_get_back(t_stream *tmp)
{
	if (tmp->std_now[0] != -1)
	{
		close (tmp->std_now[0]);
		tmp->std_now[0] = -1;
	}
	if (tmp->std_now[1] != -1)
	{
		close (tmp->std_now[1]);
		tmp->std_now[1] = -1;
	}
	if (tmp->std_now[2] != -1)
	{
		close (tmp->std_now[2]);
		tmp->std_now[2] = -1;
	}
	dup2(tmp->save_std[0], 0);
	dup2(tmp->save_std[1], 1);
	dup2(tmp->save_std[2], 2);
	ft_delall_vector(&tmp->output);
	ft_delall_vector(&tmp->input);
	tmp->input = 0;
	tmp->output = 0;
}

void			destroy_t_stream(t_stream **tmp)
{
	if (!tmp)
		return ;
	free(*tmp);
	*tmp = 0;
}
