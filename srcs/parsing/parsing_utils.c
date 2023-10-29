/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagne <mgagne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:07:54 by mgagne            #+#    #+#             */
/*   Updated: 2023/10/29 13:35:11 by mgagne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	verified_value(char c, int border, int *player)
{
	if (border == 1 && c == '1')
		return (1);
	if (border == 1 && c != '1')
		return (ft_printf("map error : must be closed by walls\n"), 0);
	if (c == '0' || c == '1' || c == ' ')
		return (1);
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		if (*player == 0)
		{
			*player = 1;
			return (1);
		}
		else
			return (ft_printf("map error : multiple player value\n"), 0);
	}
	return (ft_printf("map error : unknown value detected\n"), 0);
}

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

long	create_rgb(int r, int g, int b)
{
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

long	translate_rgb(char *str)
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
				return (free_split(values),
					printf("error : RGB value is not digit\n"), -1);
		}
		nb[i] = ft_atoi(values[i]);
		if (nb[i] > 255 || nb[i] < 0)
			return (free_split(values), printf("error : 0<RGB<255\n"), -1);
	}
	if (i == 3)
		return (free_split(values), create_rgb(nb[0], nb[1], nb[2]));
	return (free_split(values), printf("error : need 3 RGB values\n"), -1);
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
