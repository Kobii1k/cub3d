/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagne <mgagne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 12:13:41 by mgagne            #+#    #+#             */
/*   Updated: 2023/11/13 13:35:35 by mgagne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	put_minimap(t_data *cube, double x, double y, char c);
void	draw_outline(t_data *cube);

int	get_line_len(t_data *cube, int y)
{
	if (y >= 0 && floor(y / 10) < cube->height && cube->map[(int)floor(y / 10)])
		return (ft_strlen(cube->map[(int)floor(y / 10)]));
	else
		return (-1);
}

void	draw_minimap(t_data *cube, int len, double x, double y)
{
	double	xkeep;
	double	ykeep;

	x = ((cube->j1.posx) - 100.0);
	y = ((cube->j1.posy) - 100.0);
	xkeep = x + 200;
	ykeep = y + 200;
	while (y <= ykeep)
	{
		len = get_line_len(cube, y);
		x = xkeep - 200;
		while (x <= xkeep)
		{
			if (x >= 0 && y >= 0 && floor(y / 10) < cube->height
				&& (int)floor(x / 10) < len
				&& cube->map[(int)floor(y / 10)][(int)floor(x / 10)])
				put_minimap(cube, (floor(x - xkeep + 200)),
					(floor(y - ykeep + 200)),
					cube->map[(int)floor((y / 10))][(int)floor((x / 10))]);
			x += 0.99999;
		}
		y += 0.99999;
	}
	draw_outline(cube);
}

void	draw_outline(t_data *cube)
{
	int	x;
	int	y;

	x = 200;
	while (x < 203)
	{
		y = 0;
		while (y < 203)
		{
			my_mlx_pixel_put(cube, x, y, 0x000000);
			y++;
		}
		x++;
	}
	y = 200;
	while (y < 203)
	{
		x = 0;
		while (x < 203)
		{
			my_mlx_pixel_put(cube, x, y, 0x000000);
			x++;
		}
		y++;
	}
}

void	put_minimap(t_data *cube, double x, double y, char c)
{
	if (c == '1')
		my_mlx_pixel_put(cube, x, y, 0x000088);
	else if (c == '0')
		my_mlx_pixel_put(cube, x, y, 0xF0F0F0);
	else if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		my_mlx_pixel_put(cube, x, y, 0xF0F0F0);
}

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
			my_mlx_pixel_put(cube,
				floor(100 + x1 + 5),
				floor(100 + y1 + 5), 0xFF0000);
			r--;
		}
		angle++;
	}
}
