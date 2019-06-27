/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 18:31:12 by udraugr-          #+#    #+#             */
/*   Updated: 2019/06/26 11:21:50 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/twenty_one_sh.h"

void			ft_abort(int sign)
{
	if (sign == SIGINT)
	{
		signal(SIGINT, ft_restart);
		write(1, "\n\033[31mABORT\n\033[0m", 16);
	}
}

static int		ft_prep_for_execute(char **turn_str, t_stream *stream,
									char **old_result, t_vector **env)
{
	char		**arr_env;
	
	arr_env = ft_vector_to_arr(env);
	if (ft_get_redir(turn_str, stream) == EXEC_FAIL)
		return (EXEC_FAIL);
	if (ft_forward(*turn_str, env) == EXEC_FAIL)
		ft_exec(*turn_str, arr_env, old_result, stream);
	ft_del_arr(&arr_env);
	return (EXEC_SUCC);
}

void			ft_execute(char *str, t_vector **env)
{
	char		**turn;
	char		*old_result;
	t_stream	*stream;
	int			i;
	int			arr_len;
	
	signal(SIGINT, ft_abort);
	turn = ft_strsplit(str, '|');
	i = -1;
	old_result = ft_strdup("");
	arr_len = ft_arrlen(turn);
	stream = ft_create_stream(arr_len);
	while (++i < arr_len)
	{
		if (ft_prep_for_execute(&turn[i], stream,
								&old_result, env) == EXEC_FAIL)
		{
			ft_error(REDICTFAIL, "");
			break ;
		}
		ft_get_back(stream);

	}
	ft_strdel(&old_result);
	ft_del_arr(&turn);
	destroy_t_stream(&stream);
}
