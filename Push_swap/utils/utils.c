/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmaata <wasmaata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 20:25:54 by wasmaata          #+#    #+#             */
/*   Updated: 2025/04/22 20:41:28 by wasmaata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

long	ft_atol(const char *theString)
{
	int		i;
	int		sin;
	long	res;

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

int	ft_strncmp(const char *first, const char *second)
{
	size_t	i;

	i = 0;
	while ((first[i] == second[i]) && (first[i] && second[i]))
		i++;
	return ((unsigned char)first[i] - (unsigned char)second[i]);
}
