/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   twenty_one_sh.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 14:43:18 by udraugr-          #+#    #+#             */
/*   Updated: 2019/07/19 22:30:48 by draynor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TWENTY_ONE_SH_H
# define TWENTY_ONE_SH_H

# include "../libftprintf/ft_printf/printf.h"
# include <dirent.h>
# include <sys/stat.h>
# include <signal.h>

# include <fcntl.h>

# include <stdio.h>

# include <sys/termios.h>
# include <curses.h>
# include <term.h>
# include <sys/ioctl.h>

# define STDMES 2048
# define FOLD 1
# define BIN 2

# define EXEC_FAIL 1
# define EXEC_SUCC 0

# define NOTFOUND 1
# define NOTREG 2
# define NOTDIR 3
# define PERDEN 4
# define NOTEXIST 5
# define REDICTFAIL 6

# define K_SPACE		32
# define K_ESC			27
# define K_TAB			9
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
# define K_PGUP			2117425947
# define K_PGDOWN		2117491483
# define BUF_G_STR		8192
# define K_OPT_L		1146821403
# define K_OPT_R		1130044187
# define K_OPT_U		1096489755
# define K_OPT_D		1113266971

typedef struct		s_var_env
{
	char			*key;
	char			*value;
	char			*full_line;
}					t_var_env;

typedef struct		s_stream
{
	int				*std_now;
	int				all_pipe;
	int				now_pipe;
	pid_t			proc;
}					t_stream;

typedef struct		s_stack
{
	char			*data;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_mygv
{
	struct termios	old;
	t_vector		*env;
	int				col;
	int				row;
	char			g_str[BUF_G_STR];
	int				g_j;
	int				g_stage;
	int				g_y_pos;
	int				g_fd_r;
	int				g_fd_w;
	unsigned		g_n_his;
	int				g_c_his;
	t_stack			*grab;
	char			*target;
	int				cur_her;
	int				g_kos;
}					t_mygv;

t_var_env			*ft_take_info(char *str);
void				ft_del_content_var_env(t_var_env *cur);

void				begin(t_vector **env);
void				ft_prossesing(char **str, t_vector **env);

void				ft_space_for_redirs(char **str);

t_vector			*ft_arr_to_vector(char **arr_env);

int					ft_forward(char *str, char **arr_env);

void				ft_replacment(char **str, t_vector **env);
int					ft_prep_for_pipes(char *str, char **prep_pipes,
												t_vector **env);

char				*ft_take_value_env(char *key, t_vector **env);

char				*ft_divide(char *str, char *sep);

void				ft_echo(char *param);
void				ft_env(t_vector **env, char *str);
void				ft_unsetenv(char *param, t_vector **env);
void				ft_setenv(char *param, t_vector **env);
void				ft_addenv(char *str, t_vector **env);
void				ft_cd(char *param, t_vector **env);

int					ft_search(t_vector **env, char *file, char **path);

int					file_check(char *path, int type, int rigths, char *command);

void				ft_error(int error, char *str);

void				ft_execute(char *str, t_vector **env);

t_vector			*create_vect_for_pipes(int arr_len);

int					ft_get_redir(char **string, t_stream *stream);
int					ft_simple_redir(char ***arr_string, int i,
										t_stream *stream, int check);
int					ft_advanced_redir(char ***arr_string, int i,
										t_stream *stream);
int					ft_difficult_redir(char ***arr_string,
										int i, t_stream *stream);

t_vector			*ft_get_myproc(t_vector *my_vect, int mode);

void				ft_change_std(t_stream *stream);
void				ft_close_std(t_vector *beg);

void				ft_exec(char **arr_env, char **param);
void				ft_wait(int left_proc);

void				ft_ungrab_arr(char **param);

void				my_reopen(int *fd, int new_fd);
void				ft_destroy_t_stream(t_stream **stream);
t_stream			*ft_create_t_stream(int now_pipe, int all_pipe);

char				**ft_vector_to_arr(t_vector **env);

void				ft_restart(int sign);
void				ft_abort(int sign);

char				*ft_list_bins(const char *text, int state);
char				**ft_complete(const char *text, int start, int end);

void				ft_bye(t_vector **env);

t_mygv				*ft_get_mygv(t_mygv *mygv);
void				ft_clear_mygv(t_mygv *mygv);
void				ft_init_screen(int mode);
char				*ft_input(void);
void				ft_put_letter(unsigned i, t_mygv *mygv);
int					ft_i_enter(t_mygv *mygv);
void				ft_del_letter(unsigned i, t_mygv *mygv);
void				ft_i_arrow_l_r(unsigned i, t_mygv *mygv);
void				ft_i_arrow_u_d(unsigned i, t_mygv *mygv);
void				ft_prompt_line(t_mygv *mygv);
void				ft_back_screen(int signo);
void				ft_get_tty_col_ros(void);
void				ft_autocompl(t_mygv *mygv);
char				**ft_get_path_bins(char **arr);
void				ft_autocompl_2(char **arr, t_mygv *mygv);
void				ft_autocompl_3(char **arr, t_mygv *mygv, int len);
char				**ft_autocompl_dir(void);
void				ft_i_pgup_pgdown(unsigned i, t_mygv *mygv);
int					ft_gnl_pro(const int fd, char **line, char ch);
void				ft_foo_2(t_mygv *mygv);
void				ft_foo_3(t_mygv *mygv);
int					ft_get_max_line(char *str);

void				ft_push_stack(t_stack **head, t_stack *tail);
t_stack				*ft_imap_stack(t_stack *head, int n);
t_stack				*ft_new_stack(char *s);
int					ft_len_stack(t_stack *head);
void				ft_grab(char **s, int i, int j);
char				*ft_ungrab(char *s, int i);
int					ft_pre_heredoc(t_mygv *m);
void				ft_del_stack(t_stack **head);
void				ft_change_heredoc(t_mygv *mygv);
int					ft_is_delim(char c, char d);
void				ft_check_n(void);
char				*ft_strtrim_norm(char const *s);
int					ft_ctrl_d(t_mygv *mygv);
void				ft_print_equ(char **equ, int stage);
void				ft_put_equ(char ***equ, char *str, char **arr, int len);
int					ft_size_equ(char *str, char **arr, int len);

#endif
