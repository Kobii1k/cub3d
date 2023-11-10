/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagne <mgagne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:29:44 by mgagne            #+#    #+#             */
/*   Updated: 2023/11/10 12:55:55 by mgagne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

t_data	*init_cube(char *str)
{
	t_data	*cube;
	int		fd;
	int		index;

	fd = map_verif(str);
	if (fd == -1)
		return (NULL);
	cube = malloc(sizeof(t_data));
	if (!cube)
		return (close(fd), NULL);
	cube->p = parse_map(cube, fd);
	if (!cube->p)
		return (close(fd), free(cube), NULL);
	cube->keys = malloc(sizeof(int) * 7);
	if (!cube->keys)
		return (close(fd), free_parse(cube->p, NULL, 1),
			free_map(cube->map, cube->height), free(cube), NULL);
	index = 0;
	while ((index + 1) <= ESCk)
	{
		cube->keys[index] = 0;
		index++;
	}
	print_map(cube);
	return (close(fd), cube->count = 0, cube);
}
