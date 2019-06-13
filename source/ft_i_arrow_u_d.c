
#include "../include/twenty_one_sh.h"

//static int		ft_never_mind(t_mygv *mygv, int j)
//{
//	int			b;
//
//	b = 0;
//	--j;
//	if (j < 0)
//		return (0);
//	while (j && mygv->g_str[j] && mygv->g_str[j] != '\n')
//	{
//		--j;
//		++b;
//	}
//	return (b);
//}
//
//static void		ft_up_2(t_mygv *mygv, int a, int b)
//{
//	if (a == -1 && b == 0)
//		ft_i_arrow_l_r(K_LEFT, mygv);
//	else if (a == -1)
//	{
//		ft_i_arrow_l_r(K_LEFT, mygv);
//		ft_i_arrow_u_d(K_UP, mygv);
//	}
//	else if (a > b)
//		return;
//	else
//		mygv->g_j = mygv->g_j - b + a;
//}
//
//static void		ft_up(unsigned i, t_mygv *mygv)
//{
//	int			a;
//	int			b;
//
//	a = 0;
//	b = 0;
//	while (mygv->g_j > 0 && mygv->g_str[mygv->g_j] != '\n')
//	{
//		--mygv->g_j;
//		++a;
//	}
//	if (!mygv->g_j)
//		return;
//	b = ft_never_mind(mygv, mygv->g_j);
//	ft_up_2(mygv, a - 1, b);
//}
//
//static void		ft_down(unsigned i, t_mygv *mygv)
//{
//	int			a;
//	int			b;
//
//	a = 0;
//	b = 0;
//}
//
//void			ft_i_arrow_u_d(unsigned i, t_mygv *mygv)
//{
//	if (i == K_UP)
//		ft_up(i, mygv);
//	else if (i == K_DOWN)
//		ft_down(i, mygv);
//}

static void		ft_strlen_pro(int *arr, int j, char *str, int flag)
{
	//--j;
	j += flag;
	while (j >= 0 && str[j] && str[j] != '\n')
	{
		//--j;
		j += flag;
		++arr[0];
	}
	//--j;
	j += flag;
	while (j >= 0 && str[j] && str[j] != '\n')
	{
		//--j;
		j += flag;
		++arr[1];
	}
}


static void		ft_up(unsigned i, t_mygv *mygv)
{
	int			arr[2];
	
	arr[0] = 0;
	arr[1] = 0;
	ft_strlen_pro(arr, mygv->g_j, mygv->g_str, -1);
	if (!arr[0] && !arr[1] && mygv->g_j > 0)
		--mygv->g_j;
	else if (arr[0] <= arr[1])
		mygv->g_j = mygv->g_j - arr[0] - arr[1] + arr[0] - 1;
	else
		mygv->g_j = mygv->g_j - arr[0] - 1;
	return;
}

static void		ft_down(unsigned i, t_mygv *mygv)
{
	int			arr[2];
	
	arr[0] = 0;
	arr[1] = 0;
	ft_strlen_pro(arr, mygv->g_j, mygv->g_str, -1);
	while (mygv->g_str[mygv->g_j] && mygv->g_str[mygv->g_j] != '\n')
		++mygv->g_j;
	if (mygv->g_str[mygv->g_j])
		++mygv->g_j;;
	while (mygv->g_str[mygv->g_j] && mygv->g_str[mygv->g_j] != '\n' && arr[0])
	{
		++mygv->g_j;
		--arr[0];
	}
}

void			ft_i_arrow_u_d(unsigned i, t_mygv *mygv)
{
	if (i == K_UP)
		ft_up(i, mygv);
	else if (i == K_DOWN)
		ft_down(i, mygv);
	if (mygv->g_j < 0)
		mygv->g_j = 0;
	if (mygv->g_j > ft_strlen(mygv->g_str))
		mygv->g_j = (int)ft_strlen(mygv->g_str);
}
