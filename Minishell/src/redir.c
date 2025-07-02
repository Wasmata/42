/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmaata <wasmaata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 14:34:58 by wasmaata          #+#    #+#             */
/*   Updated: 2025/07/02 01:23:14 by wasmaata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cleanup_tab(char **tab, int pos)
{
	int	i;

	free(tab[pos]);
	free(tab[pos + 1]);
	i = pos;
	while (tab[i + 2])
	{
		tab[i] = tab[i + 2];
		i++;
	}
	tab[i] = NULL;
	tab[i + 1] = NULL;
}

int	here_document(const char *delimiter)
{
	int		pipefd[2];
	char	*line;
	size_t	len;
	ssize_t	read_bytes;

	line = NULL;
	len = 0;
	if (pipe(pipefd) == -1)
		return (perror("pipe"), -1);
	while (1)
	{
		write(STDOUT_FILENO, "> ", 2);
		read_bytes = getline(&line, &len, stdin);
		if (read_bytes == -1)
			break ;
		if (line[read_bytes - 1] == '\n')
			line[read_bytes - 1] = '\0';
		if (strcmp(line, delimiter) == 0)
			break ;
		write(pipefd[1], line, strlen(line));
		write(pipefd[1], "\n", 1);
	}
	return (free(line), close(pipefd[1]), pipefd[0]);
}

int	process_output_redirections(char **tab, int *fd_out)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (ft_strcmp(tab[i], ">") == 0 && tab[i + 1])
		{
			if (handle_output_redirection(tab, fd_out, i) == -1)
				return (-1);
		}
		else if (ft_strcmp(tab[i], ">>") == 0 && tab[i + 1])
		{
			if (handle_append_redirection(tab, fd_out, i) == -1)
				return (-1);
		}
		i++;
	}
	return (0);
}

int	process_input_redirections(char **tab, int *fd_in, int *fd_heredoc)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (ft_strcmp(tab[i], "<") == 0 && tab[i + 1])
		{
			if (handle_input_redirection(tab, fd_in, i) == -1)
				return (-1);
		}
		else if (ft_strcmp(tab[i], "<<") == 0 && tab[i + 1])
		{
			if (handle_heredoc_redirection(tab, fd_heredoc, i) == -1)
				return (-1);
		}
		i++;
	}
	return (0);
}

int	handle_redirections(char **tab)
{
	int	fd_in;
	int	fd_out;
	int	fd_heredoc;

	fd_in = -1;
	fd_out = -1;
	fd_heredoc = -1;
	if (process_output_redirections(tab, &fd_out) == -1)
		return (-1);
	if (process_input_redirections(tab, &fd_in, &fd_heredoc) == -1)
		return (-1);
	return (apply_redirections(fd_in, fd_out, fd_heredoc));
}
