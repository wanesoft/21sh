/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 11:21:30 by udraugr-          #+#    #+#             */
/*   Updated: 2019/06/18 14:21:33 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/twenty_one_sh.h"

static int		ft_check(char *str_tmp)
{
	char		*redirs[9] = {"<", "<<", "<&", "&<",
								">", ">>", ">&", "&>",(void *)0};
	int			i;
	
	i = 0;
	while (redirs[i])
	{
		if (ft_strequ(str_tmp, redirs[i]) == 1)
			return (i);
		++i;
	}
	return (-1);
}

static int		ft_get_stream(t_vector **redirs, int *i, char **arr_string,
							  int type_stream)
{
	if (arr_string[*i + 1])
	{
		*redirs = ft_add_vector(*redirs, ft_creat(arr_string[*i + 1], type_stream));
		arr_string[*i][0] = '\0';
		arr_string[*i + 1][0] = '\0';
		*i += 2;
		return (EXEC_SUCC);
	}
	else
		return (EXEC_FAIL);
}

static void		ft_sort_redirs(t_vector **redirs)
{
	t_vector	*tmp_i;
	t_vector	*tmp_j;
	
	if (!redirs || !*redirs)
		return ;
	tmp_i = *redirs;
	while (tmp_i)
	{
		tmp_j = tmp_i->next;
		while (tmp_j)
		{
			if (((t_stream *)tmp_i->content)->type_stream >
				((t_stream *)tmp_j->content)->type_stream)
				ft_swap_vector(tmp_i, tmp_j);
			tmp_j = tmp_j->next;
		}
		tmp_i = tmp_i->next;
	}
}

int				ft_get_redir(char **string, t_vector **redirs)
{
	char		**arr_string;
	int			i;
	int			type_stream;
	char		*ans;
	char		*tmp;
	
	arr_string = ft_strsplit(*string, ' ');
	i = 0;
	while (arr_string[i])
	{
		if ((type_stream = ft_check(arr_string[i])) != -1)
		{
			if (ft_get_stream(redirs, &i, arr_string, type_stream) == EXEC_FAIL)
			{
				ft_error(REDICTFAIL, "");
				return (EXEC_FAIL);
			}
		}
		++i;
	}
	i = -1;
	ans = ft_strdup("");
	while (arr_string[++i])
	{
		tmp = ans;
		ans = ft_strjoin(ans, arr_string[i]);
		ft_strdel(&tmp);
		tmp = ans;
		ans = ft_strjoin(ans, " ");
		ft_strdel(&tmp);
	}
	ft_del_arr(&arr_string);
	ft_strdel(string);
	ft_sort_redirs(redirs);
	*string = ans;
	return (EXEC_SUCC);
}
