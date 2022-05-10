/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_paint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urycherd <urycherd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:27:49 by urycherd          #+#    #+#             */
/*   Updated: 2022/05/10 12:44:15 by urycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_floor(t_game *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->window, data->floor, \
									x * SCALE, y * SCALE);
}

void	draw_wall(t_game *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->window, data->wall, \
									x * SCALE, y * SCALE);
}

void	draw_item(t_game *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->window, data->items, \
									x * SCALE, y * SCALE);
}

void	draw_exit(t_game *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->window, data->exit, \
									x * SCALE, y * SCALE);
}

void	draw_player(t_game *data, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->window, data->player, \
									x * SCALE, y * SCALE);
}
