
#include "../include/minishell.h"

void		ft_put_letter(unsigned i, t_mygv *mygv)
{
	mygv->g_str[mygv->g_j] = (char)i;
	mygv->g_str[mygv->g_j + 1] = '\0';
	++mygv->g_j;
}
