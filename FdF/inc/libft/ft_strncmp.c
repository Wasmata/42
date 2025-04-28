/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmaata <wasmaata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 10:02:21 by wasmaata          #+#    #+#             */
/*   Updated: 2024/11/07 10:24:30 by wasmaata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *first, const char *second, size_t length)
{
	size_t	i;

	i = 0;
	while ((first[i] == second[i]) && (first[i] && second[i]) && (length))
	{
		i++;
		length--;
	}
	if (length == 0)
		return (0);
	return ((unsigned char)first[i] - (unsigned char)second[i]);
}
