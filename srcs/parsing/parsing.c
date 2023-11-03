/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:36:14 by mgagne            #+#    #+#             */
/*   Updated: 2023/11/03 13:13:57 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	input_values(t_parse *p, int fd, int complete[6]);
int	create_map(int fd, t_data *cube);
int	map_check(char **map, int size);
int	get_params(char *str, t_parse *p, int complete[6], int index);

t_parse	*parse_map(t_data *cube, int fd)
{
	t_parse	*p;
	int		complete[6];

	p = malloc(sizeof(t_parse));
	if (!p)
		return (NULL);
	if (input_values(p, fd, complete))
		return (NULL);
	if (create_map(fd, cube))
		return (NULL);
	if (map_check(cube->map, cube->height))
		return (NULL);
	return (p);
}

int	input_values(t_parse *p, int fd, int complete[6])
{
	int		n;
	int		i;
	char	*str;

	n = 0;
	str = get_next_line(fd);
	ft_memset_int(complete, 0, 6);
	while (str)
	{
		if (str[0])
		{
			i = 0;
			while (ft_isspace(str[i]))
				i++;
			if (get_params(str, p, complete, i))
				return (free(str), free_parse(p, complete, 0), 1);
			n++;
			if (n == 6)
				break ;
		}
		free(str);
		str = get_next_line(fd);
	}
	return (free(str), 0);
}

int	create_map(int fd, t_data *cube)
{
	char	*str;
	int		index;

	index = 0;
	str = get_next_line(fd);
	if (!str)
		return (1);
	cube->map = malloc(sizeof(char *) * 60);
	while (str)
	{
		if (str[0])
		{
			if (ft_isspace(str[0]) || str[0] == '1')
				break ;
			else
				return (ft_printf("map error : unexpected value\n"), 1);
		}
		free(str);
		str = get_next_line(fd);
	}
	while (str)
	{
		cube->map[index] = ft_strdup(str);
		free(str);
		str = get_next_line(fd);
		index++;
	}
	ft_printf("%d\n\n", index);
	cube->height = index;
	return (0);
}

int	map_check(char **map, int size)
{
	int		i;
	int		j;
	int		player;

	j = 0;
	player = 0;
	while (j < size)
	{
		i = 0;
		while (map[j][i])
		{
			if (!check_void(i, j, size, map))
				return (printf("map error : invalid map\n"), 1);
			if (check_player(map[j][i], &player) == 0)
				return (1);
			i++;
		}
		j++;
	}
	if (player == 0)
		return (ft_printf("map error : couldn't find player position\n"), 1);
	return (0);
}

int	get_params(char *str, t_parse *p, int complete[6], int index)
{
	int	n;
	int	i;

	n = which_param(str, index);
	if (n == -1)
		return (ft_printf("map error : values not found\n"), 1);
	else
	{
		if (complete[n] == 1)
			return (ft_printf("map error : duplicate value\n"), 1);
		if (n == 4 || n == 5)
			i = index + 1;
		else
			i = index + 2;
		if (!ft_isspace(str[i]))
			return (ft_printf("map error : space needed between values\n"), 1);
		while (ft_isspace(str[i]))
			i++;
		if ((n == 4 || n == 5))
		{
			if (rgb_to_hex(p, str, i, n) == 0)
				return (complete[n] = 1, 0);
			else
				return (1);
		}
		else
		{
			if (path_values(p, str, i, n) == 0)
				return (complete[n] = 1, 0);
			else
				return (1);
		}
	}
}
