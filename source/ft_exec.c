/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 16:19:53 by udraugr-          #+#    #+#             */
/*   Updated: 2019/07/07 10:21:23 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/twenty_one_sh.h"


void			ft_exec(/*char *str, */char **arr_env, char **param/*,
						char **old_result, t_stream *stream*/)
{
	ft_back_screen(0);
	if ((execve(param[0], param, arr_env) == -1))
		exit(EXEC_FAIL);
}

