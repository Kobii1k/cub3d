/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagne <mgagne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 23:10:35 by cprojean          #+#    #+#             */
/*   Updated: 2023/11/14 14:41:28 by mgagne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	init_textures(t_data *cube);

void	get_player(t_data *cube)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < cube->height)
	{
		x = 0;
		while (cube->map[y][x])
		{
			if (ft_isalpha(cube->map[y][x]) == 1)
			{
				cube->j1 = init_player(x, y, cube->map[y][x]);
				return ;
			}
			x++;
		}
		y++;
	}
	return ;
}

int	do_cube(t_data *cube)
{
	t_frame	window;

	ft_bzero(&window, sizeof(t_frame));
	window.mlx_ptr = mlx_init();
	if (window.mlx_ptr == 0x0)
		return (printf("error\n"), free_parse(cube->p, NULL, 1),
			free(cube->keys), free_map(cube), free(cube), -1);
	window.mlx_win = mlx_new_window(window.mlx_ptr, \
		WINWIDTH, WINHEIGHT, "cub3d");
	window.img_ptr = mlx_new_image(window.mlx_ptr, WINWIDTH, WINHEIGHT);
	window.img_addr = mlx_get_data_addr(window.img_ptr, &window.bits_per_pixel, \
	&window.line_length, &window.endian);
	cube->window = window;
	if (init_textures(cube) != 0)
		return (printf("error in textures\n"), -1);
	get_player(cube);
	display_game(cube);
	mlx_hook(window.mlx_win, 2, (1L << 0), press_keys, cube);
	mlx_hook(window.mlx_win, 3, (1L << 1), release_keys, cube);
	mlx_loop_hook(window.mlx_ptr, loop, cube);
	mlx_hook(window.mlx_win, ON_DESTROY, 0, close_window, cube);
	mlx_loop(window.mlx_ptr);
	mlx_destroy_image(window.mlx_ptr, window.img_ptr);
	mlx_destroy_window(window.mlx_ptr, window.mlx_win);
	return (free(window.mlx_ptr), 0);
}

t_player	init_player(int index, int jdex, char c)
{
	t_player	j1;

	if (c == 'N')
		j1.player_angle = 270;
	if (c == 'S')
		j1.player_angle = 90;
	if (c == 'E')
		j1.player_angle = 0;
	if (c == 'W')
		j1.player_angle = 180;
	j1.posx = index * 10;
	j1.posy = jdex * 10;
	j1.cam_dx = cos(j1.player_angle * M_PI / 180);
	j1.cam_dy = sin(j1.player_angle * M_PI / 180);
	j1.vect[0] = j1.cam_dx;
	j1.vect[1] = j1.cam_dy;
	j1.fov = 60;
	return (j1);
}

int	init_textures(t_data *cube)
{
	int	situation;

	situation = 0;
	situation = open_textures(cube);
	if (situation > 1)
		return (free_textures(cube, situation), -1);
	else if (situation < 0)
		return (free_textures(cube, 5), -1);
	return (0);
}
