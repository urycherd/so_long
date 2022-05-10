/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urycherd <urycherd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:42:40 by urycherd          #+#    #+#             */
/*   Updated: 2022/05/10 15:24:30 by urycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	making_line(int fd, char **all_line)
{
	char	*gnl_line;
	char	*tmp;

	gnl_line = get_next_line(fd);
	if (gnl_line == NULL)
		return (1);
	tmp = *all_line;
	*all_line = ft_strjoin(tmp, gnl_line);
	free(tmp);
	free(gnl_line);
	return (0);
}

static void	ft_error_and_free(t_game **data)
{
	free(*data);
	ft_error("Error: map mistake");
}

void	map_parce(char *argv, t_game **data)
{
	int		fd;
	int		done;
	char	*all_line;

	done = 0;
	fd = check_name_and_fd(argv);
	if (fd == -1)
		ft_error_and_free(data);
	all_line = get_next_line(fd);
	if (all_line == NULL)
		ft_error_and_free(data);
	(*data)->map_x = ft_strlen(all_line) - 1;
	while (done == 0)
		done = making_line(fd, &all_line);
	if (ft_check(all_line) == 0)
		ft_error_and_free(data);
	(*data)->map_data = ft_split(all_line, '\n');
	free(all_line);
	if (additional_check_of_map((*data)->map_data, *data) == 0)
	{
		free_data(data);
		ft_error("Error: map mistake");
	}
	close(fd);
}
