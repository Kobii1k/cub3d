/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagne <mgagne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:06:02 by mgagne            #+#    #+#             */
/*   Updated: 2023/11/14 14:38:43 by mgagne           ###   ########.fr       */
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

int	verified_value(char c)
{
	return (c == '1'
		|| c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int	check_void(int i, int j, int size, char **map)
{
	char	c;

	c = map[j][i];
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		c = '0';
	if (i == 0 || j == 0 || j == size - 1 || map[j][i + 1] == '\0')
		return ((c == '1' || ft_isspace(c)));
	if (c == '0')
		return (verified_value(map[j][i - 1]) && verified_value(map[j][i + 1])
		&& verified_value(map[j + 1][i]) && verified_value(map[j - 1][i]));
	if (ft_isspace(c) || c == '1')
		return (1);
	return (0);
}
