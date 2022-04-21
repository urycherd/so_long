/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urycherd <urycherd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 11:58:28 by urycherd          #+#    #+#             */
/*   Updated: 2022/04/21 14:55:18 by urycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(void)
{
	exit(0);
}

void	make_img(t_game *data, t_V *rn)
{
	int		x;

	data->items = mlx_xpm_file_to_image(rn->mlx, "texture/items.xpm", &x, &x);
	data->wall = mlx_xpm_file_to_image(rn->mlx, "texture/wall.xpm", &x, &x);
	data->floor = mlx_xpm_file_to_image(rn->mlx, "texture/floor.xpm", &x, &x);
	data->player = mlx_xpm_file_to_image(rn->mlx, "texture/player.xpm", &x, &x);
	// mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, \
	// 		int x, int y);
}

void	make_window(t_game *data)
{
	t_V	rend;

	rend.mlx = mlx_init(); // место под окно
	if (rend.mlx == NULL)
		return ;
	rend.window = mlx_new_window(rend.mlx, data->map_x * SCALE, \
									data->map_y * SCALE, "So_long");
	if (rend.mlx == NULL)
	{
		free(rend.window);
		return ;
	}
	make_img(data, &rend);
	make_window(data);
	
	// mlx_hook(rend.window, 17, 0, ft_close(), 0);
	mlx_destroy_window(rend.mlx, rend.window);
	mlx_destroy_display(rend.mlx);
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
