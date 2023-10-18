/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:24:58 by cprojean          #+#    #+#             */
/*   Updated: 2023/10/17 19:08:28 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void do_line(t_data *cube, double tmp_angle, int r);

void	draw_vision(t_data *cube)
{
	int		r;
	double	tmp_angle;

	r = 0;
	cube->j1.posx += 5;
	cube->j1.posy += 5;
	tmp_angle = cube->j1.player_angle;
	tmp_angle = tmp_angle - 60;
	while (tmp_angle < cube->j1.player_angle + 60)
	{
        do_line(cube, tmp_angle, r);
		tmp_angle += 0.0625;
	}
	cube->j1.posx -= 5;
	cube->j1.posy -= 5;
}

void do_line(t_data *cube, double tmp_angle, int r)
{
    int x1;
    int y1;
    int posx;
    int posy;
    
    r = 0;
    while (r < 300)
    {
        x1 = r * cos(tmp_angle * M_PI / 180);
        y1 = r * sin(tmp_angle * M_PI / 180);
        posx = floor((cube->j1.posx + x1) / 10);
        posy = floor((cube->j1.posy + y1) / 10);
        if (((posx >= 0) && (posy >= 0)) && cube->map[posy][posx] == '1')
        {
            my_mlx_pixel_put(cube, cube->j1.posx + x1, cube->j1.posy + y1, 0xFE0000);
            // raycast(data, r);
            break ;
        }
        r++;
    }
}
