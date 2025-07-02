/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmaata <wasmaata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 14:00:12 by wasmaata          #+#    #+#             */
/*   Updated: 2025/07/02 01:00:11 by wasmaata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	wait_all_children(pid_t *pids, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		waitpid(pids[i], NULL, 0);
		i++;
	}
}

void	setup_child_fds(int in_fd, int out_fd)
{
	if (in_fd != 0)
	{
		dup2(in_fd, 0);
		close(in_fd);
	}
	if (out_fd != 1)
	{
		dup2(out_fd, 1);
		close(out_fd);
	}
}

void	launch_child_process(t_token *v, t_index *i, int in_fd, int out_fd)
{
	setup_child_fds(in_fd, out_fd);
	i->tab = ft_quoter(v->str, i);
	i->count = ft_tablen(i->tab);
	ft_selectform(i, i->count);
	exit(0);
}

pid_t	create_pipe_and_fork(t_index *index, int *fd)
{
	pid_t	pid;

	if (index->i < index->cntpipe)
	{
		if (pipe(fd) == -1)
			return (perror("pipe"), -1);
	}
	pid = fork();
	if (pid == -1)
		return (perror("fork"), -1);
	return (pid);
}

void	setup_child_redirections(t_index *index, int *fd)
{
	if (index->stdin != 0)
	{
		dup2(index->stdin, STDIN_FILENO);
		close(index->stdin);
	}
	if (index->i < index->cntpipe)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
	}
}
