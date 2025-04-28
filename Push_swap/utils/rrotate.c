/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmaata <wasmaata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:35:06 by wasmaata          #+#    #+#             */
/*   Updated: 2025/04/22 10:11:41 by wasmaata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rrotate(t_pile **noeud)
{
	t_pile	*last;

	if (noeud && *noeud && (*noeud)->next)
	{
		last = *noeud;
		while (last->next)
			last = last->next;
		last->prev->next = NULL;
		last->next = *noeud;
		last->prev = NULL;
		(*noeud)->prev = last;
		*noeud = last;
	}
}

void	rra(t_pile **noeud)
{
	rrotate(noeud);
	write(1, "rra\n", 4);
}

void	rrb(t_pile **noeud)
{
	rrotate(noeud);
	write(1, "rrb\n", 4);
}

void	rrr(t_pile **noeud_a, t_pile **noeud_b)
{
	rrotate(noeud_a);
	rrotate(noeud_b);
	write(1, "rrr\n", 4);
}
