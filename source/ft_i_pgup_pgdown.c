
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
	if ((-bar) >= max - 1)
		return ((-max) + 1);
	else if (bar > 0)
		return (0);
	return (bar);
}

void			ft_i_pgup_pgdown(unsigned i, t_mygv *mygv)
{
	int			find;
	char		*tmp;
	
	if (i == K_PGDOWN)
		--mygv->g_c_his;
	else
		++mygv->g_c_his;
	mygv->g_c_his = ft_foo(mygv->g_c_his, mygv->g_n_his);
	find = mygv->g_n_his - 1 + mygv->g_c_his;
	ft_printf("\n\n%d\n\n", find);
	tmp = ft_strjoin(getenv("HOME"), "/Desktop/21sh_history.txt");
	mygv->g_fd_r = open(tmp, O_RDONLY | O_CREAT, S_IRWXU);
	if (mygv->g_fd_r < 0)
	{
		//edit must
		ft_printf("Error open/create !!IN THE INPUT!! %s\n", tmp);
		exit(EXIT_FAILURE);
	}
	ft_put_his_g_str(mygv, find);
	free(tmp);
	close(mygv->g_fd_r);
}
