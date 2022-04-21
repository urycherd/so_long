/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urycherd <urycherd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:03:24 by urycherd          #+#    #+#             */
/*   Updated: 2021/10/18 13:20:23 by urycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*s;

	if (!(s1) || !(s2))
		return (0);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	s = (char *)malloc(len_s1 + len_s2 + 1);
	if (!s)
		return (0);
	ft_strlcpy(s, s1, len_s1 + 1);
	ft_strlcpy(s + len_s1, s2, len_s2 + 1);
	return (s);
}
