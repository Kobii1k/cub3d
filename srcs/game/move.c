/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:02:10 by cprojean          #+#    #+#             */
/*   Updated: 2023/10/17 14:57:05 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	move_up(t_data *cube)
{
    cube->j1.cam_dx = cosf(cube->j1.player_angle * M_PI / 180);
	cube->j1.cam_dy = sinf(cube->j1.player_angle * M_PI / 180);
    cube->j1.posy += cube->j1.cam_dy;
    cube->j1.posx += cube->j1.cam_dx;
}

void	move_down(t_data *cube)
{
    cube->j1.cam_dx = cosf(cube->j1.player_angle * M_PI / 180);
	cube->j1.cam_dy = sinf(cube->j1.player_angle * M_PI / 180);
    cube->j1.posy -= cube->j1.cam_dy;
    cube->j1.posx -= cube->j1.cam_dx;
}
void	move_right(t_data *cube)
{
    cube->j1.cam_dx = cosf((cube->j1.player_angle + 90) * M_PI / 180);
	cube->j1.cam_dy = sinf((cube->j1.player_angle + 90) * M_PI / 180);
    cube->j1.posy += cube->j1.cam_dy;
    cube->j1.posx += cube->j1.cam_dx;
}
void	move_left(t_data *cube)
{
    cube->j1.cam_dx = cosf((cube->j1.player_angle + 90) * M_PI / 180);
	cube->j1.cam_dy = sinf((cube->j1.player_angle + 90) * M_PI / 180);
    cube->j1.posy -= cube->j1.cam_dy;
    cube->j1.posx -= cube->j1.cam_dx;
}   
