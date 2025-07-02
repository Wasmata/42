/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enzgonca <enzgonca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:28:32 by enzgonca          #+#    #+#             */
/*   Updated: 2024/12/03 15:38:26 by enzgonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str && str[len])
		len++;
	return (len);
}

char	*ft_substr(char *str, size_t start, size_t len)
{
	char	*substr;
	size_t	i;

	i = 0;
	if (!str || start >= ft_strlen(str))
		return (NULL);
	substr = malloc(len + 1);
	if (!substr)
		return (NULL);
	while (i < len && str[start + i])
	{
		substr[i] = str[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*tmp;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	tmp = malloc(len1 + len2 + 1);
	if (!tmp)
		return (NULL);
	while (i < len1)
	{
		tmp[i] = s1[i];
		i++;
	}
	while (j < len2)
	{
		tmp[i++] = s2[j++];
	}
	tmp[i] = '\0';
	return (tmp);
}
