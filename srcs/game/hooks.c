/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:12:16 by cprojean          #+#    #+#             */
/*   Updated: 2023/10/07 21:21:42 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	is_wall(t_data *cube, int mode, int value);
int	camera(int key, t_data *cube);

int	moove_keys(int key, t_data *cube)
{
	ft_printf("key : %d\n", key);
	if (key == W && is_wall(cube, 1, -5) == 0)
		cube->j1.posy += -5;
	else if (key == S && is_wall(cube, 1, +5) == 0)
		cube->j1.posy += 5;
	else if (key == A && is_wall(cube, 0, -5) == 0)
		cube->j1.posx += -5;
	else if (key == D && is_wall(cube, 0, +5) == 0)
		cube->j1.posx += 5;
	else if (key == ESC)
	{
		close_window(cube);
		exit (0);
	}
	return (camera(key, cube));
}

int	camera(int	key, t_data *cube)
{
	if (key == LEFT_ARR)
	{
		cube->j1.player_angle -= 3;
		if (cube->j1.player_angle < 0)
			cube->j1.player_angle = 360;
	}
	else if (key == RIGHT_ARR)
	{
		cube->j1.player_angle += 3;
		if (cube->j1.player_angle > 360)
			cube->j1.player_angle = 0;
	}
	if (key == LEFT_ARR || key == RIGHT_ARR || \
		key == W || key == S || key == A || key == D)
		display_game(cube);
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

int	close_window(t_data *cube)
{
	int	index;

	index = 0;
	mlx_destroy_image(cube->mlx_ptr, cube->img_ptr);
	mlx_destroy_window(cube->mlx_ptr, cube->mlx_win);
	// mlx_destroy_display(cube->mlx_ptr);
	while (index < 10)
	{
		free(cube->map[index]);
		index++;
	}
	free(cube->map);
	free(cube->mlx_ptr);
	// free(cube);
	exit (0);
}

 