/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prossesing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 15:09:32 by udraugr-          #+#    #+#             */
/*   Updated: 2019/07/05 16:17:41 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/twenty_one_sh.h"

void		ft_prossesing(char **str, t_vector **env)
{
	char	*prep_pipes;

	prep_pipes = 0;
	if ((*str)[ft_strlen(*str) - 1] == '|')
	{
		ft_error(REDICTFAIL, "");
		return ;
	}
	ft_grab(str, 0, 0);
	ft_space_for_redirs(str);
	ft_replacment(str, env);
	if (ft_prep_for_pipes(*str, &prep_pipes, env) == EXEC_SUCC)
	{
		ft_execute(prep_pipes, env);
		ft_execute("/bin/rm -f /goinfre/.tmp", env);
	}
	ft_strdel(&prep_pipes);
}
