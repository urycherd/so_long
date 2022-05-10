/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urycherd <urycherd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:54:30 by urycherd          #+#    #+#             */
/*   Updated: 2022/05/10 16:00:59 by urycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	make_img(t_game **data)
{
	int		w;
	int		h;

	(*data)->items = mlx_xpm_file_to_image((*data)->mlx, \
							"texture/items.xpm", &w, &h);
	(*data)->wall = mlx_xpm_file_to_image((*data)->mlx, \
							"texture/wall.xpm", &w, &h);
	(*data)->floor = mlx_xpm_file_to_image((*data)->mlx, \
							"texture/floor.xpm", &w, &h);
	(*data)->player = mlx_xpm_file_to_image((*data)->mlx, \
							"texture/plr.xpm", &w, &h);
	(*data)->exit = mlx_xpm_file_to_image((*data)->mlx, \
							"texture/exit.xpm", &w, &h);
}

void	draw_all_map(t_game **data)
{
	int		x;
	int		y;
	char	**map;

	map = (*data)->map_data;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			draw_floor(*data, x, y);
			if (map[y][x] == 'C')
				draw_item(*data, x, y);
			else if (map[y][x] == 'P')
				draw_player(*data, x, y);
			else if (map[y][x] == 'E')
				draw_exit(*data, x, y);
			else if (map[y][x] == '1')
				draw_wall(*data, x, y);
			x++;
		}
		y++;
	}
	ft_putstr_fd("\nGAME START\n", 2);
}

void	make_window(t_game **data)
{
	(*data)->mlx = mlx_init();
	if ((*data)->mlx == NULL)
		return ;
	(*data)->window = mlx_new_window((*data)->mlx, ((*data)->map_x) * SCALE, \
									((*data)->map_y) * SCALE, "So_long");
	if ((*data)->mlx == NULL)
	{
		free((*data)->window);
		return ;
	}
	make_img((data));
	draw_all_map((data));
	mlx_key_hook((*data)->window, key_hook, data);
	mlx_hook((*data)->window, 17, 0, clean_exit, data);
	mlx_loop((*data)->mlx);
	mlx_destroy_window((*data)->mlx, (*data)->window);
	free((*data)->mlx);
}
