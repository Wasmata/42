/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmaata <wasmaata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 19:08:49 by wasmaata          #+#    #+#             */
/*   Updated: 2025/07/01 22:54:43 by wasmaata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putuns(unsigned int nb, int len)
{
	if (nb >= 10)
		len = ft_putnbr(nb / 10, len + 1);
	else
		len++;
	ft_putchar(nb % 10 + 48);
	return (len);
}
