/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quoter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enzgonca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/14 11:39:52 by zob               #+#    #+#             */
/*   Updated: 2025/07/01 21:00:28 by enzgonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_hdquote(char **tab, char *str, t_index *index)
{
	char	c;
	int		qmax;

	c = str[index->i];
	qmax = ft_lastq(str, c);
	if (index->i == qmax)
	{
		ft_hdmaker(str, index->i, str[index->i], index);
		index->flag = 1;
	}
	else
	{
		while (index->i != qmax && str[index->i])
		{
			if (str[index->i] == c)
				index->i++;
			else
				tab[index->k][index->j++] = str[index->i++];
		}
		index->i++;
	}
}

void	isexpand(char **tab, char *str, t_index *index)
{
	int		len;
	int		i;
	int		k;
	char	*cpy;
	char	*target;

	i = index->i + 1;
	if (str[i] == '?')
		return (ft_inshallah(tab, index));
	k = 0;
	len = alphastrlen(str, i);
	cpy = malloc(sizeof(char) * (len + 1));
	if (!cpy)
		return ;
	while (k < len && str[i])
		cpy[k++] = str[i++];
	cpy[k] = '\0';
	target = env_get(cpy, index->env);
	free(cpy);
	if (!target)
	{
		index->i += len + 1;
		return ;
	}
	wassimo(index, target, len, tab);
}

void	gihadito(char *str, char **tab, t_index *index)
{
	while (str[index->i] && str[index->i] != ' ' && str[index->i] != '\t'
		&& str[index->i] != '\n')
	{
		if (str[index->i] == '$')
			isexpand(tab, str, index);
		if (str[index->i] == 34 || str[index->i] == 39)
			ft_hdquote(tab, str, index);
		if (str[index->i] == '\\')
			index->i++;
		if (str[index->i] == '>' || str[index->i] == '<')
		{
			index->j = 0;
			while (str[index->i] && (str[index->i] == '>'
					|| str[index->i] == '<'))
				tab[index->k][index->j++] = str[index->i++];
			break ;
		}
		if (str[index->i] != '$' && str[index->i])
			tab[index->k][index->j++] = str[index->i++];
		if (str[index->i] == '>' || str[index->i] == '<')
			break ;
	}
}

char	**ft_cutquoter(char **tab, char *str, t_index *index)
{
	while (str[index->i])
	{
		index->len = ft_strlenredirec(str, index->i, index);
		index->j = 0;
		tab[index->k] = ft_calloc(sizeof(char), (index->len + 1));
		if (!tab[index->k])
			return (NULL);
		if (str[index->i] && str[index->i] != ' ' && str[index->i] != '\t'
			&& str[index->i] != '\n')
			gihadito(str, tab, index);
		while (str[index->i] && (str[index->i] == ' ' || str[index->i] == '\t'
				|| str[index->i] == '\n'))
			index->i++;
		tab[index->k][index->j] = '\0';
		index->k++;
	}
	return (tab);
}

char	**ft_quoter(char *str, t_index *index)
{
	char	**tab;
	int		cword;

	index->i = 0;
	index->k = 0;
	index->flag = 0;
	index->len = 0;
	cword = ft_cwordredir(str);
	tab = ft_calloc(sizeof(char *), (cword + 1));
	if (!tab)
		return (NULL);
	while (str[index->i] == ' ' || str[index->i] == '\t'
		|| str[index->i] == '\n')
		index->i++;
	tab = ft_cutquoter(tab, str, index);
	tab[index->k] = NULL;
	return (tab);
}
