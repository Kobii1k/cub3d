/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 14:42:18 by cprojean          #+#    #+#             */
/*   Updated: 2023/10/21 13:31:27 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	wich_wall(t_data *cube, double tmpx, double tmpy, double posx, double posy)
{
	if (cube->map[(int)tmpy][(int)posx])
	{
		if (tmpy > posy)
			cube->ray = 'W';
		else
			cube->ray = 'E'
	}
	if (cube->map[(int)posy][(int)tmpx])
	{
		if (tmpx > posx)
			cube->ray = 'S';
		else
			cube->ray = 'N';
	}
}

void	draw_textures(t_data *cube, int index, int jdex)
{
	mlx_xpm_file_to_image
	if (cube->ray == 'S')
	if (cube->ray == 'N')
	if (cube->ray == 'E')
	if (cube->ray == 'W')
}
