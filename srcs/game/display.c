/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 20:58:44 by cprojean          #+#    #+#             */
/*   Updated: 2023/10/10 13:19:22 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	my_mlx_pixel_put(t_data *cube, int x, int y, int color)
{
	int	*addr;

	if (x < 0 || y < 0 || x > WINWIDTH || y > WINHEIGHT)
		return ;
	addr = (int *)cube->img_addr;
	addr[y * WINWIDTH + x] = color;
}

int	display_game(t_data *cube)
{
	// mlx_clear_window(cube->mlx_ptr, cube->mlx_win);
	mlx_destroy_image(cube->mlx_ptr, cube->img_ptr);
	cube->img_ptr = mlx_new_image(cube->mlx_ptr, WINWIDTH, WINHEIGHT);
	cube->img_addr = mlx_get_data_addr(cube->img_ptr, \
	&cube->bits_per_pixel, &cube->line_length, &cube->endian);
	draw_map2D(cube);
	draw_player(cube);
	mlx_put_image_to_window(cube->mlx_ptr, cube->mlx_win, \
	cube->img_ptr, 0, 0);
	return (0);
}
