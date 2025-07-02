/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enzgonca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:55:40 by enzgonca          #+#    #+#             */
/*   Updated: 2025/07/02 01:55:09 by enzgonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	unclosedquote(char *str)
{
	int		i;
	char	quote;
	int		qmax;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			quote = str[i];
			qmax = ft_lastq(str, quote);
			if (i == qmax)
				return (0);
			while (str[i] && i != qmax)
				i++;
		}
		i++;
	}
	return (1);
}

void	*ft_realloc(void *ptr, size_t old_size, size_t new_size)
{
	void	*new_ptr;
	size_t	copy_size;

	if (!ptr)
		return (malloc(new_size));
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = malloc(new_size);
	if (!new_ptr)
		return (NULL);
	copy_size = old_size;
	if (new_size < old_size)
		copy_size = new_size;
	ft_memcpy(new_ptr, ptr, copy_size);
	free(ptr);
	return (new_ptr);
}

void	wassimo(t_index *index, char *target, int len, char **tab)
{
	int	k;

	index->l = ft_strlen(target);
	index->l += (index->len - (len + 1));
	tab[index->k] = ft_realloc(tab[index->k], index->len + 1, index->l + 1);
	if (!tab[index->k])
		return ;
	k = 0;
	while (target[k])
		tab[index->k][index->j++] = target[k++];
	index->i += len + 1;
	index->len = index->l;
}

void	ft_inshallah(char **tab, t_index *index)
{
	char	*target;

	target = ft_itoa(index->exit_status);
	if (!target)
		return ;
	wassimo(index, target, 1, tab);
	free(target);
}
