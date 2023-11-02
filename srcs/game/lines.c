/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagne <mgagne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:24:58 by cprojean          #+#    #+#             */
/*   Updated: 2023/11/02 17:26:39 by mgagne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	ft_reduce_opacity(int color)
{
	double	red;
	double	green;
	double	blue;

	red = (double)((color & 0xFF0000) >> 16) * 0.7;
	green = (double)((color & 0x00FF00) >> 8) * 0.7;
	blue = (double)(color & 0x0000FF) * 0.7;
	return (blue + ((int)green << 8) + ((int)red << 16));
}

int	is_in_tab(int tab[35][2], int x, int y)
{
	int	i;

	i = 0;
	while (i < 35)
	{
		if (tab[i][0] == x && tab[i][1] == y)
			return (1);
		i++;
	}
	return (0);
}

void	do_line(t_data *cube, double tmp_angle, int tab[35][2], int oldtab[35][2])
{
	int	x;
	int	y;
	int	pixel;
	int	r;

	r = 4;
	while (r < 35)
	{
		x = r * cos(tmp_angle * M_PI / 180) + 105;
		y = r * sin(tmp_angle * M_PI / 180) + 105;
		if (!is_in_tab(tab, x, y) && !is_in_tab(oldtab, x, y))
		{
			pixel = my_mlx_pixel_get(&(cube->window), x, y);
			my_mlx_pixel_put(cube, x, y, ft_reduce_opacity(pixel));
		}
		tab[r][0] = x;
		tab[r][1] = y;
		r++;
	}
	return ;
}

void	draw_vision(t_data *cube)
{
	double	tmp_angle;
	int		tab[35][2];
	int		oldtab[35][2];
	int		i;

	tmp_angle = cube->j1.player_angle;
	tmp_angle = tmp_angle - 30;
	do_line(cube, tmp_angle, tab, oldtab);
	tmp_angle += 1;
	while (tmp_angle < cube->j1.player_angle + 30)
	{
		i = 0;
		while (i < 35)
		{
			oldtab[i][0] = tab[i][0];
			oldtab[i][1] = tab[i][1];
			i++;
		}
		do_line(cube, tmp_angle, tab, oldtab);
		tmp_angle += 0.1;
	}
	return ;
}
