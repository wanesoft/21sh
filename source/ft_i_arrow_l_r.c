
#include "../include/twenty_one_sh.h"

void			ft_i_arrow_l_r(unsigned i, t_mygv *mygv)
{
	if (i == K_RIGHT && mygv->g_j < ft_strlen(mygv->g_str))
	{
		++mygv->g_x_pos;
		++mygv->g_j;
		//ft_putstr_fd(tgoto(tgetstr("cm", NULL), 10, r), STDOUT_FILENO);
		//tgoto(gotostr, 20, 10)
		//ft_printf("\n\nRIGNT\n");
		//ft_putstr_fd(tgetstr("nd", NULL), STDOUT_FILENO);
	}
	else if (i == K_LEFT && mygv->g_j > 0)
	{
		--mygv->g_x_pos;
		--mygv->g_j;
		//ft_putstr_fd(tgetstr("le", NULL), STDOUT_FILENO);
		//ft_printf("\n\nLEFT\n");
	}
}
