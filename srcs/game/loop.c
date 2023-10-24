/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:23:38 by cprojean          #+#    #+#             */
/*   Updated: 2023/10/17 14:53:01 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

// static void    choose_direction(t_data *cube);

int	loop(t_data *cube)
{
	if (cube->keys[Wk] == 1)
		move_up(cube);
	if (cube->keys[Sk] == 1)
		move_down(cube);
	if (cube->keys[Ak] == 1)
		move_left(cube);
	if (cube->keys[Dk] == 1)
		move_right(cube);
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
	// printf("%f, %f\n", cube->j1.cam_dx, cube->j1.cam_dy);
	display_game(cube);
	return (0);
}
