/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_sup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urycherd <urycherd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 14:42:42 by urycherd          #+#    #+#             */
/*   Updated: 2022/05/10 14:47:58 by urycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	step_counter(t_game **data)
{
	char	*steps;

	(*data)->steps++;
	steps = ft_itoa((*data)->steps);
	ft_putstr_fd("step:", 2);
	ft_putstr_fd(steps, 2);
	ft_putstr_fd("\n", 2);
	free(steps);
}
