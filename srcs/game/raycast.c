/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 13:07:32 by cprojean          #+#    #+#             */
/*   Updated: 2023/10/16 11:16:12 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static void	raycast(t_data *cube, double r, int index);
static int	test_angle(t_data *cube, double tmp_angle, double r);

void	draw_raycast(t_data *cube)
{
	int		index;
	double	r;
	double	tmp_angle;

	index = 0;
	r = 0;
	tmp_angle = cube->j1.player_angle - 60;
	while (tmp_angle < cube->j1.player_angle + 60)
	{
		r = 0.01;
		while (r < 400)
		{
			if (test_angle(cube, tmp_angle, r) == 1)
			{
				raycast(cube, r, index);
				break ;
			}
			if (test_angle(cube, tmp_angle, r + 1) == 1)
				r += 0.01;
			else
				r += 1;
		}
		index++;
		tmp_angle += (double)120/WINWIDTH;
	}
}

static int	test_angle(t_data *cube, double tmp_angle, double r)
{
	int	x1;
	int	y1;
	int	posx;
	int	posy;
	
	x1 = r * cos(tmp_angle * M_PI / 180);
	y1 = r * sin(tmp_angle * M_PI / 180);
	posx = floor((cube->j1.posx + 5 + x1) / 10);
	posy = floor((cube->j1.posy + 5 + y1) / 10);
	if ((posx >= 0) && (posy >= 0) && (cube->map[posy][posx] == '1'))
		return (1);
	else
		return (0);
}

static void	raycast(t_data *cube, double r, int index)
{
	double	limit;
	int		jdex;

	jdex = 0;
	limit = floor((1 / r) * 1000);
	while (jdex < WINHEIGHT)
	{
		if ((jdex >= (WINHEIGHT / 2) - limit) && (jdex <= (WINHEIGHT / 2) + limit))
			my_mlx_pixel_put(cube, index, jdex, 0xFFFFFF);
		else if ((jdex < (WINHEIGHT / 2) - limit))
			my_mlx_pixel_put(cube, index, jdex, 0x3A86FF);
		else if ((jdex > (WINHEIGHT / 2) + limit))
			my_mlx_pixel_put(cube, index, jdex, 0xE2D4BA);
		jdex++;
	}
}
