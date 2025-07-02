/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmaata <wasmaata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 17:14:45 by wasmaata          #+#    #+#             */
/*   Updated: 2024/11/08 17:58:59 by wasmaata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *pointer1, const void *pointer2, size_t size)
{
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)pointer1;
	p2 = (unsigned char *)pointer2;
	while (size && *p1 == *p2)
	{
		size--;
		p1++;
		p2++;
	}
	if (size == 0)
		return (0);
	return (*p1 - *p2);
}
