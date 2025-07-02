/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmaata <wasmaata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 13:59:09 by wasmaata          #+#    #+#             */
/*   Updated: 2025/06/24 21:12:45 by wasmaata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	find_key_index(char *key, char **env)
{
	int		i;
	int		len;

	if (!key || !env)
		return (-1);
	len = ft_strlen(key);
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], key, len) == 0 && env[i][len] == '=')
			return (i);
		i++;
	}
	return (-1);
}

int	env_unset(char *key, char ***env)
{
	int		i;
	int		index_to_remove;
	int		k;
	char	**new_env;

	if (!key || !env || !*env)
		return (1);
	index_to_remove = find_key_index(key, *env);
	if (index_to_remove == -1)
		return (0);
	new_env = calloc_env(*env);
	i = 0;
	k = 0;
	while ((*env)[i])
	{
		if (i != index_to_remove)
			new_env[k++] = (*env)[i];
		else
			free((*env)[i]);
		i++;
	}
	new_env[k] = NULL;
	free(*env);
	*env = new_env;
	return (0);
}

void	env_unset_case(char **tab, int ac, char ***env)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_strchr(tab[i], '='))
			printf("unset: `%s`: not a valid identifier\n", tab[i]);
		else
			env_unset(tab[i], env);
		i++;
	}
}
