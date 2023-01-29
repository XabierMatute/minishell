/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmatute- <xmatute-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 14:47:05 by xmatute-          #+#    #+#             */
/*   Updated: 2023/01/29 17:09:27 by xmatute-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"
#ifndef LIBFT_H
# define LIBFT_H

# include	<stddef.h>
# include	<stdlib.h>
# include <unistd.h>
// # include <stdio.h>
// # include <fcntl.h>
// # include <sys/stat.h>
// # include <stdlib.h>
// # include <sys/types.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int			ft_isalpha(int c);
int			ft_isdigit(int arg);
int			ft_isalnum(int argument);
int			ft_isascii(int a);
int			ft_isprint(int a);
size_t		ft_strlen(const char *s);
void		*ft_memset(void *str, int c, size_t n);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *destination, const void *source, size_t num);
void		*ft_memmove(void *destination, const void *source, size_t num);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
int			ft_toupper(int c);
int			ft_tolower(int c);
char		*ft_strchr(const char *str, int c);
int			ft_atoi(const char *str);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *str1, const char *str2, size_t num );
void		*ft_memchr(const void *str, int c, size_t n);
char		*ft_strnstr(const char	*big, const char *little, size_t len);
int			ft_memcmp(const void *ptr1, const void *ptr2, size_t num );
size_t		ft_strlcat(char *dst, const char *src, size_t size);
void		*ft_calloc(size_t nitems, size_t size);
char		*ft_strdup( const char *str1 );
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_itoa(int n);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));

int			ft_printf(char const *s, ...);

#endif