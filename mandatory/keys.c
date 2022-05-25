/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urycherd <urycherd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:31:54 by urycherd          #+#    #+#             */
/*   Updated: 2022/05/10 18:23:27 by urycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	game_over(t_game **data)
{
	if ((*data)->current_score == (*data)->max_score)
	{
		(*data)->game_over = 1;
		write(1, "\nYOU WIN\n", 9);
		clean_exit(data);
	}
}

static void	item_collect(t_game **data, int x, int y)
{
	(*data)->current_score++;
	draw_floor(*data, x, y);
	(*data)->map_data[y][x] = '0';
}

static void	ft_moving_up_down(t_game **data, int a)
{
	int	old_y;
	int	new_y;
	int	x;

	old_y = (*data)->player_position_y;
	new_y = (*data)->player_position_y + a;
	x = (*data)->player_position_x;
	if ((*data)->map_data[new_y][x] == '1')
		return ;
	if ((*data)->map_data[new_y][x] == 'E')
	{
		game_over(data);
		return ;
	}
	if ((*data)->map_data[new_y][x] == 'C')
		item_collect(data, x, new_y);
	draw_player(*data, x, new_y);
	(*data)->map_data[new_y][x] = 'P';
	(*data)->player_position_y = new_y;
	draw_floor(*data, x, old_y);
	(*data)->map_data[old_y][x] = '0';
	step_counter(data);
}

static void	ft_moving_left_right(t_game **data, int a)
{
	int	old_x;
	int	new_x;
	int	y;

	old_x = (*data)->player_position_x;
	new_x = (*data)->player_position_x + a;
	y = (*data)->player_position_y;
	if ((*data)->map_data[y][new_x] == '1')
		return ;
	if ((*data)->map_data[y][new_x] == 'E')
	{
		game_over(data);
		return ;
	}
	if ((*data)->map_data[y][new_x] == 'C')
		item_collect(data, new_x, y);
	draw_player(*data, new_x, y);
	(*data)->map_data[y][new_x] = 'P';
	(*data)->player_position_x = new_x;
	draw_floor(*data, old_x, y);
	(*data)->map_data[y][old_x] = '0';
	step_counter(data);
}

int	key_hook(int keysym, t_game **data)
{
	if (keysym == 13)
		ft_moving_up_down(data, -1);
	if (keysym == 1)
		ft_moving_up_down(data, 1);
	else if (keysym == 0)
		ft_moving_left_right(data, -1);
	else if (keysym == 2)
		ft_moving_left_right(data, 1);
	if (keysym == 53)
		clean_exit(data);
	return (0);
}
