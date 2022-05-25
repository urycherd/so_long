/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sup_functions_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urycherd <urycherd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:05:35 by urycherd          #+#    #+#             */
/*   Updated: 2022/05/25 21:41:17 by urycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_data(t_game **data)
{
	int	i;

	i = 0;
	while ((*data)->map_data[i])
	{
		free((*data)->map_data[i]);
		i++;
	}
	free((*data)->map_data);
	free(*data);
}

int	clean_exit(t_game **data)
{
	mlx_destroy_window((*data)->mlx, (*data)->window);
	free_data(data);
	exit(1);
	return (0);
}

void	ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	write(1, "\n", 1);
	exit(1);
}

int	ft_close(void)
{
	exit(0);
}

void	initialization(t_game **data)
{
	(*data)->map_data = NULL;
	(*data)->map_y = 0;
	(*data)->map_x = 0;
	(*data)->max_score = 0;
	(*data)->current_score = 0;
	(*data)->steps = 0;
	(*data)->game_over = 0;
	(*data)->framecount = 0;
	(*data)->idle_frames = 25;
	(*data)->action_frames = 10;
	(*data)->enemypos_x = 0;
	(*data)->enemypos_y = 0;
	(*data)->en_fm_ct = 0;
	(*data)->en_act_fm = 50;
	(*data)->enmvec = 1;
}
