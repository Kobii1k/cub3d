/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagne <mgagne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:30:44 by mgagne            #+#    #+#             */
/*   Updated: 2023/10/31 16:31:22 by mgagne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

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

int	path_values(t_parse *p, char *str, int i, int n)
{
	if (n == 0)
	{
		p->north = ft_strdup_nospace(&(str[i]));
		if (!p->north)
			return (printf("malloc error\n"), 1);
	}
	if (n == 1)
	{
		p->south = ft_strdup_nospace(&(str[i]));
		if (!p->south)
			return (printf("malloc error\n"), 1);
	}
	if (n == 2)
	{
		p->east = ft_strdup_nospace(&(str[i]));
		if (!p->east)
			return (printf("malloc error\n"), 1);
	}
	if (n == 3)
	{
		p->west = ft_strdup_nospace(&(str[i]));
		if (!p->west)
			return (printf("malloc error\n"), 1);
	}
	return (0);
}