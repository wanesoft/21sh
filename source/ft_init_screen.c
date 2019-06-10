
#include "../include/minishell.h"

void				ft_init_screen(void)
{
	struct termios	new;
	
	tcgetattr(STDIN_FILENO, &new);
	new.c_lflag &= ~(ICANON);
	new.c_lflag &= ~(ECHO);
	new.c_cc[VMIN] = 1;
	new.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSADRAIN, &new);
	tgetent(getenv("TERM"), NULL);  //napisat proverku peremennoj
}
