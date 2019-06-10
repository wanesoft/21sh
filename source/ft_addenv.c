/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 17:19:42 by udraugr-          #+#    #+#             */
/*   Updated: 2019/06/10 13:55:05 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/21sh.h"

static char	*take_key(char *str)
{
	int		len;
	char	*ans;

	len = 0;
	while (str[len] && str[len] != ':')
		++len;
	if (!str[len] || !len)
		return (0);
	ans = ft_strndup(str, len);
	return (ans);
}

static char	*take_value(char *str)
{
	char	*value;

	value = 0;
	if (ft_strchr(str, ':'))
	{
		value = ft_strdup(ft_strchr(str, ':'));
		if (ft_strlen(value) == 1)
		{
			ft_strdel(&value);
			return (0);
		}
	}
	return (value);
}

static void	ft_er_usage(void)
{
	write(1, "usage: key:value_env\n", 21);
}

static void	ft_join(char *key, char *value, t_vector **env)
{
	t_vector	*tmp;
	char		*old;

	tmp = *env;
	while (tmp)
	{
		if (ft_strequ(((t_var_env *)tmp->content)->key, key))
		{
			old = ((t_var_env *)tmp->content)->value;
			((t_var_env *)tmp->content)->value =
				ft_strjoin(((t_var_env *)tmp->content)->value, value);
			ft_strdel(&old);
			old = ((t_var_env *)tmp->content)->full_line;
			((t_var_env *)tmp->content)->full_line =
				ft_strjoin(((t_var_env *)tmp->content)->full_line, value);
			ft_strdel(&old);
			break ;
		}
		tmp = tmp->next;
	}
	if (!tmp)
		write(1, "Not such variable\n", 18);
}

void		ft_addenv(char *str, t_vector **env)
{
	char	*key;
	char	*value;

	while (*str && (*str == '\n' || *str == ' ' || *str == '\t'))
		++str;
	if (!*str)
		return ;
	if (!(key = take_key(str)))
	{
		ft_er_usage();
		return ;
	}
	if (!(value = take_value(str)))
	{
		ft_er_usage();
		ft_strdel(&key);
		return ;
	}
	ft_join(key, value, env);
	ft_strdel(&key);
	ft_strdel(&value);
}
