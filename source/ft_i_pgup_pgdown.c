
#include "../include/twenty_one_sh.h"

static void		ft_put_his_g_str(t_mygv *mygv, int find)
{
	char		*tmp;
	char		**arr;
	
	tmp = (char *)malloc(sizeof(char) * BUF_G_STR);
	while (ft_gnl_pro(mygv->g_fd_r, &tmp, '\t') > 0)
	{
		arr = ft_strsplit(tmp, ':');
		if (!arr || !arr[0] || !arr[1])
			break;
		if (ft_atoi(arr[0]) == find)
		{
			ft_bzero(mygv->g_str, BUF_G_STR);
			ft_memcpy(mygv->g_str, arr[1], ft_strlen(arr[1]));
			mygv->g_j = (int)ft_strlen(arr[1]);
		}
		ft_del_arr(&arr);
	}
	free(tmp);
}

static int		ft_foo(int bar, unsigned max)
{
	if (bar > max)
		return (max);
	else if (bar <= 1)
		return (1);
	return (bar);
}

static void		ft_muli(unsigned i, t_mygv *mygv)
{
	if (i == K_PGUP)
		++mygv->g_c_his;
	else
		--mygv->g_c_his;
}

void			ft_for_misha(t_mygv *mygv)
{
	int			count;
	int			i;
	
	i = 0;
	count = 0;
	while (mygv->g_str[i])
	{
		if (mygv->g_str[i] == '\n')
			++count;
		++i;
	}
//	if (count)
//		mygv->g_stage = count + 2;
//	else
//		mygv->g_stage = 0;
	while (count)
	{
		ft_putstr_fd(tgetstr("up", NULL), STDOUT_FILENO);
		ft_putstr_fd(tgetstr("dl", NULL), STDOUT_FILENO);
		ft_putstr_fd(tgetstr("cr", NULL), STDOUT_FILENO);
		--count;
	}
}

void			ft_i_pgup_pgdown(unsigned i, t_mygv *mygv)
{
	int			find;
	char		*tmp;
	
	ft_muli(i, mygv);
	if (mygv->g_c_his < 1)
	{
		/*KOKOK*/
		int			ii;
		int			j;
		
		ii = 0;
		j = 0;
		while (mygv->g_str[ii])
		{
			if (mygv->g_str[ii] == '\n')
				++j;
			++ii;
		}
		while (j)
		{
			ft_putstr_fd(tgetstr("up", NULL), STDOUT_FILENO);
			ft_putstr_fd(tgetstr("dl", NULL), STDOUT_FILENO);
			ft_putstr_fd(tgetstr("cr", NULL), STDOUT_FILENO);
			--j;
		}
		
		ft_clear_mygv(mygv);
		mygv->g_c_his = 0;
		return ;
	}
	mygv->g_stage = 0;
	ft_for_misha(mygv);
	mygv->g_c_his = ft_foo(mygv->g_c_his, mygv->g_n_his);
	find = mygv->g_n_his - mygv->g_c_his;
	tmp = ft_strjoin(getenv("HOME"), "/Desktop/21sh_history.txt");
	mygv->g_fd_r = open(tmp, O_RDONLY | O_CREAT, S_IRWXU);
	if (mygv->g_fd_r < 0)
	{
		ft_printf("Error open/create !!IN THE INPUT!! %s\n", tmp);
		exit(EXIT_FAILURE);
	}
	ft_put_his_g_str(mygv, find);
	free(tmp);
	close(mygv->g_fd_r);
}
