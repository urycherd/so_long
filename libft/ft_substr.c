/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urycherd <urycherd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 14:43:09 by urycherd          #+#    #+#             */
/*   Updated: 2021/10/19 19:58:10 by urycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	len_s;

	if (!s)
		return (0);
	len_s = ft_strlen(s);
	if (start > len_s)
	{
		new = (char *)malloc(sizeof(char) * 1);
		new[0] = '\0';
		return (new);
	}
	len = len + 1;
	if ((start + len) < len_s)
		new = (char *)malloc(sizeof(char) * len);
	else
		new = (char *)malloc(sizeof(char) * (len_s - start + 1));
	if (!(new))
		return (0);
	ft_strlcpy(new, s + start, len);
	return (new);
}
