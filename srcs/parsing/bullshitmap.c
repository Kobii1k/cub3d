/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bullshitmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 23:07:57 by cprojean          #+#    #+#             */
/*   Updated: 2023/10/09 17:08:43 by cprojean         ###   ########.fr       */
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
	while (str && str[0] != '1')
	{
		free(str);
		str = get_next_line(fd);
	}
	while (str)
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
