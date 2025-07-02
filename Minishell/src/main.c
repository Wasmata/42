/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmaata <wasmaata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 17:09:51 by wasmaata          #+#    #+#             */
/*   Updated: 2025/07/02 05:03:52 by wasmaata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_init(t_token *vars, t_index *index)
{
	vars->str = NULL;
	index->tab = NULL;
	index->input = NULL;
	index->cntpipe = 0;
	index->cnttab = 0;
	index->flag = 0;
	index->i = 0;
	index->j = 0;
	index->k = 0;
	index->len = 0;
	index->stdin = 0;
	index->stdout = 1;
	index->exit_status = 0;
	index->pwd = get_pwd(1);
	index->readline = ft_strjoin(index->pwd, "$ ");
}

void	init_signals_and_env(char **envp, t_index *index)
{
	system("clear");
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, handle_sigquit);
	index->env = copy_env(calloc_env(envp), envp);
}

void	freemain(t_token *vars)
{
	free(vars->str);
	ft_free_tokens(vars);
}

int	main(int ac, char **av, char **envp)
{
	t_token	vars;
	t_index	index;

	(void) ac;
	(void) av;
	init_signals_and_env(envp, &index);
	while (1)
	{
		if (!envp[0])
			return (1);
		ft_init(&vars, &index);
		index.input = readline(index.readline);
		free(index.readline);
		free(index.pwd);
		if (!ft_ctrld(index.input, &index, &vars))
			return (1);
		ft_checker(&vars, &index);
		if (ft_strlen(index.input) > 0)
			add_history(index.input);
		if (index.cntpipe > 0)
			freemain(&vars);
		ft_freetab(index.tab);
	}
	return (0);
}
