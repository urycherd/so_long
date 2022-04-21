/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: urycherd <urycherd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 18:08:14 by urycherd          #+#    #+#             */
/*   Updated: 2022/03/17 13:40:57 by urycherd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	rem_fill(int fd, char *buffer, char **rem)
{
	char	*cpy;
	int		bytes;

	if (!*rem || !ft_strchr(*rem, '\n'))
	{
		bytes = read (fd, buffer, BUFFER_SIZE);
		buffer[bytes] = '\0';
		while (bytes > 0)
		{
			if (!*rem)
				*rem = ft_substr(buffer, 0, bytes);
			else
			{
				cpy = *rem;
				*rem = ft_strjoin(*rem, buffer);
				free (cpy);
			}
			if (ft_strchr(buffer, '\n'))
				break ;
			bytes = read (fd, buffer, BUFFER_SIZE);
			buffer[bytes] = '\0';
		}
	}
	free (buffer);
}

static char	*get_line(char **rem, char **line)
{
	int		new_line;
	int		length;
	char	*cpy;

	if (*rem == 0)
		return (0);
	if (!ft_strchr(*rem, '\n'))
	{
		*line = ft_substr(*rem, 0, ft_strlen(*rem));
		free (*rem);
		*rem = 0;
		return (*line);
	}
	new_line = ft_strlen(ft_strchr(*rem, '\n'));
	length = ft_strlen(*rem);
	*line = ft_substr(*rem, 0, length - new_line + 1);
	cpy = *rem;
	*rem = ft_substr(ft_strchr(*rem, '\n'), 1, length);
	free (cpy);
	if (**rem == '\0')
	{
		free (*rem);
		*rem = 0;
	}
	return (*line);
}

char	*get_next_line(int fd)
{
	static char	*rem;
	char		*buffer;
	char		*line;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer || BUFFER_SIZE < 1 || fd < 0)
	{
		free (buffer);
		return (NULL);
	}
	rem_fill(fd, buffer, &rem);
	return (get_line(&rem, &line));
}
