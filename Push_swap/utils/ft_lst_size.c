/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmaata <wasmaata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 15:29:49 by wasmaata          #+#    #+#             */
/*   Updated: 2025/04/22 10:08:44 by wasmaata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_lst_size(t_pile *pile)
{
	int	len;

	len = 0;
	while (pile)
	{
		len++;
		pile = pile->next;
	}
	return (len);
}
