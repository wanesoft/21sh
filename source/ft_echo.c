/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 15:14:32 by udraugr-          #+#    #+#             */
/*   Updated: 2019/06/02 15:34:25 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void		ft_echo(char *params)
{
//	if (ft_strlen(params) > 4)
//		write(1, params + 5, ft_strlen(params + 5));
//	write(1, "\n", 1);
	ft_printf("%s\n", params);
	ft_printf("\n ---------------------------- EHO \n");
	return ;
}
