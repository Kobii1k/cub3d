/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagne <mgagne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:06:02 by mgagne            #+#    #+#             */
/*   Updated: 2023/10/31 16:34:08 by mgagne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	map_verif(char *str)
{
	int		fd;

	if (verif_map_name(str) == -1)
	{
		ft_printf("map error : bad file extension\n");
		return (-1);
	}
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("map error : no access to file\n");
		return (-1);
	}
	return (fd);
}

int	verif_map_name(char *str)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '.')
			tmp = i;
		i++;
	}
	if (!str[tmp + 1] || str[tmp + 1] != 'c')
		return (-1);
	if (!str[tmp + 2] || str[tmp + 2] != 'u')
		return (-1);
	if (!str[tmp + 3] || str[tmp + 3] != 'b')
		return (-1);
	if (str[tmp + 4])
		return (-1);
	return (0);
}

void	print_map(t_data *cube)
{
	int	index;

	if (!cube->map)
		ft_printf("Error with the map\n");
	index = 0;
	while (index < cube->height)
	{
		ft_printf("%s\n", cube->map[index]);
		index++;
	}
}
