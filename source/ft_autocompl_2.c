
#include "../include/twenty_one_sh.h"

void			ft_autocompl_2(char **arr, t_mygv *mygv)
{
	int			i;
	int			count;
	
	
	count = 0;
	i = mygv->g_j - 1;
	while (i >= 0 && mygv->g_str[i] != ' ' && mygv->g_str[i] != '\n')
	{
		++count;
		--i;
	}
	
}
