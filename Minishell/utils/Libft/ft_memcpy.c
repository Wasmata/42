/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmaata <wasmaata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:05:35 by wasmaata          #+#    #+#             */
/*   Updated: 2024/11/08 11:05:13 by wasmaata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *destination, const void *source, size_t size)
{
	unsigned char	*dest_tmp;
	unsigned char	*src_tmp;

	dest_tmp = (unsigned char *)destination;
	src_tmp = (unsigned char *)source;
	if (!dest_tmp && !src_tmp)
		return (0);
	while (size--)
	{
		*dest_tmp = *src_tmp;
		src_tmp++;
		dest_tmp++;
	}
	return (destination);
}
