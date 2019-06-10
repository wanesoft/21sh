/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 18:31:12 by udraugr-          #+#    #+#             */
/*   Updated: 2019/06/10 13:58:18 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/21sh.h"

char		**ft_vector_to_arr(t_vector **env)
{
	char		**arr_env;
	t_vector	*tmp;
	int			i;

	if (!(arr_env = (char **)malloc(sizeof(char *) *
					(ft_count_vector(*env) + 1))))
		return (0);
	tmp = *env;
	i = 0;
	while (tmp)
	{
		arr_env[i] = ft_strdup(((t_var_env *)tmp->content)->full_line);
		tmp = tmp->next;
		++i;
	}
	arr_env[i] = 0;
	return (arr_env);
}

void		ft_abort(int sign)
{
	if (sign == SIGINT)
	{
		signal(SIGINT, ft_restart);
		write(1, "\n\033[31mABORT\n\033[0m", 16);
	}
}

void		ft_execute(char *path, char **param, t_vector **env)
{
	char		**arr_env;
	pid_t		father;

	arr_env = ft_vector_to_arr(env);
	signal(SIGINT, ft_abort);
	father = fork();
	if (!father)
		execve(path, param, arr_env);
	else
		wait(0);
	ft_del_arr(&arr_env);
}
