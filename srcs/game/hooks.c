/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:12:16 by cprojean          #+#    #+#             */
/*   Updated: 2023/10/16 16:13:17 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int		is_wall(t_data *cube, int mode, int value);
int		release_keys(int key, t_data *cube);
void	add_vect(t_data *cube, int x, int y);

int	press_keys(int key, t_data *cube)
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

void	add_vect(t_data *cube, int x, int y)
{
	int	vect[2];

	vect[0] = x;
	vect[1] = y;
	printf("BEFORE : x %f, x : %d\n", cube->j1.vect[0], vect[0]);
	printf("BEFORE : y %f, y : %d\n", cube->j1.vect[1], vect[1]);
	cube->j1.vect[0] = cos((cube->j1.vect[0] + vect[0]) * cube->j1.player_angle);
	cube->j1.vect[1] = sin((cube->j1.vect[1] + vect[1]) * cube->j1.player_angle);
	cube->j1.posx = floor(cube->j1.posx + cube->j1.vect[0]);
	cube->j1.posy = floor(cube->j1.posy + cube->j1.vect[1]);
	printf("ADD : x %f, y : %f\n", cube->j1.vect[0], cube->j1.vect[1]);
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
