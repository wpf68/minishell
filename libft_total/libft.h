/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwolff <pwolff@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 13:35:03 by pwolff            #+#    #+#             */
/*   Updated: 2022/04/11 11:10:28 by pwolff           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdarg.h>

typedef struct s_list_get
{
	int		len;
	char	*temp;
	char	*tabs;
	int		fd;
}		t_list_get;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}		t_list;

int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
size_t		ft_strlen(const char *str);
void		*ft_memset(void *s, int c, unsigned long int n);
void		ft_bzero(void *s, unsigned long int n);
void		*ft_memcpy(void *dest, const void *src, unsigned long int n);
void		*ft_memmove(void *dest, const void *src, unsigned long int n);
size_t		ft_strlcpy(char *dest, const char *src, unsigned int size);
size_t		ft_strlcat(char *dest, const char *src, size_t size);
int			ft_toupper(int c);
int			ft_tolower(int c);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, unsigned long int n);
void		*ft_memchr(const void *s, int c, unsigned long int n);
int			ft_memcmp(const void *s1, const void *s2, unsigned long int n);
char		*ft_strnstr(const char *s1, const char *s2, unsigned long int len);
long long	ft_atoi(const char *str);
void		*ft_calloc(unsigned long int nb, unsigned long int size);
char		*ft_strdup(const char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char const *s, void (*f)(unsigned int, char*));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *c, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstadd_back(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
char		*get_next_line(int fd);
char		*get_strjoin(char const *s1, char const *s2);
size_t		get_strchr(const char *s, int c);
char		*ft_itoa_unsigned(unsigned int n);
int			ft_printf(const char *tab, ...);
void		ft_printf_c(va_list ap, int *i);
void		ft_printf_s(va_list ap, int *i);
void		ft_printf_d_i(va_list ap, int *i);
void		ft_printf_u(va_list ap, int *i);
void		ft_rev_char_tab(char *tab);
char		*ft_hex_lower(unsigned int nb);
void		ft_printf_x(va_list ap, int *i, char c);
void		ft_printf_p(va_list ap, int *i);
char		*ft_hex_lower_long(unsigned long int nb, char *tab_hex);
char		ft_toupper_print(char c);

#endif
