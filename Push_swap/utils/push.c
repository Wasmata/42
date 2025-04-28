/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmaata <wasmaata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:43:19 by wasmaata          #+#    #+#             */
/*   Updated: 2025/04/22 10:13:03 by wasmaata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push(t_pile **noeud_a, t_pile **noeud_b)
{
	t_pile	*tmp;

	if (noeud_a && *noeud_a)
	{
		tmp = *noeud_a;
		*noeud_a = (*noeud_a)->next;
		if (*noeud_a)
			(*noeud_a)->prev = NULL;
		tmp->next = *noeud_b;
		if (*noeud_b)
			(*noeud_b)->prev = tmp;
		*noeud_b = tmp;
		tmp->prev = NULL;
	}
}

void	pa(t_pile **noeud_a, t_pile **noeud_b)
{
	push(noeud_b, noeud_a);
	write(1, "pa\n", 3);
}

void	pb(t_pile **noeud_a, t_pile **noeud_b)
{
	push(noeud_a, noeud_b);
	write(1, "pb\n", 3);
}
