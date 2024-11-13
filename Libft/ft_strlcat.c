/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmaata <wasmaata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:08:56 by wasmaata          #+#    #+#             */
/*   Updated: 2024/11/08 12:36:54 by wasmaata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	ldst;
	size_t	lsrc;

	i = 0;
	ldst = ft_strlen(dst);
	lsrc = ft_strlen(src);
	if (ldst >= size)
		return (lsrc + size);
	while (*src && (ldst + i) < (size - 1))
	{
		dst[ldst + i] = *src;
		i++;
		src++;
	}
	dst[ldst + i] = '\0';
	return (lsrc + ldst);
}
