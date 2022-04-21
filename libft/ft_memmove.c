/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urycherd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 13:14:13 by urycherd          #+#    #+#             */
/*   Updated: 2021/10/06 13:14:16 by urycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dest;
	const char	*sorc;

	dest = dst;
	sorc = src;
	if (!(dst) && !(src))
		return (0);
	if (dest > sorc)
	{
		while (len--)
			dest[len] = sorc[len];
	}
	else
	{
		while (len--)
			*dest++ = *sorc++;
	}
	return (dst);
}
