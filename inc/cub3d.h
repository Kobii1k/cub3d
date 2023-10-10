/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:11:03 by cprojean          #+#    #+#             */
/*   Updated: 2023/10/10 10:52:46 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

# ifdef __APPLE__
#  include "../mlx/mlx.h"
#  define W 13
#  define Q 12
#  define A 0
#  define S 1
#  define D 2
#  define RIGHT_ARR 124
#  define LEFT_ARR 123
#  define ESC 53
# elif __linux__
#  include "../minilibx/mlx.h"
#  define W 119
#  define A 97
#  define S 115
#  define D 100
#  define RIGHT_ARR 65363
#  define LEFT_ARR 65361
#  define ESC 65307
# endif
# define WINWIDTH 1000
# define WINHEIGHT 1000

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

// enum {
// 	W = 13,
// 	A = 12,
// 	S = 1,
// 	D = 2,
// 	RIGHT_ARR = 124,
// 	LEFT_ARR = 123,
// 	ESC = 53
// };

typedef struct s_player
{
	int		posx;
	int		posy;
	double	player_angle;
	double	cam_dx;
	double	cam_dy;
}				t_player;

typedef struct s_data
{
	char		**map;
	int			*keys;
	int			count;
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
	t_player	j1;
}			t_data;

void		do_cube(t_data cube);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			moove_keys(int key, t_data *cube);
void		draw_player(t_data *cube);
void		draw_map2D(t_data *cube);
int			close_window(t_data *cube);
void		draw_player(t_data *cube);
void		draw_map2D(t_data *cube);
void		draw_square(t_data *cube, int color, int index, int jdex);
char		**create_map(int fd, t_data *cube);
t_player	init_player(int index, int jdex, char c);
void		draw_lines(t_data *cube);
int			is_wall(t_data *cube, int mode, int value);
int			display_game(t_data *cube);

#endif
