/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:12:16 by cprojean          #+#    #+#             */
/*   Updated: 2023/10/02 17:39:19 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int     moove_keys(int key, t_data *cube)
{
	(void) cube;
	ft_printf("key : %d\n", key);
	if (key == W)
	{
		cube->j1->posy += -3;
		mlx_destroy_image(cube->mlx_ptr, cube->img_ptr);
		cube->img_ptr = mlx_new_image(cube->mlx_ptr, WINWIDTH, WINHEIGTH);
		draw_player(cube);
	}
	if (key == S)
	{
		cube->j1->posy += 3;
		mlx_destroy_image(cube->mlx_ptr, cube->img_ptr);
		cube->img_ptr = mlx_new_image(cube->mlx_ptr, WINWIDTH, WINHEIGTH);
		draw_player(cube);
	}
	if (key == A)
	{
		cube->j1->posx += -3;
		mlx_destroy_image(cube->mlx_ptr, cube->img_ptr);
		cube->img_ptr = mlx_new_image(cube->mlx_ptr, WINWIDTH, WINHEIGTH);
		draw_player(cube);
	}
	if (key == D)
	{
		cube->j1->posx += 3;
		mlx_destroy_image(cube->mlx_ptr, cube->img_ptr);
		cube->img_ptr = mlx_new_image(cube->mlx_ptr, WINWIDTH, WINHEIGTH);
		draw_player(cube);
	}
	if (key == ESC)
	{
		close_window(cube);
		exit (0);
	}
	return (key);
}

int     close_window(t_data *cube)
{
	mlx_destroy_image(cube->mlx_ptr, cube->img_ptr);
	mlx_destroy_window(cube->mlx_ptr, cube->mlx_win);
	mlx_destroy_display(cube->mlx_ptr);
	free(cube->mlx_ptr);
	exit (0);
}