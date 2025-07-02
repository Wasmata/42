/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmaata <wasmaata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 12:28:04 by enzgonca          #+#    #+#             */
/*   Updated: 2025/07/02 01:30:53 by wasmaata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_pwd(int ac)
{
	char	*cwd;

	cwd = malloc(4096);
	if (ac > 3)
		printf("echo : too many arguments\n");
	if (ac >= 1 && getcwd(cwd, 4096) != 0)
		return (cwd);
	else if (ac == 1)
		printf("Error pwd\n");
	return (NULL);
}

int	pwd_case(int ac)
{
	char	*cwd;

	cwd = get_pwd(ac);
	if (!cwd)
		return (1);
	printf("%s\n", cwd);
	free(cwd);
	return (0);
}

void	get_env(char **env, int ac)
{
	int		i;
	char	*equal;

	i = 0;
	if (ac > 3)
	{
		printf("env: too many arguments\n");
		return ;
	}
	while (env[i])
	{
		equal = ft_strchr(env[i], '=');
		if (equal && ft_strlen(equal + 1))
		{
			ft_putstr_fd(env[i], 1);
			ft_putchar_fd('\n', 1);
		}
		i++;
	}
}

int	get_env_size(char **env)
{
	int	size;

	size = 0;
	while (env[size])
		size++;
	return (size);
}
