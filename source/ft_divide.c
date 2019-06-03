/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 15:34:35 by udraugr-          #+#    #+#             */
/*   Updated: 2019/05/26 13:05:03 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	ft_check(char c, char *sep)
{
	while (*sep)
	{
		if (*sep == c)
			return (1);
		++sep;
	}
	return (0);
}

static char	*ft_new_str(char *str, char *sep)
{
	int		i;
	int		len;
	char	*ans;

	i = 0;
	len = 0;
	while (ft_check(*str, sep))
		++str;
	while (str[i])
	{
		while (str[i] && !ft_check(str[i], sep))
		{
			++i;
			++len;
		}
		while (str[i] && ft_check(str[i], sep))
			++i;
		if (str[i])
			++len;
	}
	ans = ft_memalloc(len);
	return (ans);
}

char		*ft_divide(char *str, char *sep)
{
	char	*ans;
	int		i;
	int		j;

	if (!(ans = ft_new_str(str, sep)))
		return (0);
	i = 0;
	j = 0;
	while (ft_check(*str, sep))
		++str;
	while (str[j])
	{
		while (str[j] && !ft_check(str[j], sep))
		{
			ans[i] = str[j];
			++i;
			++j;
		}
		while (str[j] && ft_check(str[j], sep))
			j++;
		if (str[j])
			ans[i++] = ' ';
	}
	return (ans);
}
