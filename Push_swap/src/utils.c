/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmaata <wasmaata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 15:24:23 by wasmaata          #+#    #+#             */
/*   Updated: 2025/04/22 11:00:33 by wasmaata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_str_sort(int *str, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (str[j] > str[j + 1])
			{
				temp = str[j];
				str[j] = str[j + 1];
				str[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	ft_set_index(t_pile **tmp, int	*str, int size)
{
	int	i;

	while (*tmp)
	{
		i = 0;
		while (i < size)
		{
			if ((*tmp)->value == str[i])
			{
				(*tmp)->index = i;
				break ;
			}
			i++;
		}
		*tmp = (*tmp)->next;
	}
}

void	ft_normalize(t_pile **pile, int size)
{
	int		*str;
	t_pile	*tmp;
	int		i;

	i = 0;
	tmp = *pile;
	str = malloc(sizeof(int) * size);
	while (i < size)
	{
		str[i++] = tmp->value;
		tmp = tmp->next;
	}
	ft_str_sort(str, size);
	tmp = *pile;
	ft_set_index(&tmp, str, size);
	ft_select_sort(pile);
	free(str);
}

int	ft_is_sorted(t_pile *pile_a)
{
	if (pile_a->index == -1)
	{
		while (pile_a && pile_a->next)
		{
			if (pile_a->value > pile_a->next->value)
				return (0);
			pile_a = pile_a->next;
		}
	}
	else if (pile_a->index != -1)
	{
		while (pile_a && pile_a->next)
		{
			if (pile_a->index > pile_a->next->index)
				return (0);
			pile_a = pile_a->next;
		}
	}
	return (1);
}

int	ft_max_bits(t_pile *pile_a)
{
	int	max;
	int	bits;

	max = 0;
	bits = 0;
	while (pile_a)
	{
		if (pile_a->index > max)
			max = pile_a->index;
		pile_a = pile_a->next;
	}
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}
