/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmaata <wasmaata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 20:50:06 by wasmaata          #+#    #+#             */
/*   Updated: 2025/04/28 17:46:32 by wasmaata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	ft_count_words(char	**tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	ft_count_line(int fd)
{
	int		len;
	char	*line;

	len = 0;
	line = get_next_line(fd);
	while (line)
	{
		len++;
		free(line);
		line = get_next_line(fd);
	}
	return (len);
}

int	is_fdf(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (!(str[i - 1] == 'f' && str[i - 2] == 'd'
			&& str[i - 3] == 'f' && str[i - 4] == '.'))
		return (0);
	return (1);
}

static void	fill_map(int fd, t_map *map)
{
	char	*line;
	char	**tab;
	int		i;
	int		j;

	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		tab = ft_split(line, ' ');
		map->x = ft_count_words(tab);
		map->map[i] = malloc(sizeof(int) * map->x);
		j = 0;
		while (j < map->x)
		{
			map->map[i][j] = ft_atoi(tab[j]);
			j++;
		}
		free_tab(tab);
		free(line);
		line = get_next_line(fd);
		i++;
	}
}

int	parse(char *file, t_map *map)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	map->y = ft_count_line(fd);
	map->map = malloc(sizeof(int *) * map->y);
	close(fd);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	fill_map(fd, map);
	close(fd);
	return (1);
}
