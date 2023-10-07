/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 23:07:18 by cprojean          #+#    #+#             */
/*   Updated: 2023/10/06 00:18:58 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"
#include <stdio.h>

t_player	axis_converter(t_data cube, int x, int y);

void	draw_player(t_data *cube)
{
	int	index_max;
	int	jndex_max;
	int	tmpx;
	int	tmpy;

	index_max = cube->j1.posx + 10;
	tmpy = cube->j1.posy;
	tmpx = cube->j1.posx;
	jndex_max = cube->j1.posy + 10;
	while (cube->j1.posx < index_max)
	{
		cube->j1.posy = tmpy;
		while (cube->j1.posy < jndex_max)
		{
			my_mlx_pixel_put(cube, cube->j1.posx, cube->j1.posy, 0xFF0000);
			cube->j1.posy++;
		}

		cube->j1.posx++;
	}
	cube->j1.posx = tmpx;
	cube->j1.posy = tmpy;
	// draw_vision(cube);
}

// void	draw_vision(t_data *cube)
// {
// 	int	index_max;
	
// 	index_max = cube->j1.posx + 50;
// }

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
				draw_square(cube, color, index, jdex);
			}
			else if (cube->map[index][jdex] == '0')
			{
				color = 0xF0F0F0;
				draw_square(cube, color, index, jdex);
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

// void	draw_line(t_data *cube, int index, int jdex)
// {
	
// }

// t_player	axis_converter(t_data cube, int x, int y)
// {
// 	t_player	j1;

// 	(void) cube;
// 	j1.posx = (x - WINWIDTH / 2.0);
// 	j1.posy = (y - WINHEIGTH / 2.0);
// 	return (j1);
// }
