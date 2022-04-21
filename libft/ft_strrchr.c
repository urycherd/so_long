/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urycherd <urycherd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:26:45 by urycherd          #+#    #+#             */
/*   Updated: 2021/10/27 21:01:04 by urycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*a;

	a = s;
	while (*s)
		s++;
	while (s >= a)
	{
		if (*s == (char)c)
			return ((char *)s);
		s--;
	}
	return (0);
}
