/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   21sh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 13:52:19 by udraugr-          #+#    #+#             */
/*   Updated: 2019/06/10 14:13:07 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "../libftprintf/ft_printf/printf.h"
# include <dirent.h>
# include <sys/stat.h>
# include <signal.h>

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

# include <sys/termios.h>
# include <curses.h>
# include <term.h>

# define STDMES 2048
# define FOLD 1
# define BIN 2

# define NOTFOUND 1
# define NOTREG 2
# define NOTDIR 3
# define PERDEN 4
# define NOTEXIST 5

# define K_SPACE		32
# define K_ESC			27
# define K_Q			113
# define K_DOWN			4348699
# define K_UP			4283163
# define K_RIGHT		4414235
# define K_LEFT			4479771
# define K_ENTER		10
# define K_DEL			2117294875
# define K_BACKSP		127
# define K_HOME			4741915
# define K_END			4610843
# define BUF_G_STR		2048

typedef struct		s_var_env
{
	char			*key;
	char			*value;
	char			*full_line;
}					t_var_env;

typedef struct      s_mygv
{
    struct termios  old;
    char            g_str[BUF_G_STR];
    int             g_j;
    int             g_y_pos;
    int             g_x_pos;
}                   t_mygv;

t_var_env			*ft_take_info(char *str);
void				ft_del_content_var_env(t_var_env *cur);

void				begin(t_vector **env);
void				ft_prossesing(char *str, t_vector **env);
void				ft_replacment(char **str, t_vector **env);

char				*ft_take_value_env(char *key, t_vector **env);

char				*ft_divide(char *str, char *sep);

void				ft_echo(char *param);
void				ft_env(t_vector **env, char *str);
void				ft_unsetenv(char *param, t_vector **env);
void				ft_setenv(char *param, t_vector **env);
void				ft_addenv(char *str, t_vector **env);
void				ft_cd(char *param, t_vector **env);

int					ft_search(t_vector **env, char *file, char **path);

int					file_check(char *path, int type, int mod, char *command);

void				ft_error(int error, char *str);

void				ft_execute(char *path, char **param, t_vector **env);
char				**ft_vector_to_arr(t_vector **env);

void				ft_restart(int sign);
void				ft_abort(int sign);

char				*ft_list_bins(const char *text, int state);
char				**ft_complete(const char *text, int start, int end);

void				ft_bye(t_vector **env);

t_mygv				*ft_get_mygv(t_mygv *mygv);
void				ft_clear_mygv(t_mygv *mygv);
void				ft_init_screen(void);
char				*ft_input(t_vector **env);
void				ft_put_letter(unsigned i, t_mygv *mygv);

#endif
