
#include "../include/twenty_one_sh.h"

static char			*ft_get_target(char *iter)
{
	int				i;
	char			*res;
	
	i = 0;
	while (*iter && *iter == ' ')
		++iter;
	while (iter[i] && iter[i] != '\n' && iter[i] != ' ')
		++i;
	res = ft_strndup(iter, i);
	return (res);
}

static int			ft_heredoc_solver(char *target, char **arr)
{
	if (*arr)
		++arr;
	while (*arr)
	{
		if (ft_strequ(target, *arr))
			return (1);
		++arr;
	}
	return (0);
}

int					ft_heredoc(t_mygv *mygv)
{
	char			*iter;
	char			**arr;
	int				res;
	char			*target;
	
	res = 1;
	iter = ft_strstr(mygv->g_str, "<<");
	if (iter)
		iter += 2;
	else
		return (0);
	target = ft_get_target(iter);
	arr = ft_strsplit(iter, '\n');
	res = ft_heredoc_solver(target, arr);
	ft_del_arr(&arr);
	return (!res);
}
