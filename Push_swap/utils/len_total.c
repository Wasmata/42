/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_total.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmaata <wasmaata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 09:36:54 by wasmaata          #+#    #+#             */
/*   Updated: 2025/04/22 10:08:27 by wasmaata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_len_total(char	**args)
{
	int	i;
	int	j;

	j = 1;
	i = 0;
	while (args[i])
	{
		while (args[i][j])
			j++;
		i++;
	}
	return (j);
}
