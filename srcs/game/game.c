/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 23:10:35 by cprojean          #+#    #+#             */
/*   Updated: 2023/10/10 13:57:21 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	do_cube(t_data cube)
{
	cube.mlx_ptr = mlx_init();
	if (cube.mlx_ptr == 0x0)
		exit(1);
	cube.mlx_win = mlx_new_window(cube.mlx_ptr, WINWIDTH, WINHEIGHT, "cub3d");
	cube.img_ptr = mlx_new_image(cube.mlx_ptr, WINWIDTH, WINHEIGHT);
	cube.img_addr = mlx_get_data_addr(cube.img_ptr, &cube.bits_per_pixel, \
	&cube.line_length, &cube.endian);
	cube.count = 0;
	draw_map2D(&cube);
	draw_player(&cube);
	mlx_put_image_to_window(cube.mlx_ptr, cube.mlx_win, cube.img_ptr, 0, 0);
	mlx_hook(cube.mlx_win, 2, (1L << 0), moove_keys, &cube);
	mlx_hook(cube.mlx_win, 3, (1L << 1), release_keys, &cube);
	mlx_loop_hook(cube.mlx_ptr, loop, &cube);
	mlx_hook(cube.mlx_win, ON_DESTROY, 0, close_window, &cube);
	mlx_loop(cube.mlx_ptr);
	mlx_destroy_image(cube.mlx_ptr, cube.img_ptr);
	mlx_destroy_window(cube.mlx_ptr, cube.mlx_win);
	free(cube.mlx_ptr);
}

t_player	init_player(int index, int jdex, char c)
{
	t_player	j1;

	if (c == 'N')
		j1.player_angle = 270;
	if (c == 'E')
		j1.player_angle = 0;
	if (c == 'S')
		j1.player_angle = 90;
	if (c == 'W')
		j1.player_angle = 180;
	j1.posx = index * 10;
	j1.posy = jdex * 10;
	j1.cam_dx = cos(j1.player_angle * M_PI) * 5;
	j1.cam_dy = sin(j1.player_angle * M_PI) * 5;
	return (j1);
}
