/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmaata <wasmaata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:17:20 by wasmaata          #+#    #+#             */
/*   Updated: 2024/11/08 17:18:11 by wasmaata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	o;

	i = 0;
	j = 0;
	o = 0;
	if (*s2 == '\0')
		return ((char *)s1);
	while (s1[i] && len > i)
	{
		o = i;
		while (s1[i] == s2[j] && len > i && s1[i] && s2[j])
		{
			i++;
			j++;
		}
		if (s2[j] == '\0')
			return ((char *)(s1 + o));
		j = 0;
		i = o + 1;
	}
	return (NULL);
}
