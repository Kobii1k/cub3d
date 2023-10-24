/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagne <mgagne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:36:14 by mgagne            #+#    #+#             */
/*   Updated: 2023/10/24 14:47:26 by mgagne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	which_param(char *str);
int	path_values(t_parse *p, char *str, int i, int n);
int	rgb_to_hex(t_parse *p, char *str, int i, int n);

int	get_params(char *str, t_parse *p, int complete[6])
{
	int	n;
	int	i;

	n = which_param(str);
	if (n == -1)
		return (ft_printf("map error : values not found\n"), 1);
	else
	{
		if (complete[n] == 1)
			return (ft_printf("map error : duplicate value\n"), 1);
		complete[n] = 1;
		i = 2;
		if (n == 4 || n == 5)
			i = 1;
		while (str[i] == ' ')
			i++;
		if (n != 4 && n != 5)
			return (path_values(p, str, i, n));
		else
			return (rgb_to_hex(p, str, i, n));
	}
}
int	input_values(t_parse *p, int fd, int complete[6])
{
	int		n;
	char	*str;

	n = 0;
	str = get_next_line(fd);
	ft_memset(complete, 0, 6);
	while (str)
	{
		if (str[0])
		{
			if (get_params(str, p, complete))
				return (free(str), free_parse(p), 1);
			n++;
			if (n == 6)
				break ;
		}
		str = get_next_line(fd);
	}
	return (free(str), 0);
}

int	verified_value(char c, int border, int *player)
{
	if (border == 1 && c == '1')
		return (1);
	if (border == 1 && c == '0')
		return (0);
	if (c == '0' || c == '1')
		return (1);
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		if (*player == 0)
		{
			*player = 1;
			return (1);
		}
		else
			return (ft_printf("map error : multiple player position value\n"), 0);
	}
	return (ft_printf("map error : unknown value detected\n"), 0);
}

int	map_check(char **map, int size)
{
	int		i;
	int		j;
	int		border;
	int		player;

	j = 0;
	player = 0;
	while (j < size)
	{
		i = 0;
		while (map[j][i])
		{
			if (i == 0 || j == 0 || j == size - 1 || map[j][i+1] == '\0')
				border = 1;
			if (verified_value(map[j][i], border, &player) == 0)
				return (1);
			border = 0;
			i++;
		}
		j++;
	}
	return (0);
}

t_parse	*parse_map(int fd, char **map, int size)
{
	t_parse	*p;
	int		complete[6];

	p = malloc(sizeof(t_parse));
	if (!p)
		return (NULL);
	if (input_values(p, fd, complete))
		return (NULL);
	if (map_check(map, size))
		return (NULL);
	return (p);
}
// printf("NO : %s\nSO : %s\nWE : %s\nEA : %s\nC : %x\nF : %x\n", p->north, p->south, p->east, p->west, p->ceiling, p->floor);

int	which_param(char *str)
{
	int	nb;

	nb = -1;
	if (ft_strncmp(str, "NO", 2) == 0)
		nb = 0;
	if (ft_strncmp(str, "SO", 2) == 0)
		nb = 1;
	if (ft_strncmp(str, "EA", 2) == 0)
		nb = 2;
	if (ft_strncmp(str, "WE", 2) == 0)
		nb = 3;
	if (ft_strncmp(str, "C", 1) == 0)
		nb = 4;
	if (ft_strncmp(str, "F", 1) == 0)
		nb = 5;
	return (nb);
}

int	createRGB(int r, int g, int b)
{
    return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

int	translate_rgb(char *str)
{
	char	**values;
	int		i;
	int		j;
	int		nb[3];

	values = ft_split(str, ',');
	if (!values)
		return (printf("malloc error\n"), -1);
	i = -1;
	while (values[++i])
	{
		j = -1;
		while (values[i][++j])
		{
			if (!ft_isdigit(values[i][j]))
				return (free_s(values),
					printf("error : RGB value not digit\n"), -1);
		}
		nb[i] = ft_atoi(values[i]);
		if (nb[i] > 255 && nb[i] < 0)
			return (free_s(values), printf("error : 0<RGB_value<255\n"), -1);
	}
	if (i == 3)
		return(free_s(values), createRGB(nb[0], nb[1], nb[2]));
	return (free_s(values), printf("error : you must have 3 RGB values\n"), -1);
}

int	rgb_to_hex(t_parse *p, char *str, int i, int n)
{
	if (n == 4)
	{
		p->ceiling = translate_rgb(&str[i]);
		if (p->ceiling == -1)
			return (1);
	}
	else if (n == 5)
	{
		p->floor = translate_rgb(&str[i]);
		if (p->floor == -1)
			return (1);
	}
	return (0);
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
