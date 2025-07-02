/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enzgonca <enzgonca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:28:48 by enzgonca          #+#    #+#             */
/*   Updated: 2024/12/17 13:57:19 by enzgonca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_newline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*read_and_stock(int fd, char *buffer)
{
	char	*tmp;
	char	*read_buffer;
	ssize_t	bytes_read;

	read_buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!read_buffer)
		return (NULL);
	while (find_newline(buffer) == -1)
	{
		bytes_read = read(fd, read_buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buffer), free(read_buffer), NULL);
		else if (bytes_read == 0)
			break ;
		read_buffer[bytes_read] = '\0';
		tmp = buffer;
		buffer = ft_strjoin(buffer, read_buffer);
		free(tmp);
		if (!buffer)
			return (free(buffer), NULL);
	}
	free(read_buffer);
	return (buffer);
}

char	*ft_newline_found(char **buffer, int newline_index, char *line)
{
	char	*tmp;
	size_t	len;

	if (!line)
	{
		free(*buffer);
		*buffer = NULL;
		return (NULL);
	}
	len = ft_strlen(*buffer);
	tmp = ft_substr(*buffer, (newline_index + 1), (len - (newline_index + 1)));
	free(*buffer);
	*buffer = tmp;
	return (*buffer);
}

char	*extract_line(char **buffer)
{
	char	*line;
	int		newline_index;

	if (!*buffer || **buffer == '\0')
		return (NULL);
	newline_index = find_newline(*buffer);
	if (newline_index == -1)
	{
		line = ft_substr(*buffer, 0, ft_strlen(*buffer));
		if (!line)
		{
			free(*buffer);
			*buffer = NULL;
			return (NULL);
		}
		free(*buffer);
		*buffer = NULL;
	}
	else
	{
		line = ft_substr(*buffer, 0, newline_index + 1);
		ft_newline_found(buffer, newline_index, line);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_and_stock(fd, buffer);
	if (!buffer)
		return (NULL);
	return (extract_line(&buffer));
}

// int main(void)
// {
// 	int fd;
// 	char *line;
// 	int i = 0;
// 	// Ouvre le fichier "test.txt"
// 	fd = open("test.txt", O_RDONLY);
// 	if (fd == -1)
// 	{
// 		perror("Error opening file");
// 		return (1);
// 	}
// 	// Lire et afficher chaque ligne
// 	while (i < 1)
// 	{
// 		line = get_next_line(fd);
// 		printf("%s", line);  // Affiche la ligne
// 		free(line);  // Libère la mémoire
// 		i++;
// 	}
// 	// Fermer le fichier
// 	close(fd);
// 	return (0);
// }
