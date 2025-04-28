/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmaata <wasmaata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:16:59 by wasmaata          #+#    #+#             */
/*   Updated: 2024/11/09 12:10:25 by wasmaata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int character)
{
	if (!(character >= 97 && character <= 122))
		return (character);
	else
		return (character - 32);
}
