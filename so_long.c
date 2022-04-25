/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urycherd <urycherd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 11:58:28 by urycherd          #+#    #+#             */
/*   Updated: 2022/04/25 17:36:00 by urycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(void)
{
	exit(0);
}

void	make_img(t_game *data, t_V *rn)
{
	int		w;
	int		h;

	data->items = mlx_xpm_file_to_image(rn->mlx, "texture/items.xpm", &w, &h);
	data->wall = mlx_xpm_file_to_image(rn->mlx, "texture/wall.xpm", &w, &h);
	data->floor = mlx_xpm_file_to_image(rn->mlx, "texture/floor.xpm", &w, &h);
	data->player = mlx_xpm_file_to_image(rn->mlx, "texture/player.xpm", &w, &h);
	data->exit = mlx_xpm_file_to_image(rn->mlx, "texture/exit.xpm", &w, &h);
}

void	draw_obj(t_game *data, t_V *rn, void *obj, char c)
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
			if (map[y][x] == c)
			{
				mlx_put_image_to_window(rn->mlx, rn->window, obj, \
						x, y);
			}
			x++;
		}
		y++;
	}
}

void	draw_img(t_game *data, t_V *rn)
{
	draw_obj(data, rn, data->floor, '1');
	draw_obj(data, rn, data->wall, '1');
	draw_obj(data, rn, data->floor, '0');
	draw_obj(data, rn, data->floor, 'E');
	draw_obj(data, rn, data->exit, 'E');
	draw_obj(data, rn, data->floor, 'P');
	draw_obj(data, rn, data->player, 'P');
	draw_obj(data, rn, data->floor, 'C');
	draw_obj(data, rn, data->items, 'C');
}

void	make_window(t_game *data)
{

	// void	*mlx;
	// void	*mlx_win;

	// mlx = mlx_init();
	// mlx_win = mlx_new_window(mlx, 500, 300, "so_long");
	// mlx_loop(mlx);



	t_V	rend;

	rend.mlx = mlx_init(); // место под окно
	if (rend.mlx == NULL)
		return ;
	rend.window = mlx_new_window(rend.mlx, data->map_x * 100, \
									data->map_y * 100, "So_long");
	if (rend.mlx == NULL)
	{
		free(rend.window);
		return ;
	}
	make_img(data, &rend);
	draw_img(data, &rend);
	mlx_loop(rend.mlx);
	// mlx_hook(rend.window, 17, 0, ft_close(), 0);//анимация
	mlx_destroy_window(rend.mlx, rend.window);
	// mlx_destroy_display(rend.mlx);
	free(rend.mlx);
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
