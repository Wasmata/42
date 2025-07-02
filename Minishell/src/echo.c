/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmaata <wasmaata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 17:10:02 by wasmaata          #+#    #+#             */
/*   Updated: 2025/07/01 23:12:03 by wasmaata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	echo_print(char **tab, int i, int newline)
{
	while (tab[i])
	{
		ft_putstr_fd(tab[i], 1);
		if (tab[i + 1])
			ft_putchar_fd(' ', 1);
		i++;
	}
	if (newline)
		ft_putchar_fd('\n', 1);
}

void	echo_case(char **tab)
{
	int	i;
	int	fd;
	int	j;

	fd = 1;
	i = 1;
	if (handle_redirections(tab) == -1)
		return ;
	if (!tab[i])
		ft_putchar_fd('\n', fd);
	else if (tab[i] && ft_strncmp(tab[i], "-n", 2) == 0)
	{
		j = 2;
		while (tab[i][j] == 'n')
			j++;
		if (!tab[i][j] && tab[i + 1])
		{
			i++;
			echo_print(tab, i, 0);
		}
		else if (tab[i][j])
			echo_print(tab, i, 1);
	}
	else if (tab[i] && ft_strncmp(tab[i], "-n", 2))
		echo_print(tab, i, 1);
}
