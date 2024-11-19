/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmaata <wasmaata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 19:08:49 by wasmaata          #+#    #+#             */
/*   Updated: 2024/11/18 11:07:07 by wasmaata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_putuns(unsigned int nb, int len)
{
	if (nb >= 10)
		len = ft_putnbr(nb / 10, len + 1);
	else
		len++;
	ft_putchar(nb % 10 + 48);
	return (len);
}
