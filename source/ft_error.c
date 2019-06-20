/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 15:51:01 by udraugr-          #+#    #+#             */
/*   Updated: 2019/06/10 14:36:56 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/twenty_one_sh.h"

void	ft_error(int error, char *str)
{
	write(2, "Mishinshell: ", 13);
	write(2, str, ft_strlen(str));
	if (error == NOTFOUND)
		write(2, ": Command not found", 19);
	else if (error == NOTEXIST)
		write(2, ": No such file or directory", 27);
	else if (error == PERDEN)
		write(2, ": Permission denied", 19);
	else if (error == NOTREG)
		write(2, ": Not a regular file or a soft link", 35);
	else if (error == NOTDIR)
		write(2, ": Not a directory", 17);
	else if (error == REDICTFAIL)
		write(2, "Fail with redirection or pipe", 29);
	write(1, "\n", 1);
}
