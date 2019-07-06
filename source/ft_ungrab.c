/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ungrab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 15:22:20 by udraugr-          #+#    #+#             */
/*   Updated: 2019/07/04 16:16:54 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/twenty_one_sh.h"

static int		ft_add_to_str(char **s, int i, int n)
{
	char		*tmp;
	char		*tmp2;
	char		*tmp3;
	t_mygv		*m;
	t_stack		*st;

	tmp = ft_strndup(*s, i);
	m = ft_get_mygv(NULL);
	st = ft_imap_stack(m->grab, n);
	tmp2 = ft_strjoin(tmp, st->data);
	++i;
	while ((*s)[i] != -50)
		++i;
	++i;
	tmp3 = ft_strjoin(tmp2, &(*s)[i]);
	free(tmp);
	free(tmp2);
	free(*s);
	*s = tmp3;
	return (i);
}

char			*ft_ungrab(char *s, int i)
{
	char		*ss;

	ss = ft_strdup(s);
	while (ss[i])
	{
		if (ss[i] == -50)
		{
			ft_add_to_str(&ss, i, ft_atoi(&ss[i + 1]));
			i = -1;
		}
		++i;
	}
	return (ss);
}
