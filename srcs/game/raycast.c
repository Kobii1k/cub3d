/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 13:07:32 by cprojean          #+#    #+#             */
/*   Updated: 2023/10/30 16:47:37 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static	double	find_angle(t_data *cube, double tmp_angle);
static void		raycast(t_data *cube, double r, int index, double tmp_angle);
static int		test_angle(t_data *cube, double tmp_angle, double r);

void	draw_raycast(t_data *cube)
{
	int		index;
	double	r;
	double	tmp_angle;

	index = 0;
	r = 0;
	tmp_angle = cube->j1.player_angle - cube->j1.fov / 2;
	while (index < WINWIDTH)
	{
		r = 0.01;
		while (r < 800)
		{
			if (test_angle(cube, tmp_angle, r) == 1)
			{
				raycast(cube, r, index, find_angle(cube, tmp_angle));
				break ;
			}
			if (test_angle(cube, tmp_angle, r + 1) == 1)
				r += 0.01;
			else
				r += 1;
		}
		index++;
		tmp_angle += (double)cube->j1.fov / WINWIDTH;
	}
}

static int	test_angle(t_data *cube, double tmp_angle, double r)
{
	double	x1;
	double	y1;
	double	tmp[2];
	double	pos[2];

	x1 = (r - 1) * cosf(tmp_angle * M_PI / 180);
	y1 = (r - 1) * sinf(tmp_angle * M_PI / 180);
	pos[0] = (cube->j1.posx + x1 + 5) / 10;
	pos[1] = (cube->j1.posy + y1 + 5) / 10;
	x1 = r * cosf(tmp_angle * M_PI / 180);
	y1 = r * sinf(tmp_angle * M_PI / 180);
	tmp[0] = floor((cube->j1.posx + x1 + 5) / 10);
	tmp[1] = floor((cube->j1.posy + y1 + 5) / 10);
	cube->raypos[0] = (cube->j1.posx + x1 + 5) / 10;
	cube->raypos[1] = (cube->j1.posy + y1 + 5) / 10;
	if ((tmp[0] >= 0) && (tmp[1] >= 0) && \
		(cube->map[(int)tmp[1]][(int)tmp[0]] == '1'))
		return (wich_wall(cube, tmp, pos[0], pos[1]), 1);
	if ((cube->map[(int)tmp[1]][(int)pos[0]] == '1') || \
		(cube->map[(int)pos[1]][(int)tmp[0]] == '1') || \
		(cube->map[(int)tmp[1]][(int)tmp[0]] == '1'))
		return (wich_wall(cube, tmp, pos[0], pos[1]), 1);
	return (0);
}

static	double	find_angle(t_data *cube, double tmp_angle)
{
	return (fabs(tmp_angle - cube->j1.player_angle));
}

static void	raycast(t_data *cube, double r, int index, double tmp_angle)
{
	double	limit;
	int		jdex;

	jdex = 0;
	limit = floor((1 / (r * cosf(tmp_angle * M_PI / 180))) * 4000);
	cube->limit = limit;
	while (jdex <= WINHEIGHT)
	{
		if ((jdex > (WINHEIGHT / 2) - limit) && \
			(jdex < (WINHEIGHT / 2) + limit))
			draw_textures(cube, index, jdex);
		else if ((jdex <= (WINHEIGHT / 2) - limit))
			my_mlx_pixel_put(cube, index, jdex, cube->p->ceiling);
		else if ((jdex >= (WINHEIGHT / 2) + limit))
			my_mlx_pixel_put(cube, index, jdex, cube->p->floor);
		jdex++;
	}
}
