/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:06:02 by mgagne            #+#    #+#             */
/*   Updated: 2023/10/31 09:58:42 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int		map_verif(char *str);
int		verif_map_name(char *str);
void	print_map(t_data *cube);

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

int	path_values(t_parse *p, char *str, int i, int n)
{
	if (n == 0)
	{
		p->north = ft_strdup(&(str[i]));
		if (!p->north)
			return (printf("malloc error\n"), 1);
	}
	if (n == 1)
	{
		p->south = ft_strdup(&(str[i]));
		if (!p->south)
			return (printf("malloc error\n"), 1);
	}
	if (n == 2)
	{
		p->east = ft_strdup(&(str[i]));
		if (!p->east)
			return (printf("malloc error\n"), 1);
	}
	if (n == 3)
	{
		p->west = ft_strdup(&(str[i]));
		if (!p->west)
			return (printf("malloc error\n"), 1);
	}
	return (0);
}
