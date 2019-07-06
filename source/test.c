/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/06 20:09:02 by udraugr-          #+#    #+#             */
/*   Updated: 2019/07/06 20:26:45 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdarg.h>
#include <sys/wait.h>
#include <signal.h>

void			ft_exec(char *arg, char **env)
{
	char		*tmp[2] = {arg, (void *)0};
	execve(arg, tmp, env);
}

int 			main(int argc, char **argv, char **env)
{
	pid_t		child[2];
	pid_t		tmp;
	int			i;

	i = 0;
	int pipefd[2];
	if (pipe(pipefd) == -1)
		return (1);
	int save[2] = {dup(0), dup(1)};
	while (i < 2)
	{
		child[i] = fork();
		if (!child[i])
		{
			if (i == 0)
				dup2(pipefd[1], 1);
			else
				dup2(pipefd[0], 0);
			ft_exec(argv[i + 1], env);
			return (0);
		}
		if (child[i] == -1)
			return (1);
		++i;
	}
	tmp = wait(0);
	if (tmp == child[1])
	{
		kill(child[0], SIGINT);
	}
	dup2(save[0], 0);
	dup2(save[1], 1);
	return (0);
}
