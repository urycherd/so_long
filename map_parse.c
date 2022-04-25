/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urycherd <urycherd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:42:40 by urycherd          #+#    #+#             */
/*   Updated: 2022/04/25 15:56:28 by urycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_check_name(char *name)
{
	int			len;
	const char	*start;

	len = ft_strlen(name);
	start = (const char *) &name[(len - 4)];
	if (ft_strncmp(start, ".ber", 4) == 0)
		return (1);
	return (0);
}

static int	check_name_and_fd(char *argv)
{
	int	fd;

	if (!ft_check_name(argv))
		ft_error("Error: wrong file name");
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		ft_error("Error: can't open this file");
	return (fd);
}

static int	map_mistake(char *line, int lenght)
{
	int	i;

	i = 0;
	if ((int)ft_strlen(line) != lenght - 1)
	{
		return (0);
	}
	while (i != lenght - 1)
	{
		if (ft_strchr("01CEP\n", line[i++]) != 0)
			return (1);
	}
	return (0);
}

static void	additional_check_of_map(char	**map, t_game *data)
{
	int		x;
	int		y;
	t_flags	wow;

	y = 0;
	data->max_score = 0;
	wow.c = 0;
	wow.p = 0;
	wow.e = 0;
	while (map[y])
	{
		x = 0;
		if (map_mistake(map[y], data->map_x) == 0)
			ft_error("Error: map mistake");
		while (map[y][x])
		{
			ft_check_pec(map[y][x], y, x, data);
			check_cpe(map[y][x], &wow);
			x++;
		}
		y++;
		data->map_y++;
	}
	check_flags(&wow);
}

void	map_parce(char *argv, t_game *data)
{
	int		fd;
	char	*gnl_line;
	char	*all_line;
	char	*tmp;

	fd = check_name_and_fd(argv);
	all_line = get_next_line(fd);
	if (all_line == NULL)
		ft_error("Error: map mistake");
	data->map_x = ft_strlen(all_line);
	data->map_y = 0;
	while (all_line != NULL)
	{
		gnl_line = get_next_line(fd);
		if (gnl_line == NULL)
			break ;
		tmp = all_line;
		all_line = ft_strjoin(tmp, gnl_line);
		free(tmp);
		free(gnl_line);
	}
	data->map_data = ft_split(all_line, '\n');
	free(all_line);
	additional_check_of_map(data->map_data, data);
	close(fd);
}
