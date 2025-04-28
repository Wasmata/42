/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmaata <wasmaata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 15:28:05 by wasmaata          #+#    #+#             */
/*   Updated: 2025/04/23 12:27:19 by wasmaata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <limits.h>

int	check_num(char *liste)
{
	int	i;

	i = 0;
	while ((liste[i] && (liste[i] >= '0' && liste[i] <= '9'))
		|| (liste[i] == ' ' || liste[i] == '-'))
		i++;
	if (!liste[i])
		return (1);
	return (0);
}

static int	invalid_limits(char *str)
{
	long	nb;

	nb = ft_atol(str);
	if (nb > INT_MAX || nb < INT_MIN)
		return (1);
	return (0);
}

int	check_double(char **liste)
{
	int		i;
	int		j;

	i = 0;
	while (liste[i])
	{
		if (invalid_limits(liste[i]))
			return (0);
		j = i + 1;
		while (liste[j])
		{
			if (ft_strncmp(liste[i], liste[j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	i = 0;
	while (liste[i])
		free(liste[i++]);
	free(liste);
	return (1);
}

int	ft_was(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i = 1;
	while (str[i])
	{
		if (str[i] == '-')
		{
			if (!(str[i + 1] >= '0' && str[i + 1] <= '9'))
				return (0);
			if (str[i - 1] != ' ')
				return (0);
		}
		i++;
	}
	return (1);
}

void	parser(char *liste)
{
	t_pile	*pile;
	t_pile	*noeud;
	char	**tab;
	int		i;
	int		size;

	i = 0;
	tab = ft_split(liste, ' ');
	pile = ft_lstnew(ft_atoi(tab[i]));
	noeud = pile;
	while (tab[++i])
	{
		pile->next = ft_lstnew(ft_atoi(tab[i]));
		pile->next->prev = pile;
		pile = pile->next;
	}
	size = ft_lst_size(noeud);
	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	if (!ft_is_sorted(noeud))
		ft_normalize(&noeud, size);
	else
		free_pile(&noeud);
}
