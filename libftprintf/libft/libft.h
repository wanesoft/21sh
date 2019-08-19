/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 19:17:06 by udraugr-          #+#    #+#             */
/*   Updated: 2019/08/19 16:56:21 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>

# define BUFF_SIZE 1024
# define ONLY_FIRST 1
# define ONLY_SECOND 2
# define BOTH 3

typedef struct			s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}						t_list;

typedef struct			s_vector
{
	void				*content;
	struct s_vector		*next;
	struct s_vector		*previous;
}						t_vector;

void					ft_putnbr_fd(int n, int fd);
void					ft_putstr_fd(char const *s, int fd);
void					ft_putchar_fd(char c, int fd);
void					ft_putendl_fd(char const *s, int fd);
void					ft_putnbr(int n);
void					ft_putendl(char const *s);
void					ft_putstr(char const *s);
void					ft_putchar(char c);
char					*ft_itoa(int n);
int						ft_tolower(int c);
int						ft_toupper(int c);
int						ft_isprint(int c);
int						ft_isascii(int c);
int						ft_isalnum(int c);
int						ft_isdigit(int c);
int						ft_isalpha(int c);
int						ft_atoi(const char *str);
int						ft_strncmp(const char *str1, const char *str2,
		size_t num);
int						ft_strcmp(const char *str1, const char *str2);
char					*ft_strnstr(const char *big, const char *little,
		size_t len);
char					*ft_strstr(const char *haystack,
		const char *needle);
char					*ft_strrchr(const char *str, int c);
char					*ft_strchr(const char *str, int c);
size_t					ft_strlcat(char *dst,
		const char *src, size_t size);
char					*ft_strncat(char *destination,
		const char *source, size_t num);
char					*ft_strcat(char *destination,
		const char *source);
char					*ft_strncpy(char *destination,
		const char *source, size_t num);
char					*ft_strcpy(char *destination, const char *source);
char					*ft_strdup(const char *src);
size_t					ft_strlen(const char *str);
void					*ft_memset(void *str, int value, size_t num);
void					*ft_bzero(void *s, size_t n);
void					*ft_memcpy(void *dst, const void *src, size_t n);
void					*ft_memccpy(void *dst, const void *src, int c,
		size_t n);
void					*ft_memmove(void *dst, const void *src, size_t len);
void					*ft_memchr(const void *s, int c, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
void					*ft_memalloc(size_t size);
void					ft_memdel(void **ap);
char					*ft_strnew(size_t size);
void					ft_strdel(char **as);
void					ft_strclr(char *s);
void					ft_striter(char *s, void (*f)(char *));
void					ft_striteri(char *s, void (*f)(unsigned int, char*));
char					*ft_strmap(char const *s, char (*f)(char));
char					*ft_strmapi(char const *s,
		char (*f)(unsigned int, char));
int						ft_strequ(char const *s1, char const *s2);
int						ft_strnequ(char const *s1, char const *s2, size_t n);
char					*ft_strsub(char const *s, unsigned int start,
		size_t len);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strtrim(char const *s);
char					**ft_strsplit(char const *s, char c);
t_list					*ft_lstnew(void const *content, size_t
		content_size);
void					ft_lstdelone(t_list **alst,
		void (*del)(void *, size_t));
void					ft_lstdel(t_list **alst,
		void (*del)(void *, size_t));
void					ft_lstadd(t_list **alst, t_list *new);
void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list					*ft_lstsplit(char const *s, char c);
long long				ft_lstfold(int x, int *arr, int (*f)(int, int),
		int lenarr);
void					ft_swap(int *a, int *b);
char					*ft_strrev(char *str);
int						ft_lstlen(t_list *begin);
void					*ft_lstfree(t_list *begin);

int						get_next_line(const int fd, char **line);

char					**ft_copy_arr(int number_of_str, char **str_arr);
void					ft_del_arr(char ***arr);
void					ft_swap_str(char **str1, char **str2);
void					ft_strtolower(char *str);
char					*ft_strndup(char *str, int n);

t_vector				*ft_create_vector(void *content);
int						ft_count_vector(t_vector *begin);
void					ft_del_vector(t_vector **chain);
t_vector				*ft_add_vector(t_vector *begin, void *content);
void					ft_swap_vector(t_vector *v1, t_vector *v2);
void					ft_delall_vector(t_vector **chain);

int						ft_arrlen(char **arr);
char					*ft_strjoin_pro(char *begin, char *end, int mod);
char					**ft_strsplit_str(char const *str, char *sep);

#endif
