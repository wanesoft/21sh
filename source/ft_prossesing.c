/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prossesing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 15:09:32 by udraugr-          #+#    #+#             */
/*   Updated: 2019/06/22 15:41:57 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/twenty_one_sh.h"

static void ft_grab_2(char *s, int i, int j)
{
	char	*tmp;
	t_mygv	*mygv;
	int		len;
	
	mygv = ft_get_mygv(NULL);
	tmp = ft_strndup(&s[i], j - i);
	ft_push_stack(&(mygv->grab), ft_new_stack(tmp));
	s[i] = '%';
	len = ft_len_stack(mygv->grab);
	if (len < 10)
		s[i + 1] = len + 48;
	else
	{
		ft_printf("MNOGA KAVYCHEKKKKK!!!!!!!!!!\n\n\n");
		exit(EXIT_FAILURE);
	}
	while (i + 2 < j)
	{
		s[i + 2] = ' ';
		++i;
	}
	free (tmp);
//	sleep(1);
}

static void	ft_grab(char *s)
{
	int		i;
	char	c;
	int		j;
	
	i = 0;
	while (s[i] && s[i] != '"' && s[i] != '\'')
		++i;
	if (s[i])
	{
		c = s[i];
		j = i + 1;
		while (s[j] != c)
			++j;
		++j;
		ft_grab_2(s, i, j);
	}
	else
		return;
	if (j < ft_strlen(s))
		ft_grab(s + j);
}

void		ft_prossesing(char **str, t_vector **env)
{
	char	*prep_pipes;
	
	if ((*str)[ft_strlen(*str) - 1] == '|')
	{
		ft_error(REDICTFAIL, "");
		return ;
	}
	
	/* DEMO FOR MISHA ->>>>> DEL WHEN POJMESH' */
	ft_printf("****** DEMO FOR MISHA ->>>>> DEL WHEN POJMESH' *******\n");
	ft_printf("PRISHLO: %s\n", *str);
	ft_grab(*str);
	ft_printf("IZMENIL: %s\n", *str);
	t_stack *t = (ft_get_mygv(NULL))->grab;
	for (int i = 1; t; t = t->next, ++i)
		ft_printf("SPIZDIL %s POD NOMEROM %d\n", t->data, i);
	ft_printf("****** DEMO IS END    ->>>>> DEL WHEN POJMESH' *******\n");
	/* DEMO FOR MISHA ->>>>> DEL WHEN POJMESH' */
	
	//ft_grab(*str); <<----- vklyuchaet vora kavychek
	ft_space_for_redirs(str);
	ft_replacment(str, env);
	prep_pipes = 0;
	if (ft_prep_for_pipes(*str, &prep_pipes, env) == EXEC_SUCC)
	{
		ft_execute(prep_pipes, env);
	}
	ft_strdel(&prep_pipes);
}
