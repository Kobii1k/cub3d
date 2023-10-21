/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:42:18 by cprojean          #+#    #+#             */
/*   Updated: 2023/10/21 16:54:31 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

double	ft_modf(double nbr, double div);

void    open_textures(t_data *cube)
{
	int	size;

	size = 100;
    cube->ntexture.img_ptr = mlx_xpm_file_to_image(cube->window.mlx_ptr, "../../img/north.xpm", &size, &size);
    cube->stexture.img_ptr = mlx_xpm_file_to_image(cube->window.mlx_ptr, "../../img/south.xpm", &size, &size);
    cube->etexture.img_ptr = mlx_xpm_file_to_image(cube->window.mlx_ptr, "../../img/east.xpm", &size, &size);
    cube->wtexture.img_ptr = mlx_xpm_file_to_image(cube->window.mlx_ptr, "../../img/west.xpm", &size, &size);
}

void	wich_wall(t_data *cube, double tmpx, double tmpy, double posx, double posy)
{
	// printf("pos %f %f\n", posx, posy);
	// printf("tmp %f %f\n", tmpx, tmpy);
	if (cube->map[(int)tmpy][(int)posx] == '1')
	{
		if (tmpy > posy)
			cube->ray = 'W';
		else
			cube->ray = 'E';
	}
	if (cube->map[(int)posy][(int)tmpx] == '1')
	{
		if (tmpx > posx)
			cube->ray = 'S';
		else
			cube->ray = 'N';
	}
}

double	ft_modf(double nbr, double div)
{
	double	mod;

	mod = 0.0;
	mod = nbr - (nbr / div);
	// printf("%f\n", mod);
	return (mod);
}

void	draw_textures(t_data *cube, double index, double jdex)
{
	// printf("raypos[0] %f\n", ft_modf(cube->raypos[0], 10) * 10);
	// printf("raypos[1] %f\n", ft_modf(cube->raypos[1], 10) * 10);
	if (cube->ray == 'S')
	{
		// my_mlx_pixel_put(cube, (int)index, (int)jdex, my_mlx_pixel_get(&cube->stexture, (int)(ft_modf(cube->raypos[0], 10) * 100), (int)(ft_modf(cube->raypos[1], 10) * 100)));
		my_mlx_pixel_put(cube, (int)index, (int)jdex, 0x00FF00);
	}
	if (cube->ray == 'N')
	{
		// printf("mesmorts\n");
		// my_mlx_pixel_put(cube, (int)index, (int)jdex, my_mlx_pixel_get(&cube->ntexture, (int)(ft_modf(cube->raypos[0], 10) * 100), (int)(ft_modf(cube->raypos[1], 10) * 100)));
		my_mlx_pixel_put(cube, (int)index, (int)jdex, 0xFF0000);
	}
	if (cube->ray == 'E')
	{
		// my_mlx_pixel_put(cube, (int)index, (int)jdex, my_mlx_pixel_get(&cube->etexture, (int)(ft_modf(cube->raypos[0], 10) * 100), (int)(ft_modf(cube->raypos[1], 10) * 100)));	
		my_mlx_pixel_put(cube, (int)index, (int)jdex, 0xFFFFFF);
	}
	if (cube->ray == 'W')
	{
		// my_mlx_pixel_put(cube, (int)index, (int)jdex, my_mlx_pixel_get(&cube->wtexture, (int)(ft_modf(cube->raypos[0], 10) * 100), (int)(ft_modf(cube->raypos[1], 10) * 100)));
		my_mlx_pixel_put(cube, (int)index, (int)jdex, 0x0000FF);
	}
}
