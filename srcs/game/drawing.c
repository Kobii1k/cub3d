/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 23:07:18 by cprojean          #+#    #+#             */
/*   Updated: 2023/10/02 23:09:13 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	draw_player(t_data *cube)
{
	int	index_max;
	int	jndex_max;
	int	tmpx;
	int	tmpy;

	ft_printf("%d %d\n", cube->j1->posx, cube->j1->posy);
	index_max = cube->j1->posx + 30;
	tmpy = cube->j1->posy;
	tmpx = cube->j1->posx;
	jndex_max = cube->j1->posy + 30;
	while (cube->j1->posx < index_max)
	{
		cube->j1->posy = tmpy;
		while (cube->j1->posy < jndex_max)
		{
			my_mlx_pixel_put(cube, cube->j1->posx, cube->j1->posy, 0xFFFFFF);
			cube->j1->posy += 1;
		}
		cube->j1->posx += 1;
	}
	cube->j1->posx = tmpx;
	cube->j1->posy = tmpy;
	mlx_put_image_to_window(cube->mlx_ptr, cube->mlx_win, cube->img_ptr, 0, 0);
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
				color = 0xFFFFFF;
			else
				color = 0x000000;
			draw_square(cube, color, index, jdex);
			jdex++;
		}
		index++;
	}
}

void	draw_square(t_data *cube, int color, int index, int jdex)
{
	int	tmpind;
	int	tmpjdex;

	index = index * 100;
	jdex = jdex * 100;
	tmpind = index;
	tmpjdex = jdex;
	while (index < tmpind + 100)
	{
		jdex = tmpjdex;
		while (jdex < tmpjdex + 100)
		{
			my_mlx_pixel_put(cube, index, jdex, color);
			jdex++;
		}
		index++;
	}
}
