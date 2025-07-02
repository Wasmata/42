/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmaata <wasmaata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:28:40 by wasmaata          #+#    #+#             */
/*   Updated: 2025/05/28 11:47:47 by wasmaata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ch_dir(char *path)
{
	if (chdir(path) == -1)
	{
		perror(path);
		return (1);
	}
	return (0);
}

void	cd_case(char **tab, int ac, char **env)
{
	char	*target_path;
	char	*old_pwd;
	char	*new_pwd;

	if (ac == 2 && ft_strcmp(tab[1], "-") == 0)
	{
		target_path = ft_strdup(env_get("OLDPWD", env));
		printf("%s\n", target_path);
	}
	else if (ac >= 2)
		target_path = ft_strdup(tab[1]);
	else
		target_path = ft_strdup(env_get("HOME", env));
	old_pwd = get_pwd(1);
	env_set("OLDPWD", old_pwd, &env);
	free(old_pwd);
	if (ch_dir(target_path) == 0)
	{
		new_pwd = get_pwd(1);
		env_set("PWD", new_pwd, &env);
		free(new_pwd);
	}
	free(target_path);
}
