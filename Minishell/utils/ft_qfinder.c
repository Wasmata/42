/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qfinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmaata <wasmaata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 11:25:46 by enzgonca          #+#    #+#             */
/*   Updated: 2025/07/02 01:01:52 by wasmaata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_lastq(char *str, char c)
{
	int	i;
	int	qmax;

	i = 0;
	qmax = 0;
	while (str[i])
	{
		if (str[i] == c)
			qmax = i;
		i++;
	}
	return (qmax);
}

int	ischar(char *str, int i, char c)
{
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	isaplha(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] > 32 && str[i] < 127)
			return (1);
		i++;
	}
	return (0);
}

int	alphastrlen(char *str, int i)
{
	int	j;
	int	len;

	j = i;
	len = 0;
	while (str[j] && (str[j] != 32))
	{
		len++;
		j++;
	}
	return (len);
}
