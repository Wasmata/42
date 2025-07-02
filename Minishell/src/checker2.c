/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmaata <wasmaata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 00:25:49 by enzgonca          #+#    #+#             */
/*   Updated: 2025/07/02 05:04:05 by wasmaata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_countdblquote(char *input, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (input[i])
	{
		if (input [i] == c)
			count++;
		i++;
	}
	return (count);
}

int	ispipe(t_index *index, char *input)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	index->cntpipe = 0;
	while (input[i])
	{
		if (input[i] == '|')
		{
			index->cntpipe++;
			flag = 1;
		}
		i++;
	}
	if (flag == 0)
		return (1);
	else
		return (0);
}

int	ft_strqlen(char *str, int i)
{
	int	count;

	count = 0;
	while (str[i] && str[i] != '|')
	{
		if (str[i] == '"')
		{
			i++;
			count++;
			while (str[i] != '"')
			{
				i++;
				count++;
			}
		}
		i++;
		count++;
	}
	return (count);
}

t_token	*ft_cutpipe(t_token **vars, t_index *index, t_token *head)
{
	while (index->input[index->i])
	{
		if (index->input[index->i] == '|')
		{
			index->i++;
			index->len = ft_strqlen(index->input, index->i);
			(*vars)->next = malloc(sizeof(t_token));
			(*vars) = (*vars)->next;
			(*vars)->next = NULL;
			(*vars)->str = ft_calloc(sizeof(char), index->len + 1);
			index->j = 0;
		}
		while (index->len && index->input[index->i])
		{
			(*vars)->str[index->j++] = index->input[index->i++];
			index->len--;
		}
		(*vars)->str[index->j] = '\0';
		if (index->flag == 0)
		{
			head = *vars;
			index->flag = 1;
		}
	}
	return (head);
}

int	ft_tablen(char **split)
{
	int	count;

	count = 0;
	while (split[count])
		count++;
	return (count);
}
