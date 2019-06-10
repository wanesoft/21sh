
#include "../include/minishell.h"

/*
 
 ** dl - delete line

*/
 
static int		ft_input_proc(unsigned i, t_mygv *mygv)
{
	if (i == K_ENTER)
		return (1);
	else if (i == K_ESC)
		exit(1); //ft_clear_mygv(&mygv);
	else if (ft_isprint(i))
		ft_put_letter(i, mygv);
	return (0);
}

static void		ft_prompt_line(t_mygv *mygv)
{
	ft_putstr_fd(tgetstr("dl", NULL), STDOUT_FILENO);
	ft_putstr_fd(tgetstr("cr", NULL), STDOUT_FILENO);
	ft_putstr_fd("\033[36mWelcome> \033[0m", STDOUT_FILENO);
	ft_putstr_fd(mygv->g_str, STDOUT_FILENO);
}

char			*ft_input(t_vector **env)
{
	unsigned	input;
	t_mygv		*mygv;
	
	mygv = ft_get_mygv(NULL);
	while (1)
	{
		input = 0;
		ft_prompt_line(mygv);
		read(STDIN_FILENO, &input, 8);
		if (ft_input_proc(input, mygv))
		{
			write(STDOUT_FILENO, "\n", 1);
			break;
		}
	}
	return (ft_strdup(mygv->g_str)); // a nado li malloc???
}
