/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sup_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urycherd <urycherd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:05:35 by urycherd          #+#    #+#             */
/*   Updated: 2022/05/09 19:11:33 by urycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(t_game *data)
{
	int	i;

	i = 0;
	while (data->map_data[i])
	{
		free(data->map_data[i]);
		i++;
	}
	free(data->map_data);
	free(data);
}

void	ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	write(1, "\n", 1);
	exit(1);
}

int	ft_close(void)
{
	// free data in ft_close
	exit(0);
}

void	ft_check(char *line)
{
	int	x;

	x = 0;
	if (line[0] == '\n')
		ft_error("Error: map mistake");
	while (line[x])
	{
		if (line[x] == '\n' && line[x + 1] == '\n')
			ft_error("Error: map mistake");
		x++;
	}
}

void	initialization(t_game *data)
{
	data->map_data = NULL;
	data->map_y = 0;
	data->map_x = 0;
	data->max_score = 0;
	data->current_score = 0;
	data->steps = 0;
	data->game_over = 0;
}
