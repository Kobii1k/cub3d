/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 20:58:44 by cprojean          #+#    #+#             */
/*   Updated: 2023/10/30 09:33:21 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	my_mlx_pixel_put(t_data *cube, int x, int y, int color)
{
	int	*addr;

	if (x < 0 || y < 0 || x > WINWIDTH || y > WINHEIGHT)
		return ;
	addr = (int *)cube->window.img_addr;
	addr[y * WINWIDTH + x] = color;
}

int	my_mlx_pixel_get(t_frame *image, int x, int y)
{
	char	*dst;

	if (x < 0 || y < 0)
		return (-1);
	dst = image->img_addr + (y * image->line_length + x * \
			(image->bits_per_pixel / 8));
	return (*(unsigned int *) dst);
}

int	display_game(t_data *cube)
{
	// mlx_clear_window(cube->mlx_ptr, cube->mlx_win);
	mlx_destroy_image(cube->window.mlx_ptr, cube->window.img_ptr);
	cube->window.img_ptr = \
		mlx_new_image(cube->window.mlx_ptr, WINWIDTH, WINHEIGHT);
	cube->window.img_addr = mlx_get_data_addr(cube->window.img_ptr, \
	&cube->window.bits_per_pixel, \
	&cube->window.line_length, &cube->window.endian);
	draw_raycast(cube);
	draw_map2D(cube);
	draw_player(cube);
	draw_vision(cube);
	mlx_put_image_to_window(cube->window.mlx_ptr, cube->window.mlx_win, \
	cube->window.img_ptr, 0, 0);
	return (0);
}
