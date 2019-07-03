
#include "../include/twenty_one_sh.h"

void			ft_i_arrow_l_r(unsigned i, t_mygv *mygv)
{
	mygv->g_kos = 0;
	ft_foo_2(mygv);
	if (i == K_RIGHT && mygv->g_j < ft_strlen(mygv->g_str))
	{
		++mygv->g_x_pos;
		++mygv->g_j;
	}
	else if (i == K_LEFT && mygv->g_j > 0)
	{
		--mygv->g_x_pos;
		--mygv->g_j;
	}
}
