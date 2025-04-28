/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmaata <wasmaata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:43:01 by wasmaata          #+#    #+#             */
/*   Updated: 2025/02/04 22:38:55 by wasmaata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_atoi(const char *theString)
{
	int	i;
	int	sin;
	int	res;

	i = 0;
	sin = 1;
	res = 0;
	while ((theString[i] >= 9 && theString[i] <= 13) || (theString[i] == 32))
		i++;
	if (theString[i] == '+' || theString[i] == '-')
	{
		if (theString[i] == '-')
			sin *= -1;
		i++;
	}
	while (theString[i] >= '0' && theString[i] <= '9')
	{
		res = ((res * 10) + (theString[i] - '0'));
		i++;
	}
	return (res * sin);
}
