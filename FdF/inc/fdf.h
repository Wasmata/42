/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmaata <wasmaata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 15:03:03 by wasmaata          #+#    #+#             */
/*   Updated: 2025/04/28 19:52:22 by wasmaata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"
# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>

typedef struct s_map
{
	int		**map;
	int		x;
	int		y;
}	t_map;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_map	map;
}	t_data;

typedef struct s_bresenham
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
}	t_bresenham;

typedef struct s_point
{
	int	x0;
	int	y0;
	int	x1;
	int	y1;
}	t_point;

int		parse(char *file, t_map *map);
void	free_tab(char **tab);
int		ft_count_words(char **tab);
int		ft_count_line(int fd);
int		is_fdf(char	*str);
void	draw_map(t_data *data);
void	draw_line(t_data *data, t_point p);
void	project(int *x, int *y, int z);

#endif
