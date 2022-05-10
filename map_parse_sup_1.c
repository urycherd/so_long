/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_sup_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urycherd <urycherd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:00:31 by urycherd          #+#    #+#             */
/*   Updated: 2022/05/10 15:01:29 by urycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check(char *line)
{
	int	x;

	x = 0;
	if (line[0] == '\n')
	{
		free(line);
		return (0);
	}
	while (line[x])
	{
		if (line[x] == '\n' && line[x + 1] == '\n')
		{
			free(line);
			return (0);
		}
		x++;
	}
	return (1);
}

int	ft_check_pec(char sym, int y, int x, t_game *data)
{
	if ((y == 0 || y == data->map_y - 1 || x == 0 \
		|| x == data->map_x - 1) && sym != '1')
		return (0);
	if (sym == 'P')
	{
		data->player_position_x = x;
		data->player_position_y = y;
	}
	if (sym == 'C')
		data->max_score++;
	return (1);
}

int	check_flags(t_flags *wow)
{
	if (wow->c == 0)
		return (0);
	if (wow->e == 0)
		return (0);
	if (wow->p == 0 || wow->p > 1)
		return (0);
	else
		return (1);
}

void	check_cpe(char sym, t_flags *wow)
{
	if (sym == 'C')
		wow->c++;
	else if (sym == 'P')
		wow->p++;
	else if (sym == 'E')
		wow->e++;
}
