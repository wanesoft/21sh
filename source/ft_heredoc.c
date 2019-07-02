
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
	free(target);
	ft_del_arr(&arr);
	return (!res);
}
//
//static void			ft_prep_2(t_mygv *mygv)
//{
//	int				i;
//
//	i = 0;
//	while (mygv->g_str[i])
//	{
//		if (mygv->g_str[i] == '<' && mygv->g_str[i + 1] == '<')
//		{
//			if (mygv->g_str[i + 2] != ' ')
//			{
//				ft_memmove(&mygv->g_str[i + 3], &mygv->g_str[i + 2], ft_strlen(&mygv->g_str[i + 2]));
//				mygv->g_str[i + 2] = ' ';
//			}
//			if (i > 1 && mygv->g_str[i - 1] != ' ')
//			{
//				ft_memmove(&mygv->g_str[i + 1], &mygv->g_str[i], ft_strlen(&mygv->g_str[i]));
//				mygv->g_str[i] = ' ';
//			}
//		}
//		++i;
//	}
//}

int					ft_is_delim(char c)
{
	if (c == ';' || c == '|' || c == '<')
		return (1);
	return (0);
}

static void			ft_should_go(t_mygv *mygv)
{
	mygv->g_j = mygv->cur_her + 2;
	while (mygv->g_str[mygv->g_j] && mygv->g_str[mygv->g_j] == ' ')
		++mygv->g_j;
	while (mygv->g_str[mygv->g_j] && !ft_is_delim(mygv->g_str[mygv->g_j]))
		++mygv->g_j;
}

int					ft_pre_heredoc(t_mygv *mygv)
{
	int				tmp;
	
	while (mygv->g_str[mygv->cur_her])
	{
		if (mygv->g_str[mygv->cur_her] == '<')
		{
			if (mygv->g_str[mygv->cur_her + 1] == '<')
			{
				ft_should_go(mygv);
				tmp = ft_heredoc(&(mygv->g_str[mygv->cur_her]));

				int fd = open("log.txt", O_CREAT | O_RDWR | O_TRUNC, S_IRWXU);
				write(fd, ft_itoa(tmp), ft_strlen(ft_itoa(tmp)));
				write(fd, " ", 1);
				write(fd, ft_itoa(mygv->g_j), ft_strlen(ft_itoa(mygv->g_j)));
				write(fd, " ", 1);
				write(fd, ft_itoa(mygv->cur_her), ft_strlen(ft_itoa(mygv->cur_her)));
				write(fd, "\n", 1);

				if (!tmp)
				{
					mygv->cur_her += 2;
					while (mygv->g_str[mygv->g_j] && mygv->g_str[mygv->g_j] != '<')
						++mygv->g_j;
					ft_should_go(mygv);
					return ((int)(ft_strstr(&mygv->g_str[mygv->cur_her], "<<")));
				}
				return (tmp);
			}
		}
		++mygv->cur_her;
	}
	return (0);
}
