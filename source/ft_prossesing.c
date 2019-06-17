/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prossesing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 15:09:32 by udraugr-          #+#    #+#             */
/*   Updated: 2019/06/17 20:11:27 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/twenty_one_sh.h"

void		ft_prossesing(char *str, t_vector **env)
{
	char 	*prep_pipes;
	ssize_t	a;

	a = 1;
	ft_space_for_redirs(&str);
	ft_printf("{%zu %llu %s}",sizeof(a),  SIZE_MAX, str);
	str = ft_divide(str, " \t\n");
	ft_replacment(&str, env);
	prep_pipes = 0;
	if (ft_prep_for_pipes(str, &prep_pipes, env) == EXEC_SUCC)
		ft_execute(prep_pipes, env);
	ft_strdel(&str);
	ft_strdel(&prep_pipes);
}
