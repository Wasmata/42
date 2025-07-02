/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realoc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmaata <wasmaata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 13:24:35 by wasmaata          #+#    #+#             */
/*   Updated: 2025/07/02 00:51:49 by wasmaata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_add_len(char *str, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != c)
			count++;
		i++;
	}
	return (count);
}

char	*ft_realloc_str(char *str, int new_len, char c)
{
	char	*new_str;
	int		i;

	new_str = malloc(sizeof(char) * new_len);
	if (!new_str)
		return (NULL);
	i = 0;
	while (i < new_len)
	{
		if (str[i] != c || str[i] != '\\')
			i++;
		new_str[i] = str[i];
		i++;
	}
	free(str);
	return (new_str);
}

char	**ft_realloc_tab(char **tab, size_t old_len, size_t add_len)
{
	char	**new_tab;
	size_t	i;

	new_tab = malloc((old_len + add_len) * sizeof(char *));
	if (!new_tab)
		return (NULL);
	i = 0;
	while (i < old_len)
	{
		new_tab[i] = tab[i];
		i++;
	}
	while (i < old_len + add_len)
	{
		new_tab[i] = NULL;
		i++;
	}
	free(tab);
	return (new_tab);
}
