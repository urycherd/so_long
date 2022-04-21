/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urycherd <urycherd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:42:46 by urycherd          #+#    #+#             */
/*   Updated: 2021/10/14 14:02:29 by urycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	a;
	unsigned int	b;
	unsigned int	c;

	a = 0;
	b = 0;
	if (ft_strlen(needle) == 0)
		return ((char *)&haystack[a]);
	while (haystack[a] && len)
	{
		c = a;
		while (haystack[c] == needle[b] && b < len)
		{
			c++;
			b++;
			if (needle[b] == '\0')
				return ((char *)&haystack[a]);
		}
		a++;
		b = 0;
		len--;
	}
	return (0);
}
