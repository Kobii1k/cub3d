/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bullshitmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 23:07:57 by cprojean          #+#    #+#             */
/*   Updated: 2023/10/02 23:09:29 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

char	**create_map(int fd)
{
	char	**map;
	int		index;
	int		jdex;

	(void) fd;
	index = 0;
	jdex = 0;
	map = malloc(sizeof(char *) * 10);
	while (index < 10)
	{
		map[index] = malloc(sizeof(char) * 10);
		index++;
	}
	index = 0;
	while (index < 10)
	{
		jdex = 0;
		while (jdex < 10)
		{
			if ((jdex == 0 || index == 0) || ((jdex == 9 || index == 9)))
				map[index][jdex] = '1';
			else if ((jdex * 3) % 5 == 0)
				map[index][jdex] = '1';
			else
				map[index][jdex] = '0';
			jdex++;
		}
		index++;
	}
	return (map);
}
