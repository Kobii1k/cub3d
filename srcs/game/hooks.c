/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:12:16 by cprojean          #+#    #+#             */
/*   Updated: 2023/10/03 14:18:53 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	moove_keys(int key, t_data *cube)
{
	(void) cube;
	ft_printf("key : %d\n", key);
	if (key == W)
		cube->j1->posy += -5;
	else if (key == S)
		cube->j1->posy += 5;
	else if (key == A)
		cube->j1->posx += -5;
	else if (key == D)
		cube->j1->posx += 5;
	if (key == W || key == S || key == A || key == D)
	{
		mlx_destroy_image(cube->mlx_ptr, cube->img_ptr);
		cube->img_ptr = mlx_new_image(cube->mlx_ptr, WINWIDTH, WINHEIGTH);
		draw_map2D(cube);
		draw_player(cube);
	}
	else if (key == ESC)
	{
		close_window(cube);
		exit (0);
	}
	return (key);
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
