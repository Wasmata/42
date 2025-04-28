/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmaata <wasmaata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:18:06 by wasmaata          #+#    #+#             */
/*   Updated: 2025/04/22 20:33:14 by wasmaata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_3_elements(t_pile **pile_a)
{
	int		f;
	int		s;
	int		t;

	f = (*pile_a)->index;
	s = (*pile_a)->next->index;
	t = (*pile_a)->next->next->index;
	if (f > s && s < t && f < t)
		sa(pile_a);
	else if (f > s && s > t)
	{
		sa(pile_a);
		rra(pile_a);
	}
	else if (f > s && s < t && f > t)
		ra(pile_a);
	else if (f < s && s > t && f < t)
	{
		sa(pile_a);
		ra(pile_a);
	}
	else if (f < s && s > t && f > t)
		rra(pile_a);
}

void	sort_4_elements(t_pile **pile_a)
{
	t_pile	*pile_b;

	pile_b = NULL;
	while ((*pile_a)->index != 0)
		ra(pile_a);
	pb(pile_a, &pile_b);
	sort_3_elements(pile_a);
	pa(pile_a, &pile_b);
}

void	sort_5_elements(t_pile **pile_a)
{
	t_pile	*pile_b;

	pile_b = NULL;
	while (ft_lst_size(*pile_a) > 3)
	{
		if ((*pile_a)->index == 0 || (*pile_a)->index == 1)
			pb(pile_a, &pile_b);
		else
			ra(pile_a);
	}
	sort_3_elements(pile_a);
	if (pile_b->index < pile_b->next->index)
		sb(&pile_b);
	pa(pile_a, &pile_b);
	pa(pile_a, &pile_b);
}

void	ft_radix(t_pile **pile_a)
{
	t_pile	*pile_b;
	int		max_bits;
	int		len_a;
	int		i;
	int		j;

	max_bits = ft_max_bits(*pile_a);
	len_a = ft_lst_size(*pile_a);
	i = 0;
	pile_b = NULL;
	while (i < max_bits)
	{
		j = 0;
		while (j < len_a)
		{
			if ((((*pile_a)->index >> i) & 1) == 1)
				ra(pile_a);
			else
				pb(pile_a, &pile_b);
			j++;
		}
		while (pile_b)
			pa(pile_a, &pile_b);
		i++;
	}
}
