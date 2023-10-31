/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:02:10 by cprojean          #+#    #+#             */
/*   Updated: 2023/10/29 16:56:34 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	move_up(t_data *cube)
{
	double	cam_dx;
	double	cam_dy;

	cam_dx = cosf(cube->j1.player_angle * M_PI / 180);
	cam_dy = sinf(cube->j1.player_angle * M_PI / 180);
	if (is_wall(cube, cube->j1.posx + cam_dx, cube->j1.posy) == 0)
	{
		cube->j1.cam_dx = cam_dx;
		cube->j1.posx += cube->j1.cam_dx;
	}
	if (is_wall(cube, cube->j1.posx, cube->j1.posy + cam_dy) == 0)
	{
		cube->j1.cam_dy = cam_dy;
		cube->j1.posy += cube->j1.cam_dy;
	}
}

void	move_down(t_data *cube)
{
	double	cam_dx;
	double	cam_dy;

	cam_dx = cosf(cube->j1.player_angle * M_PI / 180);
	cam_dy = sinf(cube->j1.player_angle * M_PI / 180);
	if (is_wall(cube, cube->j1.posx - cam_dx, cube->j1.posy) == 0)
	{
		cube->j1.cam_dx = cam_dx;
		cube->j1.posx -= cube->j1.cam_dx;
	}
	if (is_wall(cube, cube->j1.posx, cube->j1.posy - cam_dy) == 0)
	{
		cube->j1.cam_dy = cam_dy;
		cube->j1.posy -= cube->j1.cam_dy;
	}
}

void	move_right(t_data *cube)
{
	double	cam_dx;
	double	cam_dy;

	cam_dx = cosf((cube->j1.player_angle + 90) * M_PI / 180);
	cam_dy = sinf((cube->j1.player_angle + 90) * M_PI / 180);
	if (is_wall(cube, cube->j1.posx + cam_dx, cube->j1.posy) == 0)
	{
		cube->j1.cam_dx = cam_dx;
		cube->j1.posx += cube->j1.cam_dx;
	}
	if (is_wall(cube, cube->j1.posx, cube->j1.posy + cam_dy) == 0)
	{
		cube->j1.cam_dy = cam_dy;
		cube->j1.posy += cube->j1.cam_dy;
	}
}

void	move_left(t_data *cube)
{
	double	cam_dx;
	double	cam_dy;

	cam_dx = cosf((cube->j1.player_angle + 90) * M_PI / 180);
	cam_dy = sinf((cube->j1.player_angle + 90) * M_PI / 180);
	if (is_wall(cube, cube->j1.posx - cam_dx, cube->j1.posy) == 0)
	{
		cube->j1.cam_dx = cam_dx;
		cube->j1.posx -= cube->j1.cam_dx;
	}
	if (is_wall(cube, cube->j1.posx, cube->j1.posy - cam_dy) == 0)
	{
		cube->j1.cam_dy = cam_dy;
		cube->j1.posy -= cube->j1.cam_dy;
	}
}
