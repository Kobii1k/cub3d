/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:11:03 by cprojean          #+#    #+#             */
/*   Updated: 2023/10/02 17:07:49 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "mlx.h"
# define WINWIDTH 1000
# define WINHEIGTH 1000
# define W 119
# define A 97
# define S 115
# define D 100
# define ESC 65307

typedef struct s_player
{
	int	posx;
	int	posy;
}				t_player;

typedef struct s_data
{
	char		**map;
	int			height;
	int			width;
	int			fov;
	void		*mlx_ptr;
	void		*mlx_win;
	void		*img_ptr;
	char		*img_addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_player 	*j1;
}			t_data;

void	do_cube(void);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		moove_keys(int key, t_data *cube);
void	draw_player(t_data *cube);
int		close_window(t_data *cube);

#endif