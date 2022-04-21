/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urycherd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 09:22:33 by urycherd          #+#    #+#             */
/*   Updated: 2021/10/06 09:22:36 by urycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dest;
	const char	*sorc;

	dest = dst;
	sorc = src;
	if (!(dst) && !(src))
		return (0);
	while (n > 0)
	{
		*dest++ = *sorc++;
		n--;
	}
	return (dst);
}
