/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagne <mgagne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 12:13:41 by mgagne            #+#    #+#             */
/*   Updated: 2023/10/29 15:10:00 by mgagne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

t_player	axis_converter(t_data cube, int x, int y);
void		put_map2D(t_data *cube, double x, double y, char c);
void		raycast(t_data *cube, double r, int y);
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
			my_mlx_pixel_put(cube, floor(100 + x1 + 5), floor(100 + y1 + 5), 0xFF0000);
			r--;
		}
		angle++;
	}
	// draw_lines(cube);
}

void	draw_map2D(t_data *cube)
{
	double	x;
	double	y;
	double	xkeep;
	double	ykeep;

	x = ((cube->j1.posx + 10.0) - 100.0);
	y = ((cube->j1.posy + 10.0) - 100.0);
	xkeep = x;
	ykeep = y;
	while (y <= (ykeep + 200.0))
	{
		x = xkeep;
		while (x <= (xkeep + 200.0))
		{

			if (x >= 0.0 && y >= 0.0 && floor(y)/10 < cube->height && cube->map[(int)floor(y/10)][(int)floor(x/10)])
				put_map2D(cube, (floor(xkeep - x + 200.0)), (floor(ykeep - y + 200.0)), cube->map[(int)floor((y/10))][(int)floor((x/10))]);
			x += 0.99999;
		}
		y += 0.99999;
	}
	return ;
}

void	put_map2D(t_data *cube, double x, double y, char c)
{
	if (c == '1')
		my_mlx_pixel_put(cube, x, y, 0x005500);
	else if (c == '0')
		my_mlx_pixel_put(cube, x, y, 0xF0F0F0);
	else if (ft_isalpha(c))
		my_mlx_pixel_put(cube, x, y, 0xF0F0F0);
	else if (c == ' ')
		my_mlx_pixel_put(cube, x, y, 0x000000);
}
