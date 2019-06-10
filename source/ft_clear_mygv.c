
#include "../include/minishell.h"

void			ft_clear_mygv(t_mygv *mygv)
{
	ft_bzero(mygv->g_str, BUF_G_STR);
	mygv->g_j = 0;
	mygv->g_x_pos = 0;
	mygv->g_y_pos = 0;
}
