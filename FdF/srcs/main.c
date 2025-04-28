/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wasmaata <wasmaata@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 19:42:34 by wasmaata          #+#    #+#             */
/*   Updated: 2025/04/28 17:43:42 by wasmaata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	free_tab(char	**tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	ft_esc(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keycode == 65307)
		mlx_loop_end(data->mlx_ptr);
	return (0);
}

int	ft_close(t_data *param)
{
	t_data	*data;

	data = (t_data *)param;
	mlx_loop_end(data->mlx_ptr);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;
	int		i;

	i = 0;
	if (argc != 2 || !is_fdf(argv[1]) || !parse(argv[1], &data.map))
		return (1);
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (1);
	data.win_ptr = mlx_new_window(data.mlx_ptr, 800, 600, "fdf");
	if (!data.win_ptr)
		return (1);
	draw_map(&data);
	mlx_key_hook(data.win_ptr, ft_esc, &data);
	mlx_hook(data.win_ptr, 17, 0, ft_close, &data);
	mlx_loop(data.mlx_ptr);
	while (i < data.map.y)
		free(data.map.map[i++]);
	free(data.map.map);
	if (data.win_ptr)
		mlx_destroy_window(data.mlx_ptr, data.win_ptr);
	if (data.mlx_ptr)
		mlx_destroy_display(data.mlx_ptr);
	return (free(data.mlx_ptr), 0);
}
