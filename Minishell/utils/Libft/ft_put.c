/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmaata <wasmaata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:48:57 by wasmaata          #+#    #+#             */
/*   Updated: 2024/11/18 13:42:16 by wasmaata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(const char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(const char *str)
{
	int		len;
	char	*null;

	null = "(null)";
	len = 0;
	if (!str)
	{
		while (null[len])
		{
			ft_putchar(null[len]);
			len++;
		}
		return (6);
	}
	while (str[len])
	{
		ft_putchar(str[len]);
		len++;
	}
	return (len);
}

int	ft_putnbr_hex(unsigned long long n, int len, const char format)
{
	char	*base;

	if (format == 'X')
	{
		base = "0123456789ABCDEF";
		n = (unsigned int)n;
	}
	else if (format == 'x')
	{
		base = "0123456789abcdef";
		n = (unsigned int)n;
	}
	else
		base = "0123456789abcdef";
	if (n >= 16)
		len = ft_putnbr_hex(n / 16, len + 1, format);
	else
		len++;
	ft_putchar(base[n % 16]);
	return (len);
}

int	ft_putptr(void *ptr)
{
	int					len;
	unsigned long long	address;

	len = 0;
	address = (unsigned long long)ptr;
	if (!address)
	{
		ft_putstr("(nil)");
		return (5);
	}
	len = ft_putstr("0x");
	len = ft_putnbr_hex(address, len, 'p');
	return (len);
}

int	ft_putnbr(int nb, int len)
{
	long	lnb;

	lnb = nb;
	if (lnb < 0)
	{
		ft_putchar('-');
		lnb *= -1;
		len += 1;
	}
	if (lnb >= 10)
		len = ft_putnbr(lnb / 10, len + 1);
	else
		len++;
	ft_putchar(lnb % 10 + 48);
	return (len);
}
