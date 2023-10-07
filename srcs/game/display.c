/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 20:58:44 by cprojean          #+#    #+#             */
/*   Updated: 2023/10/07 16:52:29 by cprojean         ###   ########.fr       */
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
