/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmaata <wasmaata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 18:23:46 by wasmaata          #+#    #+#             */
/*   Updated: 2025/04/22 10:13:16 by wasmaata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_pile	*ft_lstnew(int value)
{
	t_pile	*new_element;

	new_element = (t_pile *)malloc(sizeof(t_pile));
	if (new_element == NULL)
		return (NULL);
	new_element->value = value;
	new_element->index = -1;
	new_element->next = NULL;
	new_element->prev = NULL;
	return (new_element);
}
