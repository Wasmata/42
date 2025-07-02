/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmaata <wasmaata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 00:02:05 by wasmaata          #+#    #+#             */
/*   Updated: 2025/07/02 01:22:46 by wasmaata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	handle_output_redirection(char **tab, int *fd_out, int i)
{
	if (*fd_out != -1)
		close(*fd_out);
	*fd_out = open(tab[i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (*fd_out < 0)
	{
		perror(tab[i + 1]);
		return (-1);
	}
	cleanup_tab(tab, i);
	return (0);
}

int	handle_append_redirection(char **tab, int *fd_out, int i)
{
	if (*fd_out != -1)
		close(*fd_out);
	*fd_out = open(tab[i + 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (*fd_out < 0)
	{
		perror(tab[i + 1]);
		return (-1);
	}
	cleanup_tab(tab, i);
	return (0);
}

int	handle_input_redirection(char **tab, int *fd_in, int i)
{
	if (*fd_in != -1)
		close(*fd_in);
	*fd_in = open(tab[i + 1], O_RDONLY);
	if (*fd_in < 0)
	{
		perror(tab[i + 1]);
		return (-1);
	}
	cleanup_tab(tab, i);
	return (0);
}

int	handle_heredoc_redirection(char **tab, int *fd_heredoc, int i)
{
	if (*fd_heredoc != -1)
		close(*fd_heredoc);
	*fd_heredoc = here_document(tab[i + 1]);
	if (*fd_heredoc < 0)
		return (-1);
	cleanup_tab(tab, i);
	return (0);
}

int	apply_redirections(int fd_in, int fd_out, int fd_heredoc)
{
	if (fd_heredoc != -1)
	{
		if (dup2(fd_heredoc, STDIN_FILENO) == -1)
			return (perror("dup2"), -1);
		close(fd_heredoc);
	}
	else if (fd_in != -1)
	{
		if (dup2(fd_in, STDIN_FILENO) == -1)
			return (perror("dup2"), -1);
		close(fd_in);
	}
	if (fd_out != -1)
	{
		if (dup2(fd_out, STDOUT_FILENO) == -1)
			return (perror("dup2"), -1);
		close(fd_out);
	}
	return (0);
}
