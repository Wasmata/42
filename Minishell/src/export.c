/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmaata <wasmaata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:05:43 by wasmaata          #+#    #+#             */
/*   Updated: 2025/07/02 01:30:06 by wasmaata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_valid_identifier(char *str)
{
	int	i;

	i = 0;
	if (!str || (!((str[i] >= 'a' && str[i] <= 'z')
				|| (str[i] >= 'A' && str[i] <= 'Z') || str[i] == '_')))
		return (0);
	i++;
	while (str[i] && str[i] != '=')
	{
		if (!((str[i] >= 'a' && str[i] <= 'z')
				|| (str[i] >= 'A' && str[i] <= 'Z')
				|| (str[i] >= '0' && str[i] <= '9')
				|| str[i] == '_'))
			return (0);
		i++;
	}
	return (1);
}

void	bubble_sort(char **copy, int size)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (ft_strcmp(copy[j], copy[j + 1]) > 0)
			{
				tmp = copy[j];
				copy[j] = copy[j + 1];
				copy[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

char	**sort_env(char **env)
{
	int		i;
	int		size;
	char	**copy;

	size = get_env_size(env);
	copy = malloc(sizeof(char *) * (size + 1));
	i = -1;
	while (++i < size)
		copy[i] = strdup(env[i]);
	copy[size] = NULL;
	bubble_sort(copy, size);
	return (copy);
}

void	print_export(char **env)
{
	int		i;
	char	*equal;

	i = 0;
	env = sort_env(env);
	while (env[i])
	{
		equal = strchr(env[i], '=');
		if (equal && ft_strlen(equal + 1))
		{
			*equal = '\0';
			printf("declare -x %s=\"%s\"\n", env[i], equal + 1);
			*equal = '=';
		}
		else
			printf("declare -x %s\n", env[i]);
		i++;
	}
	i = 0;
	while (env[i])
		free(env[i++]);
	free(env);
}

void	export_case(char **tab, int ac, char ***env)
{
	int		i;
	char	*key;
	char	*value;
	char	*equal_sign;

	if (ac < 2 || !tab[1])
		return (print_export(*env));
	i = 1;
	while (tab[i])
	{
		equal_sign = strchr(tab[i], '=');
		if (equal_sign)
		{
			*equal_sign = '\0';
			key = tab[i];
			value = equal_sign + 1;
			if (is_valid_identifier(key))
				env_set(key, value, env);
			*equal_sign = '=';
		}
		else if (is_valid_identifier(tab[i]))
			env_set(tab[i], NULL, env);
		i++;
	}
}
