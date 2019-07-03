
#include "../include/twenty_one_sh.h"

static char			*ft_get_target(char *iter)
{
	int				i;
	char			*res;

	i = 0;
	while (*iter && *iter == ' ')
		++iter;
	while (iter[i] && iter[i] != '\n' && iter[i] != ' ' && iter[i] != '<')
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

static int			ft_heredoc(char *iter)
{
	char			**arr;
	int				res;
	char			*target;

	res = 1;
	if (iter)
		iter += 2;
	else
		return (0);
	target = ft_get_target(iter);

	char			*tmp;
	int				i = 0;
	while (iter[i] && iter[i] != '<' && iter[i] != '|' && iter[i] != ';')
		++i;
	tmp = ft_strndup(iter, i);
	int len = (int)ft_strlen(tmp);
	if (len > 0 && tmp[len - 1] == ' ')
		tmp[len - 1] = '\n';

	arr = ft_strsplit(tmp, '\n');
	res = ft_heredoc_solver(target, arr);

	ft_get_mygv(NULL)->target = target;
	ft_del_arr(&arr);
	return (!res);
}

int					ft_is_delim(char c, char d)
{
	if (c == ';' || c == '|' || (c == '<' && d == '<'))
		return (1);
	return (0);
}

static void			ft_should_go(t_mygv *mygv, int mode)
{
	if (mode == 1)
	{
		mygv->g_j = mygv->cur_her + 2;
		while (mygv->g_str[mygv->g_j] && !ft_is_delim(mygv->g_str[mygv->g_j], mygv->g_str[mygv->g_j + 1]))
			++mygv->g_j;
	}
}

void ft_change_heredoc(t_mygv *mygv) {
	char *iter = ft_strstr(mygv->g_str, "<<");
	ft_memmove(iter, iter + 2, ft_strlen(iter) + 1);
	while (*iter == ' ')
		ft_memmove(iter, iter + 1, ft_strlen(iter) + 1);
	ft_memmove(iter, iter + (int)ft_strlen(mygv->target), ft_strlen(mygv->g_str) + 1);
	if (*iter == '\n')
		mygv->g_kos++;
	*iter = '"';

	char *tmp = ft_strjoin("\n", mygv->target);

	iter = ft_strstr(mygv->g_str, tmp);
	if (*iter == '\n')
		mygv->g_kos++;
	*(iter) = '"';
	++iter;
	ft_memmove(iter, iter + (int)ft_strlen(mygv->target), ft_strlen(iter) + 1);
	ft_strdel(&mygv->target);
}

int					ft_pre_heredoc(t_mygv *mygv)
{
	int				tmp;

	mygv->cur_her = 0;
	mygv->g_kos = 0;
	while (mygv->g_str[mygv->cur_her])
	{
		if (mygv->g_str[mygv->cur_her] == '<')
		{
			if (mygv->g_str[mygv->cur_her + 1] == '<')
			{
				ft_should_go(mygv, 1);
				tmp = ft_heredoc(&(mygv->g_str[mygv->cur_her]));
				if (!tmp)
				{
					ft_change_heredoc(mygv);
					ft_should_go(mygv, 1);
					return ((int)(ft_strstr(mygv->g_str, "<<")));
				}
				return (tmp);
			}
		}
		++mygv->cur_her;
	}
	return (0);
}
