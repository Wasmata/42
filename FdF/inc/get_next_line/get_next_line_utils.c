/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmaata <wasmaata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:34:06 by wasmaata          #+#    #+#             */
/*   Updated: 2025/04/28 18:07:07 by wasmaata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoinn(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*dest;

	if (!s1)
		s1 = ft_strdupp("");
	i = 0;
	j = 0;
	dest = ft_calloc((ft_strlen(s1) + ft_strlen(s2)) + 1, 1);
	if (!dest)
		return (NULL);
	while (s1[j])
	{
		dest[i] = s1[j++];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		dest[i] = s2[j++];
		i++;
	}
	if (s1)
		free(s1);
	return (dest);
}

char	*ft_strdupp(char *source)
{
	char	*dest;
	size_t	i;

	i = 0;
	dest = malloc(sizeof(char) * ft_strlen(source) + 1);
	if (!dest)
		return (NULL);
	while (source[i])
	{
		dest[i] = source[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
