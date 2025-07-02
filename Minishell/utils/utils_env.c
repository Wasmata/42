/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmaata <wasmaata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:53:37 by wasmaata          #+#    #+#             */
/*   Updated: 2025/07/02 14:54:37 by wasmaata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env_add(char *new_var, char ***env)
{
	int		i;
	char	**new_env;

	i = 0;
	while ((*env)[i])
		i++;
	new_env = ft_calloc(sizeof(char *), i + 2);
	if (!new_env)
		return (1);
	i = -1;
	while ((*env)[++i])
		new_env[i] = ft_strdup((*env)[i]);
	new_env[i] = new_var;
	new_env[i + 1] = NULL;
	free(*env);
	*env = new_env;
	return (0);
}

int	env_set(char *key, char *value, char ***env)
{
	int		i;
	int		len;
	char	*new_var;

	if (!key || !env || !(*env))
		return (1);
	len = ft_strlen(key);
	if (value)
		new_var = ft_strjoin3(key, "=", value);
	else
		new_var = ft_strjoin(key, "=");
	if (!new_var)
		return (1);
	i = 0;
	while ((*env)[i])
	{
		if (ft_strncmp((*env)[i], key, len) == 0 && (*env)[i][len] == '=')
		{
			free((*env)[i]);
			(*env)[i] = new_var;
			return (0);
		}
		i++;
	}
	return (env_add(new_var, env));
}

char	*env_get(char *key, char **env)
{
	int		i;
	int		len;

	if (!env)
		return (NULL);
	if (!key)
		env_set(key, ft_strdup("\0"), &env);
	i = 0;
	len = ft_strlen(key);
	while (env[i])
	{
		if (ft_strncmp(env[i], key, len) == 0 && env[i][len] == '=')
			return (env[i] + len + 1);
		i++;
	}
	return (NULL);
}

char	**calloc_env(char **env)
{
	char	**envc;
	int		i;
	int		count;

	if (!env)
		return (NULL);
	count = 0;
	while (env[count])
		count++;
	envc = (char **)ft_calloc(sizeof(char *), count + 1);
	if (!envc)
		return (NULL);
	i = 0;
	while (i < count)
	{
		envc[i] = ft_strdup(env[i]);
		if (!envc[i])
		{
			while (i-- > 0)
				free(envc[i]);
			return (free(envc), NULL);
		}
		i++;
	}
	return (envc);
}

char	**copy_env(char	**envc, char **env)
{
	int		i;
	int		j;
	int		len_shlvl;
	char	*shlvl;

	i = 0;
	j = 0;
	while (env[i] && env[i][j])
	{
		envc[i][j] = env[i][j];
		j++;
		if (!env[i][j])
		{
			i++;
			j = 0;
		}
	}
	len_shlvl = ft_atoi(env_get("SHLVL", env)) + 1;
	shlvl = ft_itoa(len_shlvl);
	env_set("SHLVL", shlvl, &envc);
	return (free(shlvl), envc);
}
