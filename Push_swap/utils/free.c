/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmaata <wasmaata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:31:30 by wasmaata          #+#    #+#             */
/*   Updated: 2025/04/22 18:31:51 by wasmaata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_pile(t_pile **pile)
{
	t_pile	*tmp;

	if (!pile)
		return ;
	while (*pile)
	{
		tmp = (*pile)->next;
		free(*pile);
		*pile = tmp;
	}
}
