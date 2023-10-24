/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 23:07:18 by cprojean          #+#    #+#             */
/*   Updated: 2023/10/24 15:41:27 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

t_player	axis_converter(t_data cube, int x, int y);
void		put_map2D(t_data *cube, int index, int jdex, int color);
void		raycast(t_data *cube, double r, int index);
int			test_angle(t_data *cube, double tmp_angle, double r);

void	draw_player(t_data *cube)
{
	int	r;
	int	x1;
	int	y1;
	int	angle;

	r = 4;
	angle = 0;
	while (angle < 360)
	{
		r = 4;
		while (r > 0)
		{
			x1 = r * cos(angle * M_PI / 180);
			y1 = r * sin(angle * M_PI / 180);
			angle += 0.1;
			my_mlx_pixel_put(cube, floor(cube->j1.posx + x1 + 5), floor(cube->j1.posy + y1 + 5), 0xFF0000);
			r--;
		}
		angle++;
	}
	// draw_lines(cube);
}

void	draw_map2D(t_data *cube)
{
	int	index;
	int	jdex;
	int	color;

	color = 0;
	index = 0;
	jdex = 0;
	while (index < cube->height)
	{
		jdex = 0;
		while (cube->map[index][jdex])
		{
			put_map2D(cube, index, jdex, color);
			jdex++;
		}
		index++;
	}
}

void	put_map2D(t_data *cube, int index, int jdex, int color)
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
