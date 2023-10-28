/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:42:18 by cprojean          #+#    #+#             */
/*   Updated: 2023/10/28 17:01:39 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

float	ft_modf(float nbr, int div);

void    open_textures(t_data *cube)
{
	int	size;

	size = 100;
    cube->ntexture.img_ptr = mlx_xpm_file_to_image(cube->window.mlx_ptr, cube->p->north, &size, &size);
	cube->ntexture.img_addr = mlx_get_data_addr(cube->ntexture.img_ptr, &cube->ntexture.bits_per_pixel, &cube->ntexture.line_length, &cube->ntexture.endian);
	
    cube->stexture.img_ptr = mlx_xpm_file_to_image(cube->window.mlx_ptr, cube->p->south, &size, &size);
	cube->stexture.img_addr = mlx_get_data_addr(cube->stexture.img_ptr, &cube->stexture.bits_per_pixel, &cube->stexture.line_length, &cube->stexture.endian);
	
    cube->etexture.img_ptr = mlx_xpm_file_to_image(cube->window.mlx_ptr, cube->p->east, &size, &size);
	cube->etexture.img_addr = mlx_get_data_addr(cube->etexture.img_ptr, &cube->etexture.bits_per_pixel, &cube->etexture.line_length, &cube->etexture.endian);

    cube->wtexture.img_ptr = mlx_xpm_file_to_image(cube->window.mlx_ptr, cube->p->west, &size, &size);
	cube->wtexture.img_addr = mlx_get_data_addr(cube->wtexture.img_ptr, &cube->wtexture.bits_per_pixel, &cube->wtexture.line_length, &cube->wtexture.endian);
}

void	wich_wall(t_data *cube, double tmpx, double tmpy, double posx, double posy)
{
	if (cube->map[(int)tmpy][(int)posx] == '1')
	{
		if (tmpy > posy)
			cube->ray = 'N';
		else
			cube->ray = 'S';
	}
	if (cube->map[(int)posy][(int)tmpx] == '1')
	{
		if (tmpx > posx)
			cube->ray = 'W';
		else
			cube->ray = 'E';
	}
}

float	ft_modf(float nbr, int div)
{
	int	i;
	
	i = nbr / div;
	nbr -= div * i;
	return (nbr);
}

void	draw_textures(t_data *cube, double index, double jdex)
{
	// double	ratio;
	int		pos_pix[2];
	
	if (cube->ray == 'S')
	{
		pos_pix[0] = (cube->raypos[0] - floor(cube->raypos[0])) * 200;
		// ratio = cube->limit / 200;
		// pos_pix[1] = (jdex - (((WINHEIGHT / 2) - cube->limit)) * 200 / cube->limit);
		pos_pix[1] = ((jdex - ((1080 / 2) - cube->limit)) * 200) / cube->limit / 2;
		my_mlx_pixel_put(cube, (int)index, (int)jdex, my_mlx_pixel_get(&cube->stexture, pos_pix[0], pos_pix[1]));
	}
	if (cube->ray == 'N')
	{
		pos_pix[0] = (cube->raypos[0] - floor(cube->raypos[0])) * 200;
		pos_pix[0] = 199 - pos_pix[0]; 
		pos_pix[1] =  (((jdex - ((1080 / 2) - cube->limit)) * 200) / cube->limit / 2);
		my_mlx_pixel_put(cube, (int)index, (int)jdex, my_mlx_pixel_get(&cube->ntexture, pos_pix[0], pos_pix[1]));
		// my_mlx_pixel_put(cube, (int)index, (int)jdex, 0xFF0000);
	}
	if (cube->ray == 'E')
	{
		pos_pix[0] = (cube->raypos[1] - floor(cube->raypos[1])) * 200;
		pos_pix[0] = 199 - pos_pix[0]; 
		pos_pix[1] =  (((jdex - ((1080 / 2) - cube->limit)) * 200) / cube->limit / 2);
		my_mlx_pixel_put(cube, (int)index, (int)jdex, my_mlx_pixel_get(&cube->etexture, pos_pix[0], pos_pix[1]));
		// my_mlx_pixel_put(cube, (int)index, (int)jdex, 0xFFFFFF);
	}
	if (cube->ray == 'W')
	{
		pos_pix[0] = (cube->raypos[1] - floor(cube->raypos[1])) * 200;
		pos_pix[1] =  (((jdex - ((1080 / 2) - cube->limit)) * 200) / cube->limit / 2);
		my_mlx_pixel_put(cube, (int)index, (int)jdex, my_mlx_pixel_get(&cube->wtexture, pos_pix[0], pos_pix[1]));
		// my_mlx_pixel_put(cube, (int)index, (int)jdex, 0x0000FF);
	}
}
