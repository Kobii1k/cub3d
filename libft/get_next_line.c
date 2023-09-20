/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:34:30 by cprojean          #+#    #+#             */
/*   Updated: 2022/12/13 18:14:02 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*array;
	ssize_t		reader;

	if (fd < 0 || read(fd, 0, 0) == -1 || BUFFER_SIZE < 0)
		return (buf[0] = 0, NULL);
	array = malloc(sizeof(char));
	if (!array)
		return (NULL);
	array[0] = 0;
	reader = -1;
	if (buf[0] == 0)
	{
		reader = read(fd, buf, BUFFER_SIZE);
		if (reader == -1)
			return (free(array), NULL);
		buf[reader] = 0;
	}
	array = next_get_next_line(buf, array, reader, fd);
	if (!array)
		return (free(array), NULL);
	return (array);
}

char	*next_get_next_line(char *buf, char *array, ssize_t reader, int fd)
{
	while (where_backslash(buf) == -1 && reader != 0)
	{
		array = ft_strnjoin(array, buf, BUFFER_SIZE);
		if (!array)
			return (NULL);
		reader = read(fd, buf, BUFFER_SIZE);
		if (reader == -1)
			return (free(array), NULL);
		buf[reader] = 0;
	}
	if (where_backslash(buf) > 0)
	{
		array = ft_strnjoin(array, buf, where_backslash(buf));
		if (!array)
			return (NULL);
		ft_buf_reset(buf, where_backslash(buf));
		return (array);
	}
	if (array[0] == 0)
		return (free(array), NULL);
	else
		return (array);
}
