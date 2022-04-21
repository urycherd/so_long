/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urycherd <urycherd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:52:01 by urycherd          #+#    #+#             */
/*   Updated: 2021/11/09 15:09:57 by urycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	words_counter(char const *lol, char c)
{
	int	i;

	i = 0;
	while (*lol && *lol == c)
		lol++;
	while (*lol)
	{
		while (*lol && *lol != c)
			lol++;
		while (*lol && *lol == c)
			lol++;
		i++;
	}
	return (i);
}

static char	**make_strs(char **strs, char const *lol, char c)
{
	int		start;
	int		end;
	int		i;

	start = 0;
	i = 0;
	while (lol[start] && lol[start] == c)
		start++;
	end = start;
	while (lol[end])
	{
		while (lol[end] && lol[end] != c)
			end++;
		strs[i] = ft_substr(lol, start, end - start);
		while (lol[end] && lol[end] == c)
			end++;
		start = end;
		i++;
	}
	strs[i] = NULL;
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		num;

	if (!s)
		return (0);
	num = words_counter(s, c);
	strs = (char **)malloc(sizeof(char *) * (num + 1));
	if (!strs)
		return (0);
	strs = make_strs(strs, s, c);
	return (strs);
}
