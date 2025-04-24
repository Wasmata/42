/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmaata <wasmaata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:59:03 by wasmaata          #+#    #+#             */
/*   Updated: 2024/11/09 12:11:10 by wasmaata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int character)
{
	if (((character >= 65 && character <= 90)
			|| (character >= 97 && character <= 122))
		|| (character >= 48 && character <= 57))
		return (1);
	else
		return (0);
}
