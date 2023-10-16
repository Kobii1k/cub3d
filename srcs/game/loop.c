/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:23:38 by cprojean          #+#    #+#             */
/*   Updated: 2023/10/16 15:25:45 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// static void    choose_direction(t_data *cube);

int	loop(t_data *cube)
{
	cube->j1.cam_dx = cos(cube->j1.player_angle * M_PI / 180);
	cube->j1.cam_dy = sin(cube->j1.player_angle * M_PI / 180);
	if (cube->keys[Wk] == 1 && is_wall(cube, 1, -2) == 0)
		add_vect(cube, 0, -2);
	if (cube->keys[Sk] == 1 && is_wall(cube, 1, +2) == 0)
		add_vect(cube, 0, 2);
	if (cube->keys[Ak] == 1 && is_wall(cube, 0, -2) == 0)
		add_vect(cube, -2, 0);
	if (cube->keys[Dk] == 1 && is_wall(cube, 0, +2) == 0)
		add_vect(cube, 2, 0);
    // if (cube->keys[Wk] == 1 || cube->keys[Sk] == 1 || cube->keys[Ak] == 1 || cube->keys[Dk] == 1)
    //     choose_direction(cube);
	if (cube->keys[LEFT_ARRk] == 1)
	{
		cube->j1.player_angle -= 1.5;
		if (cube->j1.player_angle < 0)
			cube->j1.player_angle += 360;
	}
	if (cube->keys[RIGHT_ARRk] == 1)
	{
		cube->j1.player_angle += 1.5;
		if (cube->j1.player_angle > 360)
			cube->j1.player_angle -= 360;
	}
	printf("%f, %f\n", cube->j1.cam_dx, cube->j1.cam_dy);
	display_game(cube);
	return (0);
}

// static void    choose_direction(t_data *cube)
// {
// }
