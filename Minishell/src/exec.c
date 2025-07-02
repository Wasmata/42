/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmaata <wasmaata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 12:03:51 by wasmaata          #+#    #+#             */
/*   Updated: 2025/07/02 05:11:51 by wasmaata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_builtin_with_redirection(char **tab, t_index *index, int ac)
{
	index->saved_stdin = dup(STDIN_FILENO);
	index->saved_stdout = dup(STDOUT_FILENO);
	if (handle_redirections(tab) == -1)
		return ;
	if (tab[0] && ft_strcmp(tab[0], "cd") == 0)
		cd_case(tab, ac, index->env);
	else if (tab[0] && ft_strcmp(tab[0], "echo") == 0)
		echo_case(tab);
	else if (tab[0] && ft_strcmp(tab[0], "pwd") == 0)
		pwd_case(ac);
	else if (tab[0] && ft_strcmp(tab[0], "env") == 0)
		get_env(index->env, ac);
	else if (tab[0] && ft_strcmp(tab[0], "export") == 0)
		export_case(tab, ac, &index->env);
	else if (tab[0] && ft_strcmp(tab[0], "unset") == 0)
		env_unset_case(tab, ac, &index->env);
	else if (tab[0] && ft_strcmp(tab[0], "exit") == 0)
		exit_case(tab, ac, index);
	else
		imp_exec(tab, index->env);
	dup2(index->saved_stdin, STDIN_FILENO);
	dup2(index->saved_stdout, STDOUT_FILENO);
	close(index->saved_stdin);
	close(index->saved_stdout);
}

void	ft_selectform(t_index *index, int ac)
{
	if (index->tab[0])
		exec_builtin_with_redirection(index->tab, index, ac);
}
