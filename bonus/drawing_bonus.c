/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urycherd <urycherd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:54:30 by urycherd          #+#    #+#             */
/*   Updated: 2022/05/25 21:27:31 by urycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
	(*data)->idle_img_0 = mlx_xpm_file_to_image((*data)->mlx, \
							"texture/plr1.xpm", &w, &h);
	(*data)->idle_img_1 = mlx_xpm_file_to_image((*data)->mlx, \
							"texture/plr2.xpm", &w, &h);
	(*data)->exit = mlx_xpm_file_to_image((*data)->mlx, \
							"texture/exit.xpm", &w, &h);
	(*data)->enemy_l = mlx_xpm_file_to_image((*data)->mlx, \
							"texture/enemy_l.xpm", &w, &h);
	(*data)->enemy_r = mlx_xpm_file_to_image((*data)->mlx, \
							"texture/enemy_r.xpm", &w, &h);
	(*data)->idle_img_2 = (*data)->player;
}

void	obj_draw(t_game **data, int x, int y)
{
	draw_floor(*data, x, y);
	if ((*data)->map_data[y][x] == 'C')
		draw_item(*data, x, y);
	else if ((*data)->map_data[y][x] == 'P')
		draw_player(*data, x, y);
	else if ((*data)->map_data[y][x] == 'E')
		draw_exit(*data, x, y);
	else if ((*data)->map_data[y][x] == '1')
		draw_wall(*data, x, y);
	else if (x == (*data)->enemypos_x && y == (*data)->enemypos_y \
									&& (*data)->map_data[y][x] == '0')
		draw_img_ptr(*data, (*data)->enemy_l, x, y);
}

void	draw_all_map(t_game **data)
{
	int		x;
	int		y;
	char	**map;

	map = (*data)->map_data;
	y = 0;
	while ((*data)->map_data[y])
	{
		x = 0;
		while ((*data)->map_data[y][x])
		{
			obj_draw(data, x, y);
			x++;
		}
		y++;
	}
	ft_putstr_fd("\nGAME START\n", 2);
}

int	update(t_game **data)
{
	if ((*data)->player == (*data)->idle_img_2
		&& (*data)->framecount >= (*data)->action_frames)
	{
		enemy_patrol(data);
		(*data)->player = (*data)->idle_img_1;
	}
	else if ((*data)->framecount == (*data)->idle_frames)
	{
		(*data)->player = (*data)->idle_img_0;
	}
	else if ((*data)->framecount >= (*data)->idle_frames * 2)
	{
		(*data)->player = (*data)->idle_img_2;
		(*data)->framecount = 0;
	}
	(*data)->framecount += 1;
	draw_floor((*data), (*data)->player_position_x, (*data)->player_position_y);
	draw_player((*data), (*data)->player_position_x, \
								(*data)->player_position_y);
	return (1);
}

void	make_window(t_game **data)
{
	(*data)->mlx = mlx_init();
	if ((*data)->mlx == NULL)
		return ;
	(*data)->window = mlx_new_window((*data)->mlx, ((*data)->map_x) * SCALE, \
									((*data)->map_y) * SCALE, "So_long_bonus");
	if ((*data)->mlx == NULL)
	{
		free((*data)->window);
		return ;
	}
	mlx_hook((*data)->window, 17, 0, clean_exit, data);
	make_img((data));
	draw_all_map((data));
	mlx_key_hook((*data)->window, key_hook, data);
	mlx_loop_hook((*data)->mlx, update, data);
	mlx_loop((*data)->mlx);
	mlx_destroy_window((*data)->mlx, (*data)->window);
	free((*data)->mlx);
}
