/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urycherd <urycherd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 17:48:35 by urycherd          #+#    #+#             */
/*   Updated: 2022/05/25 17:27:21 by urycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	draw_img_ptr(t_game *data, void *img_ptr, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->window, \
							img_ptr, x * SCALE, y * SCALE);
}

void	player_catch(t_game **data, int x, int y)
{
	if ((*data)->map_data[y][x + (*data)->enmvec] == 'P')
	{
		(*data)->game_over = 1;
		write(1, "\nYOU DIED\n", 10);
		clean_exit(data);
	}
}

void	enemy_move(t_game **data, int x, int y)
{
	char	**map;

	map = (*data)->map_data;
	if ((*data)->map_data[y][x + (*data)->enmvec] == '0')
	{
		draw_floor(*data, x, y);
		(*data)->enemypos_x += (*data)->enmvec;
		draw_floor(*data, (*data)->enemypos_x, y);
		if ((*data)->enmvec > 0)
			draw_img_ptr(*data, (*data)->enemy_r, (*data)->enemypos_x, y);
		else if ((*data)->enmvec < 0)
			draw_img_ptr(*data, (*data)->enemy_l, (*data)->enemypos_x, y);
		if ((*data)->map_data[y][x + (*data)->enmvec * 2] != '0' \
					&& (*data)->map_data[y][x + (*data)->enmvec * 2] != 'P')
			(*data)->enmvec *= -1;
	}
}

void	enemy_patrol(t_game **data)
{
	int		x;
	int		y;

	x = (*data)->enemypos_x;
	y = (*data)->enemypos_y;
	player_catch(data, x, y);
	enemy_move(data, x, y);
}
