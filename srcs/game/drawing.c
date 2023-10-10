/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 23:07:18 by cprojean          #+#    #+#             */
/*   Updated: 2023/10/10 16:35:23 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

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
	draw_lines(cube);
}

void	draw_lines(t_data *cube)
{
	int		r;
	int		x1;
	int		y1;
	int		posx;
	int		posy;
	double	tmp_angle;

	posx = cube->j1.posx + 5;
	posy = cube->j1.posy + 5;
	r = 0;
	cube->j1.posx += 5;
	cube->j1.posy += 5;
	tmp_angle = cube->j1.player_angle;
	tmp_angle = tmp_angle - 60;
	while (tmp_angle < cube->j1.player_angle + 60)
	{
		r = 0;
		while (r < 80)
		{
			x1 = r * cos(tmp_angle * M_PI / 180);
			y1 = r * sin(tmp_angle * M_PI / 180);
			posx = floor((cube->j1.posx + x1) / 10);
			posy = floor((cube->j1.posy + y1) / 10);
			if ((posx >= 0) && (posy >= 0) && (cube->map[posy][posx] == '1'))
			{
				my_mlx_pixel_put(cube, cube->j1.posx + x1, cube->j1.posy + y1, 0xFE0000);
				break ;
			}
			r++;
		}
		tmp_angle += 2;
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
	while (index < cube->height)
	{
		jdex = 0;
		while (cube->map[index][jdex])
		{
			if (cube->map[index][jdex] == '1')
			{
				color = 0x00FF00;
				draw_square(cube, color, index, jdex);
			}
			else if (cube->map[index][jdex] == '0')
			{
				color = 0xF0F0F0;
				draw_square(cube, color, index, jdex);
			}
			else if (ft_isalpha(cube->map[index][jdex]) == 1)
			{
				if (cube->count == 0)
				{
					cube->j1 = init_player(jdex, index, cube->map[index][jdex]);
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
	while (index < tmpind + 10)
	{
		jdex = tmpjdex;
		while (jdex < tmpjdex + 10)
		{
			my_mlx_pixel_put(cube, jdex, index, color);
			jdex++;
		}
		index++;
	}
}
