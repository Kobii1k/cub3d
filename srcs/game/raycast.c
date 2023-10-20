/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 13:07:32 by cprojean          #+#    #+#             */
/*   Updated: 2023/10/20 16:53:12 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

// static void	raycast(t_data *cube, double r, int index, double tmp_angle);
static	double	find_angle(t_data *cube, double tmp_angle);
static void	raycast(t_data *cube, double r, int index, double tmp_angle, double hyp);
static double	hyp_size(t_data *cube, double tmp_angle, double r);
static int	test_angle(t_data *cube, double tmp_angle, double r);

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
				raycast(cube, r, index, find_angle(cube, tmp_angle), hyp_size(cube, tmp_angle, r));
				break ;
			}
			if (test_angle(cube, tmp_angle, r + 1) == 1)
				r += 0.01;
			else
				r += 1;
		}
		index++;
		tmp_angle += (double)cube->j1.fov/WINWIDTH;
	}
}

static int	test_angle(t_data *cube, double tmp_angle, double r)
{
	double	x1;
	double	y1;
	double	tmpx;
	double	tmpy;
	double	posx;
	double	posy;
	
	x1 = (r - 1) * cosf(tmp_angle * M_PI / 180);
	y1 = (r - 1) * sinf(tmp_angle * M_PI / 180);
	posx = (cube->j1.posx + x1 + 5) / 10;
	posy = (cube->j1.posy + y1 + 5) / 10;
	x1 = r * cosf(tmp_angle * M_PI / 180);
	y1 = r * sinf(tmp_angle * M_PI / 180);
	tmpx = floor((cube->j1.posx + x1 + 5) / 10);
	tmpy = floor((cube->j1.posy + y1 + 5) / 10);
	if ((tmpx >= 0) && (tmpy >= 0) && (cube->map[(int)tmpy][(int)tmpx] == '1'))
		return (1);
	else
	{
		if ((cube->map[(int)tmpy][(int)posx] == '1') && (cube->map[(int)posy][(int)tmpx] == '1'))
			return (1);
		return (0);
	}
}

static double	hyp_size(t_data *cube, double tmp_angle, double r)
{
	double	hyp;
	double	x1;
	double	y1;
	double	tmpx;
	double	tmpy;

	x1 = r * cosf(tmp_angle * M_PI / 180);
	y1 = r * sinf(tmp_angle * M_PI / 180);
	tmpx = floor((cube->j1.posx + x1 + 5) / 10);
	tmpy = floor((cube->j1.posy + y1 + 5) / 10);
	// printf("x pers %f, x coli %f\n", (cube->j1.posx + 5) / 10, tmpx); 
	hyp = sqrtl(powl(((cube->j1.posx + 5) / 10) - tmpx, 2) + powl(((cube->j1.posy + 5) / 10) - tmpy, 2));
	if (tmp_angle == cube->j1.player_angle)
		printf("hyp %f\n", hyp);
	return (hyp);
}

static	double	find_angle(t_data *cube, double tmp_angle)
{
	return (fabs(tmp_angle - cube->j1.player_angle));
}

static void	raycast(t_data *cube, double r, int index, double tmp_angle, double hyp)
{
	double	limit;
	int		jdex;
	// double	dist;
	(void) hyp;
	(void) r;
	jdex = 0;
	// dist = (double) hyp * cosf(tmp_angle * M_PI / 180);
	// printf("angle : %f\n", tmp_angle);
	// printf("player angle : %f\n", cube->j1.player_angle);
	// printf("hyp : %f opp : %f r : %f\n", hyp, hyp * sinf(tmp_angle * M_PI / 180), r);
	// printf("limit : %f\n", limit);
	// limit = (1 / dist) * 500;
	// printf("limit : %f\n", limit);
	// limit = (double)((1 / dist) * 100 * 2);
	// printf("size hypothenuse %f, other : %f\n", limit, floor((1 / r) * 1000));
	// limit = floor((1 / r) * 1000);
	limit = floor((1 / (r * cosf(tmp_angle * M_PI / 180))) * 1000);
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
