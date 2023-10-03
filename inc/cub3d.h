/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:11:03 by cprojean          #+#    #+#             */
/*   Updated: 2023/10/04 00:17:17 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"

# ifdef __APPLE__
#  include "../mlx/mlx.h"
#  define W 13
#  define Q 12
#  define A 0
#  define S 1
#  define D 2
#  define ESC 53
# elif __linux__
#  include "../minilibx/mlx.h"
#  define W 119
#  define A 97
#  define S 115
#  define D 100
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

typedef struct s_player
{
	int	posx;
	int	posy;
}				t_player;

typedef struct s_data
{
	char		**map;
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

void	do_cube(t_data cube);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		moove_keys(int key, t_data *cube);
void	draw_player(t_data *cube);
void	draw_map2D(t_data *cube);
int		close_window(t_data *cube);
char	**create_map(int fd);
void	draw_player(t_data *cube);
void	draw_map2D(t_data *cube);
void	draw_square(t_data *cube, int color, int index, int jdex);
char		**create_map(int fd);
t_player	init_player(int index, int jdex);

#endif
