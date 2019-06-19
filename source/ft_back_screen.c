
#include "../include/twenty_one_sh.h"

void				ft_back_screen(void)
{
	t_mygv			*mygv;
	
	mygv = ft_get_mygv(NULL);
	tcsetattr(STDIN_FILENO, TCSANOW, &mygv->old);
	ft_putstr_fd(tgetstr("ve", NULL), STDIN_FILENO);
	ft_putstr_fd("\033[0m", STDIN_FILENO);
	close(mygv->g_fd_w); //zakryl!
}
