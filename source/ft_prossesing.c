/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prossesing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 15:09:32 by udraugr-          #+#    #+#             */
/*   Updated: 2019/07/04 15:15:50 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/twenty_one_sh.h"

void		ft_prossesing(char **str, t_vector **env)
{
	char	*prep_pipes;

	if ((*str)[ft_strlen(*str) - 1] == '|')
	{
		ft_error(REDICTFAIL, "");
		return ;
	}
	ft_grab(str, 0, 0);
	char *sam_razbirajsja_s_mallocom_blo = ft_ungrab(*str, 0);
<<<<<<< HEAD
=======
	ft_printf("/// A TEPER' NAZAD --------- %s\n", sam_razbirajsja_s_mallocom_blo);
	ft_printf("****** DEMO IS END    ->>>>> DEL WHEN POJMESH' *******\n");
	/* DEMO FOR MISHA ->>>>> DEL WHEN POJMESH' */

	//ft_grab(*str); <<----- vklyuchaet vora kavychek
>>>>>>> 282dc2b17369d8d66daf8f6b165ca7a95d98460d
	ft_space_for_redirs(str);
	ft_replacment(str, env);
	prep_pipes = 0;
	if (ft_prep_for_pipes(*str, &prep_pipes, env) == EXEC_SUCC)
	{
		ft_execute(prep_pipes, env);
	}
	ft_strdel(&prep_pipes);
}
