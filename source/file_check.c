/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 19:05:26 by udraugr-          #+#    #+#             */
/*   Updated: 2019/06/10 14:35:18 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/twenty_one_sh.h"

int					file_check(char *path, int type, int rights, char *command)
{
	struct stat		buf;
	struct stat		buf2;

	if (!access(path, F_OK))
	{
		lstat(path, &buf);
		stat(path, &buf2);
		if ((type == BIN && (S_ISREG(buf.st_mode) ||
							(S_ISLNK(buf.st_mode) && S_ISREG(buf2.st_mode)))) ||
			(type == FOLD && (S_ISDIR(buf.st_mode) ||
							(S_ISLNK(buf.st_mode) && S_ISDIR(buf2.st_mode)))))
		{
			if (!access(path, rights))
				return (1);
			else
				ft_error(PERDEN, command);
		}
		else
			ft_error((type == BIN) ? NOTREG : NOTDIR, command);
	}
	else
		ft_error(NOTEXIST, command);
	return (0);
}
