/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmaata <wasmaata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 10:12:08 by wasmaata          #+#    #+#             */
/*   Updated: 2025/07/01 22:55:18 by wasmaata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <assert.h>
# include <stdarg.h>

int		ft_toupper(int character);
int		ft_tolower(int character);
char	*ft_strrchr(const char *string, int searchedChar);
char	*ft_strnstr(const char *s1, const char *s2, size_t len);
int		ft_strncmp(const char *first, const char *second, size_t length);
size_t	ft_strlen(const char *string);
char	*ft_strlcpy(const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strchr(const char *string, int searchedChar);
void	*ft_memset(void *pointer, int value, size_t count);
void	*ft_memcpy(void *destination, const void *source, size_t size);
void	*ft_memchr(const void *memoryBlock, int searchedChar, size_t size);
int		ft_memcmp( const void *pointer1, const void *pointer2, size_t size );
void	*ft_memmove(void *dest, const void *src, size_t len);
int		ft_isprint(char *str);
int		ft_isdigit(int character);
int		ft_isascii(int character);
int		ft_isalpha(int character);
int		ft_isalnum(int character);
void	ft_bzero(void *s, size_t n);
int		ft_atoi(const char *theString);
void	*ft_calloc(size_t elementCount, size_t elementSize);
char	*ft_strdup(const char *source);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		isquote(char *str, int i);
char	*ft_realloc_str(char *str, int new_len, char c);
char	**ft_realloc_tab(char **tab, size_t old_len, size_t add_len);
int		ft_add_len(char *str, char c);
int		ft_printf(const char *format, ...);
int		ft_select(const char format, va_list args);
int		ft_putchar(char c);
int		ft_putstr(const char *str);
int		ft_putnbr_hex(unsigned long long n, int len, const char format);
int		ft_putptr(void *ptr);
int		ft_putnbr(int nb, int len);
char	*ft_strjoin3(char *a, char *b, char *c);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

int		ft_putuns(unsigned int nb, int len);

#endif
