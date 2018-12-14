/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apion <apion@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 15:16:22 by apion             #+#    #+#             */
/*   Updated: 2018/12/08 14:37:41 by apion            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

# ifndef INT_MAX
#  define INT_MAX 2147483647
# endif
# ifndef INT_MIN
#  define INT_MIN (- INT_MAX - 1)
# endif
# ifndef UINT_MAX
#  define UINT_MAX 0xffffffffU
# endif

# ifndef LONG_MAX
#  define LONG_MAX 0x7fffffffffffffffL
# endif
# ifndef LONG_MIN
#  define LONG_MIN (- LONG_MAX - 1)
# endif
# ifndef ULONG_MAX
#  define ULONG_MAX 0xffffffffffffffffUL
# endif

# ifndef SIZE_CHAR
#  define SIZE_CHAR 1
# endif
# ifndef SIZE_SHORT
#  define SIZE_SHORT 2
# endif
# ifndef SIZE_INT
#  define SIZE_INT 4
# endif
# ifndef SIZE_LONG
#  define SIZE_LONG 8
# endif

void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putnbr_hex(unsigned long n);
void			ft_putnbr_base(unsigned long n, const char *b);

void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);

int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_isspace(int c);
int				ft_islowc(int c);
int				ft_isuppc(int c);

int				ft_toupper(int c);
int				ft_tolower(int c);

void			ft_swap(void *a, void *b, int flag);
int				ft_atoi(const char *s);
char			*ft_itoa(int n);

size_t			ft_strlen(const char *s);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strequ(const char *s1, const char *s2);
int				ft_strnequ(const char *s1, const char *s2, size_t n);
int				ft_stricmp(const char *s1, const char *s2);
int				ft_strnicmp(const char *s1, const char *s2, size_t n);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strrev(char *s);
char			*ft_strtrim(const char *s);
char			*ft_strstr(const char *s, const char *needle);
char			*ft_strnstr(const char *s, const char *needle, size_t len);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *s1, const char *s2, size_t size);

char			*ft_strdup(const char *s);
void			ft_strclr(char *s);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
char			*ft_strjoin(const char *s1, const char *s2);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			**ft_strsplit(char const *s, char c);

void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *b, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

void			ft_print_mem(void *addr, size_t n);

#endif
