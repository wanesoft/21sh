
#include "../include/twenty_one_sh.h"

static void		ft_prompt_line_3(t_mygv *mygv)
{
//	int			x;
//
//	x = mygv->g_x_pos + 10;
//	ft_putstr_fd(tgetstr("cr", NULL), STDOUT_FILENO);
//	while (x)
//	{
//		ft_putstr_fd(tgetstr("nd", NULL), STDOUT_FILENO);
//		--x;
//	}
	if (mygv->g_j == ft_strlen(mygv->g_str) && !mygv->g_y_pos)
		ft_putstr_fd("\033[7m \033[0m", STDIN_FILENO);
}

static void		ft_prompt_line_2(t_mygv *mygv)
{
	int			stage;
	int			i;
	
	i = 0;
	stage = 0;
	while (mygv->g_str[i])
	{
		if (i == mygv->g_j && mygv->g_str[i] != '\n' && !mygv->g_y_pos)
		{
//			ft_putstr_fd("\033[7m", STDIN_FILENO);
//			write(STDIN_FILENO, &mygv->g_str[i], 1);
//			ft_putstr_fd("\033[0m", STDOUT_FILENO);
			ft_printf("\033[7m%c\033[0m", mygv->g_str[i]);
			++i;
		}
		if (i == mygv->g_j && mygv->g_str[i] == '\n' && !mygv->g_y_pos)
			ft_putstr_fd("\033[7m \033[0m", STDIN_FILENO);
		write(STDOUT_FILENO, &mygv->g_str[i], 1);
		if (mygv->g_str[i] == '\n')
		{
			ft_printf("\033[33mquotes_");
			(stage > 9) ? 0 : write(1, "0", 1);
			ft_printf("%d> \033[0m", stage);
			++stage;
		}
		++i;
	}
}

void			ft_prompt_line(t_mygv *mygv)
{
	int			y;
	
	y = mygv->g_stage;
	while (y >= 0)
	{
		if (y)
			ft_putstr_fd(tgetstr("up", NULL), STDOUT_FILENO);
		ft_putstr_fd(tgetstr("dl", NULL), STDOUT_FILENO);
		ft_putstr_fd(tgetstr("cr", NULL), STDOUT_FILENO);
		--y;
	}
	ft_putstr_fd("\033[36m[Welcome]> \033[0m", STDOUT_FILENO);
	ft_prompt_line_2(mygv);
	ft_prompt_line_3(mygv);
}
