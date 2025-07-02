/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmaata <wasmaata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 10:48:57 by enzgonca          #+#    #+#             */
/*   Updated: 2025/07/02 04:58:19 by wasmaata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_splitpipe(t_token **vars, t_index *index)
{
	t_token	*head;

	head = NULL;
	index->i = 0;
	index->j = 0;
	index->len = ft_strqlen(index->input, index->i);
	(*vars)->str = malloc(sizeof(char) * index->len + 1);
	head = ft_cutpipe(vars, index, head);
	*vars = head;
	if (!ft_pipechecker(*vars, index))
		return (0);
	return (1);
}

int	ft_parsepipe(t_token **vars, t_index *index)
{
	if (!ft_splitpipe(vars, index))
		return (0);
	return (1);
}

void	ft_parseother(t_index *index)
{
	int	count;

	index->tab = ft_quoter(index->input, index);
	count = ft_tablen(index->tab);
	ft_selectform(index, count);
}

int	ft_pipeok(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (str[i])
	{
		if (str[i] == '|' && str[i + 1] == '|')
			return (perror("bash"), 0);
		else if (str[i] > 32 && str[i] < 123)
			flag = 1;
		else if (str[i] == '|' && flag == 1)
			flag = 0;
		else if (str[i] == '|' && flag == 0)
			return (perror("bash"), 0);
		if ((!str[i + 1] && flag == 0))
			return (perror("bash"), 0);
		i++;
	}
	return (1);
}

void	ft_checker(t_token *vars, t_index *index)
{
	if (unclosedquote(index->input))
	{
		if (!ispipe(index, index->input))
		{
			if (ft_pipeok(index->input))
				ft_parsepipe(&vars, index);
		}
		else
			ft_parseother(index);
	}
	else
		perror("Quote aren't closed");
}
