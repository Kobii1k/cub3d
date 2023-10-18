/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagne <mgagne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 15:48:24 by cprojean          #+#    #+#             */
/*   Updated: 2023/10/18 13:02:03 by mgagne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_buf_reset(char *buf, int index)
{
	size_t	runner;
	size_t	flag;

	flag = index;
	runner = 0;
	while (buf[runner] && index <= BUFFER_SIZE)
	{
		if (runner > BUFFER_SIZE - flag)
			buf[runner] = '\0';
		else
			buf[runner] = buf[index];
		runner++;
		index++;
	}
}

ssize_t	where_backslash(char *buf)
{
	ssize_t	runner;

	runner = 0;
	while (buf[runner])
	{
		if (buf[runner] == '\n')
			return (runner + 1);
		runner++;
	}
	return (-1);
}

size_t	ft_strlen(char *str)
{
	size_t	index;

	if (!str)
		return (0);
	index = 0;
	while (str[index])
	{
		index++;
	}
	return (index);
}

char	*ft_strnjoin(char *s1, char *s2, size_t index)
{
	size_t		sizearray;
	size_t		runner;
	size_t		size;
	char		*array;

	runner = 0;
	sizearray = ft_strlen(s1);
	size = sizearray + index + 1;
	array = malloc(sizeof(char) * (size));
	if (!array)
		return (free(s1), NULL);
	while (runner < sizearray && s1[runner] != '\0')
	{
		if (s1[runner] != 10)
			array[runner] = s1[runner];
		else
			array[runner] = '\0';
		runner++;
	}
	while (runner < sizearray + index)
	{
		if (s2[runner - sizearray] != 10)
			array[runner] = s2[runner - sizearray];
		else
			array[runner] = '\0';
		runner++;
	}
	array[runner] = '\0';
	return (free(s1), array);
}
