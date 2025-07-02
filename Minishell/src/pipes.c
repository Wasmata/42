/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmaata <wasmaata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 13:58:48 by wasmaata          #+#    #+#             */
/*   Updated: 2025/07/02 05:00:28 by wasmaata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

pid_t	prepare_pipe_iteration(t_token *vars, t_index *index, int *fd)
{
	pid_t	pid;

	pid = create_pipe_and_fork(index, fd);
	if (pid == -1)
		return (-1);
	if (pid == 0)
	{
		setup_child_redirections(index, fd);
		launch_child_process(vars, index, STDIN_FILENO, STDOUT_FILENO);
		exit(0);
	}
	if (index->stdin != 0)
		close(index->stdin);
	if (index->i < index->cntpipe)
	{
		close(fd[1]);
		index->stdin = fd[0];
	}
	return (pid);
}

int	ft_pipechecker(t_token *vars, t_index *index)
{
	int		fd[2];
	pid_t	pids[100000];

	index->i = 0;
	index->stdin = 0;
	while (index->i <= index->cntpipe && vars)
	{
		pids[index->i] = prepare_pipe_iteration(vars, index, fd);
		if (pids[index->i] == -1)
			return (1);
		vars = vars->next;
		index->i++;
	}
	wait_all_children(pids, index->i);
	return (0);
}
