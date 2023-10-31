/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagne <mgagne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:29:44 by mgagne            #+#    #+#             */
/*   Updated: 2023/10/31 16:30:01 by mgagne           ###   ########.fr       */
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
		return (NULL);
	cube->keys = malloc(sizeof(int) * 7);
	if (!cube->keys)
		return (close(fd), free(cube), NULL);
	index = 1;
	while (index <= ESCk)
	{
		cube->keys[index - 1] = 0;
		index++;
	}
	print_map(cube);
	close(fd);
	return (cube->count = 0, cube);
}