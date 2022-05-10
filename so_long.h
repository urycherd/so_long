/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urycherd <urycherd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 13:46:55 by urycherd          #+#    #+#             */
/*   Updated: 2022/05/10 15:54:53 by urycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
// # include <mlx.h>
# include "mlx/mlx.h"
# include "libft/libft.h"

# define SCALE 100

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
	int		current_score;
	int		steps;
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
int		ft_check(char *line);
int		ft_check_name(char *name);
int		check_flags(t_flags *wow);
int		clean_exit(t_game **data);
int		check_name_and_fd(char *argv, t_game **data);
int		map_mistake(char *line, int lenght);
int		key_hook(int keysym, t_game **data);
int		ft_check_pec(char sym, int y, int x, t_game *data);
int		additional_check_of_map(char	**map, t_game *data);
void	initialization(t_game **data);
void	step_counter(t_game **data);
void	ft_error(char *str);
void	make_img(t_game **data);
void	ft_error_and_free(t_game **data, char *str);
void	draw_all_map(t_game **data);
void	free_data(t_game **data);
void	make_window(t_game **data);
void	check_cpe(char sym, t_flags *wow);
void	map_parce(char *argv, t_game **data);
void	draw_floor(t_game *data, int x, int y);
void	draw_wall(t_game *data, int x, int y);
void	draw_item(t_game *data, int x, int y);
void	draw_exit(t_game *data, int x, int y);
void	draw_player(t_game *data, int x, int y);

#endif