/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmaata <wasmaata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:34:06 by wasmaata          #+#    #+#             */
/*   Updated: 2024/12/09 14:31:16 by wasmaata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *string, int searchedChar)
{
	unsigned char	c;

	c = (unsigned char)searchedChar;
	while (*string)
	{
		if ((unsigned char)(*string) == c)
			return ((char *)string);
		string++;
	}
	if (c == '\0')
		return ((char *)string);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*dest;

	if (!s1)
		s1 = ft_strdup("");
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

void	ft_bzero(void *s, size_t n)
{
	char	*s_tmp;

	s_tmp = (char *)s;
	while (n)
	{
		*s_tmp = '\0';
		s_tmp++;
		n--;
	}
}

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	char	*str;
	size_t	size;

	size = elementCount * elementSize;
	str = malloc(sizeof(char) * size);
	if (!str)
		return (NULL);
	ft_bzero(str, size);
	return (str);
}

char	*ft_strdup(char *source)
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
