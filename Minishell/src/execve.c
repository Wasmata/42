/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmaata <wasmaata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 11:54:40 by wasmaata          #+#    #+#             */
/*   Updated: 2025/07/02 14:49:08 by wasmaata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_get_full_path(char **tab, char **env)
{
	char	**path;
	char	*full_path;
	char	*temp;
	int		i;

	i = 0;
	path = ft_split(env_get("PATH", env), ':');
	full_path = NULL;
	while (path[i])
	{
		temp = ft_strjoin3(path[i], "/", tab[0]);
		if (full_path)
			free(full_path);
		full_path = temp;
		if (access(full_path, X_OK) == 0)
			break ;
		free(path[i]);
		i++;
	}
	if (full_path && access(full_path, X_OK) == 0)
		return (full_path);
	return (free(path), free(full_path), NULL);
}

int	imp_exec(char **tab, char **env)
{
	int		pid;
	char	*full_path;
	int		status;

	pid = fork();
	if (pid == 0)
	{
		if (handle_redirections(tab) == -1)
			exit(EXIT_FAILURE);
		if (ft_strncmp(tab[0], "./", 2) == 0 || ft_strncmp(tab[0], "/", 1) == 0)
			full_path = tab[0];
		else
			full_path = ft_get_full_path(tab, env);
		if (!full_path)
		{
			fprintf(stderr, "%s: command not found\n", tab[0]);
			exit(EXIT_FAILURE);
		}
		execve(full_path, tab, env);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else if (pid > 0)
		return (waitpid(pid, &status, 0), WEXITSTATUS(status));
	return (perror("fork"), -1);
}
