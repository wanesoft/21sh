/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   std_operations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 19:10:59 by udraugr-          #+#    #+#             */
/*   Updated: 2019/07/15 19:11:02 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/twenty_one_sh.h"

void        ft_change_std(t_stream *stream)
{
    if (stream->std_now[0] != -1)
        dup2(stream->std_now[0], 0);
    if (stream->std_now[1] != -1)
        dup2(stream->std_now[1], 1);
    if (stream->std_now[2] != -1)
        dup2(stream->std_now[2], 2);
}

void        ft_close_std(t_vector *beg)
{
    while (beg)
    {
        my_reopen(&((t_stream *)beg->content)->std_now[0], -1);
        my_reopen(&((t_stream *)beg->content)->std_now[1], -1);
        my_reopen(&((t_stream *)beg->content)->std_now[2], -1);
        beg = beg->next;
    }
}
