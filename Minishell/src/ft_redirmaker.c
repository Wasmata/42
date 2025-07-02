/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirmaker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enzgonca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 13:30:14 by enzgonca          #+#    #+#             */
/*   Updated: 2025/07/01 21:06:48 by enzgonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	jsp(char *str, int *i, int *count)
{
	char	c;

	c = str[*i];
	if (*i > 0 && (str[*i - 1] == ' ' || str[*i - 1] == '\t'))
		(*count)++;
	(*i)++;
	while (str[*i] && str[*i] != c)
		(*i)++;
}

int	ft_cwordredir(char *str)
{
	int		count;
	int		i;

	count = 1;
	i = 0;
	while (str[i])
	{
		if (str[i] == '>' || str[i] == '<')
		{
			count++;
			while (str[i] && (str[i] == '>' || str[i] == '<'))
				i++;
			if (str[i] > 32 && str[i] < 127)
				count++;
		}
		if ((str[i] > 32 && str[i] < 127) && i > 0
			&& (str[i - 1] == ' ' || str[i - 1] == '\t'))
			count++;
		if (str[i] == 34 || str[i] == 39)
			jsp(str, &i, &count);
		i++;
	}
	return (count);
}

int	ft_count_quotes(char *str, int i, char c, t_index *index)
{
	int	qmax;

	qmax = ft_lastq(str, c);
	while (i != qmax)
	{
		i++;
		index->count++;
	}
	return (i);
}

int	ft_count_redirection(char *str, int i, t_index *index)
{
	while ((str[i] == '>' || str[i] == '<') && str[i])
	{
		index->count++;
		i++;
	}
	return (i);
}

int	ft_strlenredirec(char *s, int i, t_index *in)
{
	char	c;

	in->count = 0;
	in->flag = 0;
	while (s[i])
	{
		if (in->flag == 0 && (s[i] == 32 && (s[i - 1] > 32 || s[i - 1] < 127)))
			break ;
		if (in->count == 0 && (s[i] == '>' || s[i] == '<'))
		{
			i = ft_count_redirection(s, i, in);
			break ;
		}
		if ((s[i] == '>' || s[i] == '<') && (s[i - 1] > 32 || s[i - 1] < 127))
			break ;
		else if (in->flag == 0 && (s[i] == 34 || s[i] == 39))
		{
			c = s[i];
			i = ft_count_quotes(s, i, c, in);
		}
		i++;
		in->count++;
	}
	i++;
	return (in->count);
}
