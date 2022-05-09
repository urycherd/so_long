/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_sup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urycherd <urycherd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:00:31 by urycherd          #+#    #+#             */
/*   Updated: 2022/05/09 21:08:02 by urycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_pec(char sym, int y, int x, t_game *data)
{
	if ((y == 0 || y == data->map_y - 1 || x == 0 \
		|| x == data->map_x - 1) && sym != '1') // не факт, что у правильно работает
		ft_error("Error: map mistake");
	if (sym == 'P')
	{
		data->player_position_x = x;
		data->player_position_y = y;
	}
	if (sym == 'C')
		data->max_score++;
}

void	check_flags(t_flags *wow)
{
	if (wow->c == 0)
		ft_error("Error: map mistake");
	else if (wow->e == 0)
		ft_error("Error: map mistake");
	else if (wow->p == 0)
		ft_error("Error: map mistake");
}

void	check_cpe(char sym, t_flags *wow)
{
	if (sym == 'C')
		wow->c++;
	if (sym == 'P')
		wow->p++;
	if (sym == 'E')
		wow->e++;
}
