/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 23:10:35 by cprojean          #+#    #+#             */
/*   Updated: 2023/10/23 12:46:02 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	do_cube(t_data cube)
{
	t_frame	window;

	ft_bzero(&window, sizeof(t_frame));
	window.mlx_ptr = mlx_init();
	if (window.mlx_ptr == 0x0)
		exit(1);
	window.mlx_win = mlx_new_window(window.mlx_ptr, WINWIDTH, WINHEIGHT, "cub3d");
	window.img_ptr = mlx_new_image(window.mlx_ptr, WINWIDTH, WINHEIGHT);
	window.img_addr = mlx_get_data_addr(window.img_ptr, &window.bits_per_pixel, \
	&window.line_length, &window.endian);
	cube.count = 0;
	cube.window = window;
	open_textures(&cube);
	draw_map2D(&cube);
	draw_player(&cube);
	mlx_put_image_to_window(window.mlx_ptr, window.mlx_win, window.img_ptr, 0, 0);
	mlx_hook(window.mlx_win, 2, (1L << 0), press_keys, &cube);
	mlx_hook(window.mlx_win, 3, (1L << 1), release_keys, &cube);
	mlx_loop_hook(window.mlx_ptr, loop, &cube);
	mlx_hook(window.mlx_win, ON_DESTROY, 0, close_window, &cube);
	mlx_loop(window.mlx_ptr);
	mlx_destroy_image(window.mlx_ptr, window.img_ptr);
	mlx_destroy_window(window.mlx_ptr, window.mlx_win);
	free(window.mlx_ptr);
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
	j1.cam_dx = cos(j1.player_angle * M_PI / 180);
	j1.cam_dy = sin(j1.player_angle * M_PI / 180);
	j1.vect[0] = j1.cam_dx;
	j1.vect[1] = j1.cam_dy;
	j1.fov = 80;
	return (j1);
}
