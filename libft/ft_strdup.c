/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urycherd <urycherd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:50:49 by urycherd          #+#    #+#             */
/*   Updated: 2021/10/18 15:44:41 by urycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char		*str;
	size_t		len;

	len = ft_strlen(s1) + 1;
	str = (char *)malloc(len);
	if (!(str))
		return (0);
	ft_strlcpy(str, s1, len);
	return (str);
}
