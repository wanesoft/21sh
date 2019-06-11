
#include "../include/twenty_one_sh.h"

void			ft_i_arrow_l_r(unsigned i, t_mygv *mygv)
{
	if (i == K_RIGHT)
	{
		ft_printf("\n\nRIGNT\n");
		//ft_putstr_fd(tgetstr("kl", NULL), STDOUT_FILENO);
	}
	else if (i == K_LEFT)
	{
		ft_printf("\n\nLEFT\n");
	}
}
