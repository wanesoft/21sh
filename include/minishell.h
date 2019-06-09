/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 11:25:07 by udraugr-          #+#    #+#             */
/*   Updated: 2019/06/09 12:47:27 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libftprintf/ft_printf/printf.h"
# include <dirent.h>
# include <sys/stat.h>
# include <signal.h>

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

# define STDMES 2000
# define FOLD 1
# define BIN 2

# define NOTFOUND 1
# define NOTREG 2
# define NOTDIR 3
# define PERDEN 4
# define NOTEXIST 5

typedef struct		s_var_env
{
	char			*key;
	char			*value;
	char			*full_line;
}					t_var_env;

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

int					ft_strequ(char const *s1, char const *s2);

#endif
