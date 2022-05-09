/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urycherd <urycherd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:31:54 by urycherd          #+#    #+#             */
/*   Updated: 2022/05/09 19:18:47 by urycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	clean_exit(t_game *data)
{
	// mlx_destroy_window((*map)->mlx, (*map)->win);
	// free_map(map);
	exit(1);
	return (0);
}

void	ft_moving_up_down(t_game *data, int a)
{
	int	old_y;
	int	new_y;
	int	x;

	old_y = data->player_position_y;
	new_y = data->player_position_y + a;
	x = data->player_position_x;
	if (data->map_data[x][new_y] == '1')
		return ;
	else if (data->map_data[x][new_y] == 'E' && data->current_score == data->max_score)
	{
		return ;
	}
	if (data->map_data[x][new_y] == 'C')
	{
		data->current_score++;
		draw_floor(data, x, new_y);
		data->map_data[x][new_y] = '0';
	}
	draw_player(data, x, new_y);
	data->map_data[x][new_y] = 'P';
	data->player_position_y = new_y;
	draw_floor(data, x, old_y);
	data->map_data[x][old_y] = '0';
}

void	ft_moving_left_right(t_game *data, int a)
{
	return ;
}

int	key_hook(int keysym, t_game *data)
{
	if (keysym == 13)
		ft_moving_up_down(data, 1);
	else if (keysym == 1)
		ft_moving_up_down(data, -1);
	else if (keysym == 0)
		ft_moving_left_right(data, -1);
	else if (keysym == 2)
		ft_moving_left_right(data, 1);
	else if (keysym == 53)
		clean_exit(data);
	return (0);
}
