/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enzgonca <enzgonca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:51:23 by enzgonca          #+#    #+#             */
/*   Updated: 2024/12/17 13:30:46 by enzgonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000000
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>
# include <stdarg.h>

int		find_newline(char *str);
char	*ft_newline_found(char **buffer, int newline_index, char *line);
char	*read_and_stock(int fd, char *buffer);
char	*extract_line(char **buffer);
char	*get_next_line(int fd);
size_t	ft_strlen(char *str);
char	*ft_substr(char *str, size_t start, size_t len);
char	*ft_strjoin(char *s1, char *s2);

#endif