/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmaata <wasmaata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 11:19:53 by wasmaata          #+#    #+#             */
/*   Updated: 2025/07/02 01:00:39 by wasmaata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *first, const char *second)
{
	size_t	i;

	i = 0;
	while ((first[i] == second[i]) && (first[i] && second[i]))
		i++;
	return ((unsigned char)first[i] - (unsigned char)second[i]);
}
