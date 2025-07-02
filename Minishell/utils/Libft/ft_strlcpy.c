/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmaata <wasmaata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:15:55 by wasmaata          #+#    #+#             */
/*   Updated: 2025/07/02 00:51:01 by wasmaata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strlcpy(const char *src, size_t size)
{
	unsigned int	i;
	char			*dst;

	i = 0;
	dst = ft_calloc(sizeof(char), (size + 1));
	if (src == NULL || dst == NULL || size == 0)
		return (dst);
	while (i < size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
