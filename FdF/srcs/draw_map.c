/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmaata <wasmaata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:36:20 by wasmaata          #+#    #+#             */
/*   Updated: 2025/04/28 18:05:05 by wasmaata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	project(int *x, int *y, int z)
{
	int		previous_x;
	int		previous_y;
	double	angle;

	angle = 0.523599;
	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(angle);
	*y = (previous_x + previous_y) * sin(angle) - z;
}

void	draw_to_right(t_data *data, int x, int y)
{
	t_point	p;

	p.x0 = x * 20;
	p.y0 = y * 20;
	p.x1 = (x + 1) * 20;
	p.y1 = y * 20;
	project(&p.x0, &p.y0, data->map.map[y][x]);
	project(&p.x1, &p.y1, data->map.map[y][x + 1]);
	p.x0 += 300;
	p.y0 += 200;
	p.x1 += 300;
	p.y1 += 200;
	draw_line(data, p);
}

void	draw_to_down(t_data *data, int x, int y)
{
	t_point	p;

	p.x0 = x * 20;
	p.y0 = y * 20;
	p.x1 = x * 20;
	p.y1 = (y + 1) * 20;
	project(&p.x0, &p.y0, data->map.map[y][x]);
	project(&p.x1, &p.y1, data->map.map[y + 1][x]);
	p.x0 += 300;
	p.y0 += 200;
	p.x1 += 300;
	p.y1 += 200;
	draw_line(data, p);
}

void	draw_point(t_data *data, int x, int y)
{
	if (x < data->map.x - 1)
		draw_to_right(data, x, y);
	if (y < data->map.y - 1)
		draw_to_down(data, x, y);
}

void	draw_map(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->map.y)
	{
		x = 0;
		while (x < data->map.x)
		{
			draw_point(data, x, y);
			x++;
		}
		y++;
	}
}
