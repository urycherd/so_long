/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse_sup_0_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urycherd <urycherd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:38:05 by urycherd          #+#    #+#             */
/*   Updated: 2022/05/24 19:40:57 by urycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_check_name(char *name)
{
	int			len;
	const char	*start;

	len = ft_strlen(name);
	start = (const char *) &name[(len - 4)];
	if (ft_strncmp(start, ".ber", 4) == 0)
		return (1);
	return (0);
}

int	check_name_and_fd(char *argv, t_game **data)
{
	int	fd;

	if (!ft_check_name(argv))
		ft_error_and_free(data, "Error: file name mistake");
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		ft_error_and_free(data, "Error: fd mistake");
	return (fd);
}

static int	length_mistake(char *line, int lenght)
{
	int	i;

	i = 0;
	if ((int)ft_strlen(line) != lenght)
	{
		return (0);
	}
	while (i != lenght)
	{
		if (ft_strchr("01CEP", line[i++]) != 0)
			return (1);
	}
	return (0);
}

static void	flag_inicilization(t_flags *wow)
{
	wow->c = 0;
	wow->p = 0;
	wow->e = 0;
}

int	additional_check_of_map(char **map, t_game *data)
{
	int		x;
	int		y;
	t_flags	wow;

	y = 0;
	flag_inicilization(&wow);
	while (map[y])
	{
		x = 0;
		if (length_mistake(map[y], data->map_x) == 0)
			return (0);
		while (map[y][x])
		{
			if (ft_check_pec(map[y][x], y, x, data) == 0)
				return (0);
			check_cpe(map[y][x], &wow);
			x++;
		}
		y++;
		data->map_y++;
	}
	if (check_flags(&wow) == 0)
		return (0);
	return (1);
}
