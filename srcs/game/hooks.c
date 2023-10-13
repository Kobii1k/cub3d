/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:12:16 by cprojean          #+#    #+#             */
/*   Updated: 2023/10/13 10:27:26 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	is_wall(t_data *cube, int mode, int value);
int	release_keys(int key, t_data *cube);

int	moove_keys(int key, t_data *cube)
{
	if (key == W)
		cube->keys[Wk] = 1;
	else if (key == S)
		cube->keys[Sk] = 1;
	else if (key == A)
		cube->keys[Ak] = 1;
	else if (key == D)
		cube->keys[Dk] = 1;
	else if (key == ESC)
	{
		close_window(cube);
		exit (0);
	}
	if (key == LEFT_ARR)
		cube->keys[LEFT_ARRk] = 1;
	else if (key == RIGHT_ARR)
		cube->keys[RIGHT_ARRk] = 1;
	return (key);
}

int	release_keys(int key, t_data *cube)
{
	if (key == W)
		cube->keys[Wk] = 0;
	else if (key == S)
		cube->keys[Sk] = 0;
	else if (key == A)
		cube->keys[Ak] = 0;
	else if (key == D)
		cube->keys[Dk] = 0;
	else if (key == LEFT_ARR)
		cube->keys[LEFT_ARRk] = 0;
	else if (key == RIGHT_ARR)
		cube->keys[RIGHT_ARRk] = 0;
	return (key);
}

int	is_wall(t_data *cube, int mode, int value)
{
	int	modif;
	int	tmpx;
	int	tmpy;

	tmpx = 0;
	tmpy = 0;
	if (mode == 0)
		modif = cube->j1.posx;
	else
		modif = cube->j1.posy;
	modif = modif + value;
	if (value > 0)
	{
		if (mode == 0)
		{
			tmpx = floor((modif + 5) / 10);
			tmpy = floor((cube->j1.posy + 5) / 10);
		}
		else if (mode == 1)
		{
			tmpx = floor((cube->j1.posx + 5) / 10);
			tmpy = floor((modif + 5) / 10);
		}
	}
	else
	{
		if (mode == 0)
		{
			tmpx = floor((modif) / 10);
			tmpy = floor((cube->j1.posy) / 10);
		}
		else if (mode == 1)
		{
			tmpx = floor((cube->j1.posx) / 10);
			tmpy = floor((modif) / 10);
		}
	}
	if (cube->map[tmpy][tmpx] == '1')
		return (1);
	return (0);
}

int	loop(t_data *cube)
{
	if (cube->keys[Wk] == 1 && is_wall(cube, 1, -2) == 0)
		cube->j1.posy += -2;
	if (cube->keys[Sk] == 1 && is_wall(cube, 1, +2) == 0)
		cube->j1.posy += 2;
	if (cube->keys[Ak] == 1 && is_wall(cube, 0, -2) == 0)
		cube->j1.posx += -2;
	if (cube->keys[Dk] == 1 && is_wall(cube, 0, +2) == 0)
		cube->j1.posx += 2;
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
	display_game(cube);
	return (0);
}

int	close_window(t_data *cube)
{
	int	index;

	index = 0;
	mlx_destroy_image(cube->mlx_ptr, cube->img_ptr);
	mlx_destroy_window(cube->mlx_ptr, cube->mlx_win);
	// mlx_destroy_display(cube->mlx_ptr);
	while (index < cube->height)
	{
		free(cube->map[index]);
		index++;
	}
	free(cube->map);
	free(cube->mlx_ptr);
	free(cube->keys);
	// free(cube);
	exit (0);
}
