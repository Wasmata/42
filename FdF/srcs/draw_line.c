/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmaata <wasmaata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 17:36:49 by wasmaata          #+#    #+#             */
/*   Updated: 2025/04/28 20:36:09 by wasmaata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

int	abs_val(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

void	init_bresenham(t_bresenham *b, t_point p)
{
	b->dx = abs_val(p.x1 - p.x0);
	b->dy = -abs_val(p.y1 - p.y0);
	if (p.x0 < p.x1)
		b->sx = 1;
	else
		b->sx = -1;
	if (p.y0 < p.y1)
		b->sy = 1;
	else
		b->sy = -1;
	b->err = b->dx + b->dy;
}

void	plot_line(t_data *data, t_bresenham b, t_point p)
{
	int	e2;
	int	x;
	int	y;

	x = p.x0;
	y = p.y0;
	while (1)
	{
		mlx_pixel_put(data->mlx_ptr, data->win_ptr, x, y, 0xFFFFFF);
		if (x == p.x1 && y == p.y1)
			break ;
		e2 = 2 * b.err;
		if (e2 >= b.dy)
		{
			b.err += b.dy;
			x += b.sx;
		}
		if (e2 <= b.dx)
		{
			b.err += b.dx;
			y += b.sy;
		}
	}
}

void	draw_line(t_data *data, t_point p)
{
	t_bresenham	b;

	init_bresenham(&b, p);
	plot_line(data, b, p);
}
