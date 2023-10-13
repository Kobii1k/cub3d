/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 23:07:18 by cprojean          #+#    #+#             */
/*   Updated: 2023/10/13 13:19:19 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

t_player	axis_converter(t_data cube, int x, int y);
void		put_map2D(t_data *cube, int index, int jdex, int color);
void		raycast(t_data *cube, double r, int index);

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
	// draw_lines(cube);
}

void	draw_raycast(t_data *cube)
{
	double	r;
	int		x1;
	int		y1;
	int		posx;
	int		posy;
	int		index;
	double	tmp_angle;

	index = 0;
	posx = cube->j1.posx + 5;
	posy = cube->j1.posy + 5;
	r = 0;
	cube->j1.posx += 5;
	cube->j1.posy += 5;
	tmp_angle = cube->j1.player_angle;
	tmp_angle = tmp_angle - 60;
	while (tmp_angle < cube->j1.player_angle + 60)
	{
		r = 0.01;
		while (r < 400)
		{
			x1 = r * cos(tmp_angle * M_PI / 180);
			y1 = r * sin(tmp_angle * M_PI / 180);
			posx = floor((cube->j1.posx + x1) / 10);
			posy = floor((cube->j1.posy + y1) / 10);
			if ((posx >= 0) && (posy >= 0) && (cube->map[posy][posx] == '1'))
			{
				raycast(cube, r, index);
				break ;
			}
			// if ()
			r += 0.01;
		}
		index++;
		tmp_angle += 0.0625;
	}
	cube->j1.posx -= 5;
	cube->j1.posy -= 5;
}

void	raycast(t_data *cube, double r, int index)
{
	double	limit;
	int		jdex;

	jdex = 0;
	limit = floor((1 / r) * 1000);
	// printf("%f\n", r);
	while (jdex < WINHEIGHT)
	{
		// printf("%f : %d\n", WINHEIGHT / 2 - limit, jdex);
		if ((jdex >= (WINHEIGHT / 2) - limit) && (jdex <= (WINHEIGHT / 2) + limit))
			my_mlx_pixel_put(cube, index, jdex, 0xFFFFFF);
		else if ((jdex < (WINHEIGHT / 2) - limit))
			my_mlx_pixel_put(cube, index, jdex, 0x3A86FF);
		else if ((jdex > (WINHEIGHT / 2) + limit))
			my_mlx_pixel_put(cube, index, jdex, 0xE2D4BA);
		jdex++;
	}
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
