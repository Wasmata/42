/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmaata <wasmaata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 09:54:51 by wasmaata          #+#    #+#             */
/*   Updated: 2024/11/08 13:33:12 by wasmaata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *string, int searchedChar)
{
	unsigned int	len;
	unsigned char	c;

	c = (unsigned char)searchedChar;
	len = ft_strlen(string);
	if (!c)
		return ((char *)(string + len));
	while (len > 0)
	{
		if ((unsigned char)string[len - 1] == c)
			return ((char *)(string + len - 1));
		len--;
	}
	return (0);
}
