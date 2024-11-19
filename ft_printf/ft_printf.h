/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmaata <wasmaata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:03:31 by wasmaata          #+#    #+#             */
/*   Updated: 2024/11/18 13:30:16 by wasmaata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <assert.h>
# include <stdarg.h>
# include <stdio.h>

int				ft_printf(const char *format, ...);
int				ft_select(const char format, va_list args);
int				ft_putchar(char c);
int				ft_putstr(const char *str);
int				ft_putnbr_hex(unsigned long long n, int len, const char format);
int				ft_putptr(void *ptr);
int				ft_putnbr(int nb, int len);
unsigned int	ft_putuns(unsigned int nb, int len);

#endif