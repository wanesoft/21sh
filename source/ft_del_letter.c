
#include "../include/twenty_one_sh.h"

void			ft_del_letter(unsigned i, t_mygv *mygv)
{
	if (i == K_DEL)
	{
		return;
	}
	else if (i == K_BACKSP && mygv->g_j > 0)
	{
		--mygv->g_j;
		mygv->g_str[mygv->g_j] = '\0';
	}
}
