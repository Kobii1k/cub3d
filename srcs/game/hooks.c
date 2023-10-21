/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:12:16 by cprojean          #+#    #+#             */
/*   Updated: 2023/10/21 14:26:30 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int		release_keys(int key, t_data *cube);
int	is_wall(t_data *cube, double posx, double posy);
// void	add_vect(t_data *cube);

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

int	is_wall(t_data *cube, double posx, double posy)
{
	if (posy <= 0 || posx <= 0)
		return (1);
	posx = floor(posx + 5) / 10;
	posy = floor(posy + 5) / 10;
	if (cube->map[(int)posy][(int)posx] == '1')
		return (1);
	return (0);
}

int	close_window(t_data *cube)
{
	int	index;

	index = 0;
	mlx_destroy_image(cube->window.mlx_ptr, cube->window.img_ptr);
	mlx_destroy_window(cube->window.mlx_ptr, cube->window.mlx_win);
	// mlx_destroy_display(cube->window.mlx_ptr);
	while (index < cube->height)
	{
		free(cube->map[index]);
		index++;
	}
	free(cube->map);
	free(cube->keys);
	free(cube->window.mlx_ptr);
	// free(cube);
	exit (0);
}
