/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmaata <wasmaata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:44:56 by wasmaata          #+#    #+#             */
/*   Updated: 2025/04/22 10:12:04 by wasmaata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate(t_pile **noeud)
{
	t_pile	*tmp;
	t_pile	*tete;

	if (noeud && *noeud && (*noeud)->next)
	{
		tmp = *noeud;
		tete = *noeud;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = tete;
		tete->prev = tmp;
		*noeud = tete->next;
		(*noeud)->prev = NULL;
		tete->next = NULL;
	}
}

void	ra(t_pile **noeud)
{
	rotate(noeud);
	write(1, "ra\n", 3);
}

void	rb(t_pile **noeud)
{
	rotate(noeud);
	write(1, "rb\n", 3);
}

void	rr(t_pile **noeud_a, t_pile **noeud_b)
{
	rotate(noeud_a);
	rotate(noeud_b);
	write(1, "rr\n", 3);
}
