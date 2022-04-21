/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urycherd <urycherd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:11:28 by urycherd          #+#    #+#             */
/*   Updated: 2021/10/19 16:20:28 by urycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s01;
	unsigned char	*s02;

	if (!(n))
		return (0);
	s01 = (unsigned char *)s1;
	s02 = (unsigned char *)s2;
	i = 0;
	while (*s01 == *s02 && i < n - 1)
	{
		s01++;
		s02++;
		i++;
	}
	return (*s01 - *s02);
}
