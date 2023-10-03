/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagne <mgagne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 23:10:35 by cprojean          #+#    #+#             */
/*   Updated: 2023/10/03 16:08:03 by mgagne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	do_cube(t_data cube)
{
	t_player	j1;

	// init_cube(cube);
	ft_bzero(&j1, sizeof(t_player));
	j1 = init_player(&j1);
	cube.j1 = &j1;
	cube.mlx_ptr = mlx_init();
	if (cube.mlx_ptr == 0x0)
		exit(1);
	cube.mlx_win = mlx_new_window(cube.mlx_ptr, WINWIDTH, WINHEIGTH, "cub3d");
	cube.img_ptr = mlx_new_image(cube.mlx_ptr, WINWIDTH, WINHEIGTH);
	cube.img_addr = mlx_get_data_addr(cube.img_ptr, &cube.bits_per_pixel, \
	&cube.line_length, &cube.endian);
	draw_map2D(&cube);
	draw_player(&cube);
	mlx_hook(cube.mlx_win, 2, (1L << 0), moove_keys, &cube);
	mlx_hook(cube.mlx_win, ON_DESTROY, 0, close_window, &cube);
	mlx_loop(cube.mlx_ptr);
	mlx_destroy_image(cube.mlx_ptr, cube.img_ptr);
	mlx_destroy_window(cube.mlx_ptr, cube.mlx_win);
	free(cube.mlx_ptr);
}

t_player	init_player(t_player *j1)
{
	j1->posx = 150;
	j1->posy = 150;
	return (*j1);
}
