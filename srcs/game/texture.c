/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:42:18 by cprojean          #+#    #+#             */
/*   Updated: 2023/10/30 09:31:42 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static int	next_open_textures(t_data *cube);
static void	put_texture(t_data *cube, double index, \
			double jdex, int pos_pix[2]);

int	open_textures(t_data *cube)
{
	cube->ntexture.img_ptr = mlx_xpm_file_to_image(cube->window.mlx_ptr, \
		cube->p->north, &cube->ntexture.sizex, &cube->ntexture.sizey);
	cube->ntexture.img_addr = mlx_get_data_addr(cube->ntexture.img_ptr, \
		&cube->ntexture.bits_per_pixel, &cube->ntexture.line_length, \
		&cube->ntexture.endian);
	if (cube->ntexture.sizex != 200 || cube->ntexture.sizey != 200)
		return (-1);
	cube->stexture.img_ptr = mlx_xpm_file_to_image(cube->window.mlx_ptr, \
		cube->p->south, &cube->stexture.sizex, &cube->stexture.sizey);
	cube->stexture.img_addr = mlx_get_data_addr(cube->stexture.img_ptr, \
	&cube->stexture.bits_per_pixel, &cube->stexture.line_length, \
	&cube->stexture.endian);
	if (cube->stexture.sizex != 200 || cube->stexture.sizey != 200)
		return (-1);
	return (next_open_texture(cube));
}

static int	next_open_textures(t_data *cube)
{
	cube->etexture.img_ptr = mlx_xpm_file_to_image(cube->window.mlx_ptr, \
		cube->p->east, &cube->etexture.sizex, &cube->etexture.sizex);
	cube->etexture.img_addr = mlx_get_data_addr(cube->etexture.img_ptr, \
		&cube->etexture.bits_per_pixel, &cube->etexture.line_length, \
		&cube->etexture.endian);
	if (cube->etexture.sizex != 200 || cube->etexture.sizex != 200)
		return (-1);
	cube->wtexture.img_ptr = mlx_xpm_file_to_image(cube->window.mlx_ptr, \
		cube->p->west, &cube->wtexture.sizex, &cube->wtexture.sizey);
	cube->wtexture.img_addr = mlx_get_data_addr(cube->wtexture.img_ptr, \
		&cube->wtexture.bits_per_pixel, &cube->wtexture.line_length, \
		&cube->wtexture.endian);
	if (cube->wtexture.sizex != 200 || cube->wtexture.sizey != 200)
		return (-1);
	return (0);
}

void	wich_wall(t_data *cube, double tmp[2], double posx, double posy)
{
	if (cube->map[(int)tmp[1]][(int)posx] == '1')
	{
		if (tmp[1] > posy)
			cube->ray = 'N';
		else
			cube->ray = 'S';
	}
	if (cube->map[(int)posy][(int)tmp[0]] == '1')
	{
		if (tmp[0] > posx)
			cube->ray = 'W';
		else
			cube->ray = 'E';
	}
}

void	draw_textures(t_data *cube, double index, double jdex)
{
	int		pos_pix[2];

	pos_pix[1] = \
		(((jdex - ((1080 / 2) - cube->limit)) * 200) / cube->limit / 2);
	if (cube->ray == 'S')
	{
		pos_pix[0] = (cube->raypos[0] - floor(cube->raypos[0])) * 200;
	}
	if (cube->ray == 'N')
	{
		pos_pix[0] = (cube->raypos[0] - floor(cube->raypos[0])) * 200;
		pos_pix[0] = cube->ntexture.sizex - 1 - pos_pix[0];
	}
	if (cube->ray == 'E')
	{
		pos_pix[0] = (cube->raypos[1] - floor(cube->raypos[1])) * 200;
		pos_pix[0] = cube->etexture.sizex - 1 - pos_pix[0];
	}
	if (cube->ray == 'W')
	{
		pos_pix[0] = (cube->raypos[1] - floor(cube->raypos[1])) * 200;
	}
	put_texture(cube, index, jdex, pos_pix);
}

static void	put_texture(t_data *cube, double index, double jdex, int pos_pix[2])
{
	if (cube->ray == 'N')
		my_mlx_pixel_put(cube, (int)index, (int)jdex, \
		my_mlx_pixel_get(&cube->ntexture, pos_pix[0], pos_pix[1]));
	if (cube->ray == 'S')
		my_mlx_pixel_put(cube, (int)index, (int)jdex, \
		my_mlx_pixel_get(&cube->stexture, pos_pix[0], pos_pix[1]));
	if (cube->ray == 'E')
		my_mlx_pixel_put(cube, (int)index, (int)jdex, \
		my_mlx_pixel_get(&cube->etexture, pos_pix[0], pos_pix[1]));
	if (cube->ray == 'W')
		my_mlx_pixel_put(cube, (int)index, (int)jdex, \
		my_mlx_pixel_get(&cube->wtexture, pos_pix[0], pos_pix[1]));
}
