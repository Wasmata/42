/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmaata <wasmaata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 14:41:02 by wasmaata          #+#    #+#             */
/*   Updated: 2025/07/01 22:51:31 by wasmaata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_case(char **tab, int ac, t_index *index)
{
	int	i;

	i = 0;
	if (ac == 1)
	{
		index->exit_status = 0;
		exit(index->exit_status);
	}
	while (tab[1][i])
	{
		if (!ft_isdigit(tab[1][i]) && tab[1][i] != '-' && tab[1][i] != '+')
		{
			printf("exit: numeric argument required\n");
			index->exit_status = 2;
			return ;
		}
		i++;
	}
	index->exit_status = ft_atoi(tab[1]);
	exit(index->exit_status);
}
