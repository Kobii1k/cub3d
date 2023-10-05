/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 23:10:35 by cprojean          #+#    #+#             */
/*   Updated: 2023/10/04 13:53:40 by cprojean         ###   ########.fr       */
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
	mlx_hook(cube.mlx_win, ON_DESTROY, 0, close_window, &cube);
	mlx_loop(cube.mlx_ptr);
	mlx_destroy_image(cube.mlx_ptr, cube.img_ptr);
	mlx_destroy_window(cube.mlx_ptr, cube.mlx_win);
	free(cube.mlx_ptr);
}

t_player	init_player(int index, int jdex)
{
	t_player	j1;

	j1.posx = index * 10;
	j1.posy = jdex * 10;
	return (j1);
}
