/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sup_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urycherd <urycherd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:05:35 by urycherd          #+#    #+#             */
/*   Updated: 2022/03/22 16:43:34 by urycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// static void	ft_putstr_fd(char *s, int fd)
// {
// 	if (!s)
// 		return ;
// 	while (*s)
// 	{
// 		write(fd, s, 1);
// 		s++;
// 	}
// 	write(fd, "\n", 1);
// }

void	ft_error(char *str)
{
	ft_putstr_fd(str, 2);
	write(1, "\n", 1);
	exit(1);
}

// void	player_position(char **map, t_game *data)
// {
// 	while
// }
