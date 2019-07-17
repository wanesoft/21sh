/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_vect_for_pipes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 19:11:19 by udraugr-          #+#    #+#             */
/*   Updated: 2019/07/17 12:12:31 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/twenty_one_sh.h"

static void			ft_fill_vect_for_pipes(t_vector *begin, int arr_len)
{
	int				count;
	t_vector		*tmp;
	int				pipefd[2];

	tmp = begin;
	count = 1;
	while (tmp)
	{
		if (count < arr_len)
		{
			if (pipe(pipefd) == -1)
				return ;
			((t_stream *)tmp->content)->std_now[1] = pipefd[1];
			((t_stream *)tmp->next->content)->std_now[0] = pipefd[0];
		}
		++count;
		tmp = tmp->next;
	}
}

static void			ft_clean_up(t_vector **begin, t_stream **stream)
{
	t_vector		*tmp;

	tmp = *begin;
	while (tmp)
	{
		ft_destroy_t_stream((t_stream **)&tmp->content);
		tmp = tmp->next;
	}
	ft_delall_vector(begin);
	ft_destroy_t_stream(stream);
}

t_vector			*create_vect_for_pipes(int arr_len)
{
	t_vector		*begin;
	t_vector		*tmp;
	t_stream		*stream;
	int				count;

	begin = 0;
	count = 1;
	stream = ft_create_t_stream(count, arr_len);
	if (arr_len == 0 || !(begin = ft_add_vector(begin, stream)))
	{
		ft_destroy_t_stream(&stream);
		return (0);
	}
	while (count < arr_len)
	{
		++count;
		stream = ft_create_t_stream(count, arr_len);
		if (!(tmp = ft_add_vector(begin, stream)))
		{
			ft_clean_up(&begin, &stream);
			return (0);
		}
	}
	ft_fill_vect_for_pipes(begin, arr_len);
	return (begin);
}
