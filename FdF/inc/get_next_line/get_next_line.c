/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmaata <wasmaata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 01:28:16 by wasmaata          #+#    #+#             */
/*   Updated: 2025/04/28 18:06:56 by wasmaata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../libft/libft.h"

char	*ft_get_line(int fd)
{
	int		bytes_read;
	char	*r_read;
	char	*line_temp;

	line_temp = NULL;
	bytes_read = 1;
	r_read = ft_calloc((BUFFER_SIZE + 1), 1);
	if (!r_read)
		return (NULL);
	while (bytes_read != 0)
	{
		bytes_read = read(fd, r_read, BUFFER_SIZE);
		if (bytes_read == 0)
			break ;
		if (bytes_read == -1)
			return (free(r_read), NULL);
		r_read[bytes_read] = '\0';
		line_temp = ft_strjoinn(line_temp, r_read);
		if (ft_strchr(line_temp, '\n'))
			break ;
	}
	free(r_read);
	if (!line_temp || line_temp[0] == '\0')
		return (free(line_temp), NULL);
	return (line_temp);
}

char	*ft_get_static(char *line_temp, char *line_static)
{
	char	*line_return;
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (line_temp[len] != '\n' && line_temp[len])
		len++;
	line_return = ft_calloc(len + 2, 1);
	if (line_temp[len] == '\n')
		len++;
	while (line_temp[i] && line_temp[len])
	{
		line_static[i] = line_temp[len++];
		i++;
	}
	i = 0;
	while (line_temp[i] != '\n')
	{
		line_return[i] = line_temp[i];
		i++;
	}
	line_return[i] = '\0';
	return (line_return);
}

char	*ft_manage(int fd, char *line_static)
{
	char		*line_temp;
	char		*tmp;

	line_temp = ft_get_line(fd);
	if (line_static && line_temp)
	{
		tmp = ft_strdupp(line_temp);
		free(line_temp);
		line_temp = ft_strjoinn(ft_strdupp(line_static), tmp);
		free(tmp);
	}
	else if (!line_temp && line_static)
		line_temp = ft_strdupp(line_static);
	return (line_temp);
}

char	*get_next_line(int fd)
{
	char		*line_temp;
	char		*line_return;
	static char	*line_static;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line_temp = ft_manage(fd, line_static);
	if (line_temp && ft_strchr(line_temp, '\n'))
	{
		free(line_static);
		line_static = ft_calloc(ft_strlen(line_temp) + 2, 1);
		line_return = ft_get_static(line_temp, line_static);
		line_return[ft_strlen(line_return)] = '\n';
		return (free(line_temp), line_return);
	}
	else if (line_temp && line_temp[0] != '\0')
	{
		free(line_static);
		line_static = NULL;
		return (line_temp);
	}
	free(line_static);
	line_static = NULL;
	return (free(line_temp), NULL);
}
