/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmaata <wasmaata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 12:39:16 by wasmaata          #+#    #+#             */
/*   Updated: 2024/11/11 16:01:12 by wasmaata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	digits(int nbr)
{
	int	c;

	c = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		c++;
	while (nbr != 0)
	{
		c++;
		nbr = nbr / 10;
	}
	return (c);
}

char	*ft_itoa(int n)
{
	char	*dest;
	long	nbrs;
	int		len;
	int		i;

	nbrs = n;
	len = digits(nbrs);
	i = len - 1;
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	if (nbrs < 0)
	{
		dest[0] = '-';
		nbrs = -nbrs;
	}
	else if (nbrs == 0)
		dest[0] = '0';
	while (nbrs != 0)
	{
		dest[i--] = nbrs % 10 + '0';
		nbrs /= 10;
	}
	dest[len] = '\0';
	return (dest);
}
