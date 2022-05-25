/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urycherd <urycherd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 11:58:28 by urycherd          #+#    #+#             */
/*   Updated: 2022/05/10 14:54:17 by urycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	*data;

	if (argc == 2)
	{
		data = (t_game *)malloc(sizeof(t_game));
		if (data == NULL)
			exit(1);
		initialization(&data);
		map_parce(argv[1], &data);
		make_window(&data);
	}
	free_data(&data);
	return (0);
}
