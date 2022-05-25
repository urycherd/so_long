/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_sup_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urycherd <urycherd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:42:42 by urycherd          #+#    #+#             */
/*   Updated: 2022/05/10 18:59:54 by urycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*step_counter(t_game **data)
{
	char	*steps;

	(*data)->steps++;
	steps = ft_itoa((*data)->steps);
	return (steps);
}

void	counter_draw(t_game **data)
{
	char	*steps;

	draw_wall(*data, 0, 0);
	steps = step_counter(data);
	mlx_string_put((*data)->mlx, (*data)->window, 50, 50, -1, steps);
	free(steps);
}
