/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bullshitmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 23:07:57 by cprojean          #+#    #+#             */
/*   Updated: 2023/10/07 22:08:26 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

char	**create_map(int fd, t_data *cube)
{
	char	**map;
	char	*str;
	int		index;

	index = 0;
	map = malloc(sizeof(char *) * 60);
	str = get_next_line(fd);
	if (str == NULL)
		return (NULL);
	while(str && str[0] != '1')
	{
		free(str);
		str = get_next_line(fd);
	}
	while(str)
	{
		map[index] = ft_strdup(str);
		free(str);
		str = get_next_line(fd);
		index++;
	}
	ft_printf("%d\n", index);
	cube->height = index;
	return (map);
}

	// jdex = 0;
	// map = malloc(sizeof(char *) * 10);
	// while (index < 10)
	// {
	// 	map[index] = malloc(sizeof(char) * 10);
	// 	index++;
	// }
	// index = 0;
	// while (index < 10)
	// {
	// 	jdex = 0;
	// 	while (jdex < 10)
	// 	{
	// 		if (jdex == 4 && index == 4)
	// 			map[index][jdex] = 'N';
	// 		else if ((jdex == 0 || index == 0) || ((jdex == 9 || index == 9)))
	// 			map[index][jdex] = '1';
	// 		else if ((jdex * 3) % 5 == 0)
	// 			map[index][jdex] = '1';
	// 		else
	// 			map[index][jdex] = '0';
	// 		jdex++;
	// 	}
	// 	index++;
	// }
 