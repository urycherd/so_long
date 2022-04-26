/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urycherd <urycherd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 11:58:28 by urycherd          #+#    #+#             */
/*   Updated: 2022/04/25 18:02:44 by urycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	make_img(t_game *data)
{
	int		w;
	int		h;

	data->items = mlx_xpm_file_to_image(data->mlx, "texture/items.xpm", &w, &h);
	data->wall = mlx_xpm_file_to_image(data->mlx, "texture/wall.xpm", &w, &h);
	data->floor = mlx_xpm_file_to_image(data->mlx, "texture/floor.xpm", &w, &h);
	data->player = mlx_xpm_file_to_image(data->mlx, "texture/plr.xpm", &w, &h);
	data->exit = mlx_xpm_file_to_image(data->mlx, "texture/exit.xpm", &w, &h);
}

// void	draw_obj(t_game *data, void *obj, char c)
// {
// 	int		x;
// 	int		y;
// 	char	**map;

// 	x = 0;
// 	y = 0;
// 	map = data->map_data;
// 	while (map[y])
// 	{
// 		while (map[y][x])
// 		{
// 			if (map[y][x] == c)
// 			{
// 				mlx_put_image_to_window(data->mlx, data->window, obj, \
// 						x, y);
// 			}
// 			x++;
// 		}
// 		y++;
// 	}
// }

void	draw_all_map(t_game *data) // либо draw_all_map и файл obj_paint.c, либо функции draw_obj и all_map
{
	int		x;
	int		y;
	char	**map;

	x = 0;
	y = 0;
	map = data->map_data;
	while (map[y])
	{
		while (map[y][x])
		{
			draw_floor(data, x, y);
			if (map[y][x] == 'C')
				draw_item(data, x, y);
			else if (map[y][x] == 'P')
				draw_player(data, x, y);
			else if (map[y][x] == 'E')
				draw_exit(data, x, y);
			else if (map[y][x] == '1')
				draw_wall(data, x, y);
			x++;
		}
		y++;
	}
}

// void	all_map(t_game *data)
// {
	// draw_obj(data, data->floor, '0');
	// draw_obj(data, data->floor, '1');
	// draw_obj(data, data->floor, 'E');
	// draw_obj(data, data->floor, 'P');
	// draw_obj(data, data->floor, 'C');
	// draw_obj(data, data->player, 'P');
	// draw_obj(data, data->items, 'C');
	// draw_obj(data, data->wall, '1');
	// draw_obj(data, data->exit, 'E');
// }

void	make_window(t_game *data)
{
	data->mlx = mlx_init(); // место под окно
	if (data->mlx == NULL)
		return ;
	data->window = mlx_new_window(data->mlx, data->map_x * 100, \
									data->map_y * 100, "So_long");
	if (data->mlx == NULL)
	{
		free(data->window);
		return ;
	}
	make_img(data);
	// all_map(data);
	draw_all_map(data); //переписанная функция - надо потестить как работает
	mlx_loop(data->mlx);
	// mlx_hook(rend.window, 17, 0, ft_close(), 0);//анимация
	mlx_destroy_window(data->mlx, data->window);
	// mlx_destroy_display(data->mlx);
	free(data->mlx);
}

// void	make_game(t_game *data)
// {
// 	mlx_put_image_to_window();
// }

int	main(int argc, char **argv)
{
	t_game	data;

	if (argc == 2)
	{
		map_parce(argv[1], &data);
		make_window(&data);
		// make_game(&data);
	}
	return (0);
}
