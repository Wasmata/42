/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmaata <wasmaata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 15:50:03 by wasmaata          #+#    #+#             */
/*   Updated: 2024/11/12 22:06:33 by wasmaata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dest;
	int		start;
	int		stop;
	int		i;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	stop = ft_strlen(s1) - 1;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (s1[stop] && ft_strrchr(set, s1[stop]))
		stop--;
	if (start > stop)
		return (ft_strdup(""));
	dest = malloc(sizeof(char) * (stop - start + 2));
	if (!dest)
		return (NULL);
	i = 0;
	while (start <= stop)
		dest[i++] = s1[start++];
	dest[i] = '\0';
	return (dest);
}
