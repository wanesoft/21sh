
#include "../include/twenty_one_sh.h"

static void		ft_up_2(t_mygv *mygv, int a, int b)
{
	if (a == 1)
		mygv->g_j++;
	else if (!b)
	{
		while (mygv->g_j && mygv->g_str[mygv->g_j] != '\n')
			--mygv->g_j;
	}
	else if (!a)
		return;
	else if (b > a)
		mygv->g_j += a;
	else
		mygv->g_j += b;
}

static void		ft_up(unsigned i, t_mygv *mygv)
{
	int			a;
	int			b;
	
	a = 0;
	b = 0;
	while (mygv->g_j && mygv->g_str[mygv->g_j] != '\n')
	{
		--mygv->g_j;
		++a;
	}
	if (mygv->g_j)
		--mygv->g_j;
	while (mygv->g_j && mygv->g_str[mygv->g_j] != '\n')
	{
		--mygv->g_j;
		++b;
	}
	ft_up_2(mygv, a, b);
}

static void		ft_down(unsigned i, t_mygv *mygv)
{
	int			a;
	int			b;
	
	a = 0;
	b = 0;
	while (mygv->g_str[mygv->g_j] && mygv->g_str[mygv->g_j] != '\n')
	{
		++mygv->g_j;
		++a;
	}
	if (mygv->g_str[mygv->g_j])
		++mygv->g_j;
	while (mygv->g_str[mygv->g_j] && mygv->g_str[mygv->g_j] != '\n')
	{
		++mygv->g_j;
		++b;
	}
	if (b > a)
		mygv->g_j -= a;
	else
		mygv->g_j -= b;
}

void			ft_i_arrow_u_d(unsigned i, t_mygv *mygv)
{
	if (i == K_UP)
		ft_up(i, mygv);
	else if (i == K_DOWN)
		ft_down(i, mygv);
}
