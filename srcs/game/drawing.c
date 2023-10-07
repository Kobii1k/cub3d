/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 23:07:18 by cprojean          #+#    #+#             */
/*   Updated: 2023/10/07 19:05:44 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include <stdio.h>

t_player	axis_converter(t_data cube, int x, int y);

void	draw_player(t_data *cube)
{
	int	r;
	int	x1;
	int	y1;
	int	angle;

	r = 4;
	cube->j1.posx += 5;
	cube->j1.posy += 5;
	angle = 0;
	while (angle < 360)
	{
		r = 4;
		while (r > 0)
		{
			x1 = r * cos(angle * M_PI / 180);
			y1 = r * sin(angle * M_PI / 180);
			angle += 0.1;
			my_mlx_pixel_put(cube, cube->j1.posx + x1, cube->j1.posy + y1, 0xFF0000);
			r--;
		}
		angle++;
	}
	cube->j1.posx -= 5;
	cube->j1.posy -= 5;
	draw_vision(cube);
}

void	draw_vision(t_data *cube)
{
	int		r;
	int		x1;
	int		y1;
	double	tmp_angle;

	r = 40;
	cube->j1.posx += 5;
	cube->j1.posy += 5;
	tmp_angle = cube->j1.player_angle;
	tmp_angle = tmp_angle - 60;
	while (tmp_angle < cube->j1.player_angle + 60)
	{
		r = 40;
		while (r > 0)
		{
			x1 = r * cos(tmp_angle * M_PI / 180);
			y1 = r * sin(tmp_angle * M_PI / 180);
			my_mlx_pixel_put(cube, cube->j1.posx + x1, cube->j1.posy + y1, 0xFE0000);
			r--;
		}
		tmp_angle += 0.5;
	}
	cube->j1.posx -= 5;
	cube->j1.posy -= 5;
}

void	draw_map2D(t_data *cube)
{
	int	index;
	int	jdex;
	int	color;

	index = 0;
	jdex = 0;
	while (index < 10)
	{
		jdex = 0;
		while (jdex < 10)
		{
			if (cube->map[index][jdex] == '1')
			{
				color = 0x00FF00;
				draw_square(cube, color, jdex, index);
			}
			else if (cube->map[index][jdex] == '0')
			{
				color = 0xF0F0F0;
				draw_square(cube, color, jdex, index);
			}
			else
			{
				if (cube->count == 0)
				{
					cube->j1 = init_player(index, jdex);
					cube->count = 1;
				}
				color = 0xF0F0F0;
				draw_square(cube, color, index, jdex);
			}
			jdex++;
		}
		index++;
	}
}

void	draw_square(t_data *cube, int color, int index, int jdex)
{
	int	tmpind;
	int	tmpjdex;

	(void)color;
	index = index * 10;
	jdex = jdex * 10;
	tmpind = index;
	tmpjdex = jdex;
	while (index < tmpind + (WINWIDTH / 100))
	{
		jdex = tmpjdex;
		while (jdex < tmpjdex + (WINHEIGHT / 100))
		{
			// ft_printf("%d %d\n", index, jdex);
			// j1 = axis_converter(*cube, index, jdex);
			my_mlx_pixel_put(cube, index, jdex, color);
			jdex++;
		}
		index++;
	}
}

 