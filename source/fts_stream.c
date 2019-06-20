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

t_stream		*ft_creat(char *file, int type_stream)
{
	t_stream	*tmp;
	
	if (!(tmp = (t_stream *)malloc(sizeof(t_stream))))
		return (0);
	tmp->file = 0;
	tmp->type_stream = 0;
	tmp->file = ft_strdup(file);
	tmp->type_stream = type_stream;
	return (tmp);
}

void			destroy_t_stream(t_stream **tmp)
{
	if (!tmp)
		return ;
	(*tmp)->type_stream = 0;
	if ((*tmp)->file)
		ft_strdel(&(*tmp)->file);
	free(*tmp);
	*tmp = 0;
}
