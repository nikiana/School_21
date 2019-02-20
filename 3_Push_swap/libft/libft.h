/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcarrot <kcarrot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 21:49:55 by kcarrot           #+#    #+#             */
/*   Updated: 2019/01/29 13:35:16 by kcarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>

# define BUFF_SIZE 1000

typedef struct		s_list
{
	int				content;
	int				index;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

typedef struct		s_gnl
{
	void			*content;
	size_t			content_size;
	struct s_gnl	*next;
}					t_gnl;

void				ft_putchar(int c);

void				ft_putstr(char const *s);

void				ft_putstr_unicode(int *s);

void				ft_putendl(char const *s);

void				*ft_memalloc(size_t size);

void				ft_memdel(void **ap);

char				*ft_strnew(size_t size);

void				ft_strdel(char **as);

void				ft_strclr(char *s);

void				ft_striter(char *s, void (*f)(char *));

void				ft_striteri(char *s, void (*f)(unsigned int, char *));

char				*ft_strmap(char const *s, char (*f)(char));

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

int					ft_strequ(char const *s1, char const *s2);

int					ft_strnequ(char const *s1, char const *s2, size_t n);

char				*ft_strsub(char const *s, unsigned int start, size_t len);

char				*ft_strjoin(char *s1, char *s2);

char				*ft_strtrim(char const *s);

char				**ft_strsplit(char const *s, char c);

char				*ft_itoa(int n);

char				*ft_itoa_base(unsigned long int value, int base);

void				ft_putnbr(int n);

void				ft_putchar_fd(char c, int fd);

void				ft_putstr_fd(char const *s, int fd);

void				ft_putendl_fd(char const *s, int fd);

void				ft_putnbr_fd(int n, int fd);

void				*ft_memset(void *b, int c, size_t len);

void				ft_bzero(void *s, size_t n);

void				*ft_memcpy(void *dst, const void *src, size_t n);

void				*ft_memccpy(void *dst, const void *src, int c, size_t n);

void				*ft_memmove(void *dst, const void *src, size_t len);

void				*ft_memchr(const void *s, int c, size_t n);

int					ft_memcmp(const void *s1, const void *s2, size_t n);

size_t				ft_strlen(const char *s);

char				*ft_strdup(const char *src);

char				*ft_strcpy(char *dst, const char *src);

char				*ft_strncpy(char *dst, const char *src, size_t len);

char				*ft_strcat(char *s1, const char *s2);

char				*ft_strncat(char *s1, const char *s2, size_t n);

size_t				ft_strlcat(char *dst, const char *src, size_t size);

char				*ft_strchr(const char *s, int c);

char				*ft_strrchr(const char *s, int c);

char				*ft_strstr(const char *a, const char *b);

char				*ft_strnstr(const char *a, const char *b, size_t len);

int					ft_strcmp(const char *s1, const char *s2);

int					ft_strncmp(const char *s1, const char *s2, size_t n);

long int			ft_atoi(const char *str);

int					ft_isalpha(int c);

int					ft_isdigit(int c);

int					ft_isalnum(int c);

int					ft_isascii(int c);

int					ft_isprint(int c);

int					ft_toupper(int c);

int					ft_tolower(int c);

t_list				*ft_lstnew(int content, int index);

void				ft_lstadd(t_list **alst, t_list *new);

int					ft_count_words(char const *s, char c);

t_list				*ft_list_push_back(t_list **begin_list,
					int content, int index);

void				ft_list_push_front(t_list **begin_list,
					int content, int index);

int					ft_list_size(t_list *begin_list);

void				ft_swap(int *a, int *b);

char				*ft_strrev(char *str);

int					ft_is_whitespace(char c);

void				ft_free_arr(char **arr);

int					get_next_line(const int fd, char **line);

t_gnl				*ft_gnl_push_back(t_gnl **begin_list,
					void const *content, size_t content_size);

t_gnl				*ft_gnlnew(void const *content, size_t content_size);

#endif
