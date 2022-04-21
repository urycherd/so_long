/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urycherd <urycherd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:19:38 by urycherd          #+#    #+#             */
/*   Updated: 2021/11/09 15:09:28 by urycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_int_size(int n)
{
	int	size;

	size = 0;
	if (n <= 0)
		size = 1;
	while (n)
	{
		n /= 10;
		size++;
	}
	return (size);
}

static int	ft_pow(int a)
{
	int	i;

	i = 1;
	while (a--)
		i *= 10;
	return (i);
}

char	*ft_itoa(int n)
{
	char	*newnum;
	int		size;
	int		i;

	i = 0;
	size = ft_int_size(n);
	newnum = (char *)malloc(sizeof(char) * size + 1);
	if (!newnum)
		return (0);
	if (n < 0)
	{
		newnum[i] = '-';
		i++;
	}
	while (i < size)
	{
		if (n < 0)
			newnum[i] = -(n / ft_pow(size - i - 1) % 10) + '0';
		else
			newnum[i] = (n / ft_pow(size - i - 1) % 10) + '0';
		i++;
	}
	newnum[i] = '\0';
	return (newnum);
}
