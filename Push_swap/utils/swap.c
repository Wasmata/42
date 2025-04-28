/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmaata <wasmaata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 11:50:16 by wasmaata          #+#    #+#             */
/*   Updated: 2025/04/22 10:11:10 by wasmaata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_pile **noeud)
{
	t_pile	*tmp;
	t_pile	*prev_node;

	if (noeud && (*noeud)->next)
	{
		tmp = (*noeud)->next;
		prev_node = (*noeud)->prev;
		(*noeud)->next = tmp->next;
		if (tmp->next)
			tmp->next->prev = *noeud;
		tmp->prev = prev_node;
		tmp->next = *noeud;
		if (prev_node)
			prev_node->next = tmp;
		*noeud = tmp;
	}
}

void	sa(t_pile **noeud)
{
	swap(noeud);
	write(1, "sa\n", 3);
}

void	sb(t_pile **noeud)
{
	swap(noeud);
	write(1, "sb\n", 3);
}

void	ss(t_pile **noeud_a, t_pile **noeud_b)
{
	swap(noeud_a);
	swap(noeud_b);
	write(1, "ss\n", 3);
}
