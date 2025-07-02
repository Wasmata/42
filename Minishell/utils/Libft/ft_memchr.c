/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmaata <wasmaata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 16:32:58 by wasmaata          #+#    #+#             */
/*   Updated: 2024/11/08 13:35:56 by wasmaata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *memoryBlock, int searchedChar, size_t size)
{
	unsigned char	*mem;
	unsigned char	c;

	mem = (unsigned char *)memoryBlock;
	c = (unsigned char)searchedChar;
	while (size)
	{
		if (*mem == c)
			return (mem);
		size--;
		mem++;
	}
	return (NULL);
}
