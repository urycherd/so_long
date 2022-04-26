/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urycherd <urycherd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:46:55 by urycherd          #+#    #+#             */
/*   Updated: 2022/04/25 18:00:35 by urycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
// # include <mlx.h>
# include "mlx/mlx.h"
# include "libft/libft.h"

# define SCALE 50

//delete them

#include <stdio.h>

typedef struct s_game_map
{
	char	**map_data;
	int		map_y;
	int		map_x;
	int		player_position_x;
	int		player_position_y;
	void	*wall;
	void	*exit;
	void	*floor;
	void	*items;
	void	*player; // *player[2] что бы картинка персонажа менялась
	int		max_score;
	// int		current_score;
	// int		steps;
	int		game_over;
	// void	*end_img;
	// void	*enemy;
	// int		*enemypos;
	void	*mlx;
	void	*window;
}	t_game;

typedef struct s_flags
{
	int	c;
	int	p;
	int	e;
}	t_flags;

int		ft_close(void);
void	ft_error(char *str);
void	check_flags(t_flags *wow);
void	check_cpe(char sym, t_flags *wow);
void	map_parce(char *argv, t_game *data);
void	ft_check_pec(char sym, int y, int x, t_game *data);
void	draw_floor(t_game *data, int x, int y);
void	draw_wall(t_game *data, int x, int y);
void	draw_item(t_game *data, int x, int y);
void	draw_exit(t_game *data, int x, int y););
void	draw_player(t_game *data, int x, int y);

#endif