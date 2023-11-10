/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagne <mgagne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:11:03 by cprojean          #+#    #+#             */
/*   Updated: 2023/11/10 13:07:01 by mgagne           ###   ########.fr       */
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
# define WINWIDTH 1920
# define WINHEIGHT 1080

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

enum {
	Wk = 1,
	Ak = 2,
	Sk = 3,
	Dk = 4,
	RIGHT_ARRk = 5,
	LEFT_ARRk = 6,
	ESCk = 7
};

// typedef struct s_lst
// {
// 	char	*str;
// 	t_lst	*next;
// }			t_lst;

typedef struct s_parse
{
	char	*north;
	char	*south;
	char	*east;
	char	*west;
	long	ceiling;
	long	floor;
}			t_parse;

typedef struct s_player
{
	float	vect[2];
	int		next_pos[2];
	double	posx;
	double	posy;
	double	player_angle;
	double	cam_dx;
	double	cam_dy;
	int		fov;
}				t_player;

typedef struct s_frame
{
	void		*mlx_ptr;
	void		*mlx_win;
	void		*img_ptr;
	char		*img_addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			sizex;
	int			sizey;
}				t_frame;

typedef struct s_data
{
	char		**map;
	int			*keys;
	int			count;
	int			height;
	int			width;
	int			x1;
	int			y1;
	char		ray;
	double		opposite;
	double		adj;
	double		raypos[2];
	double		limit;
	t_frame		window;
	t_frame		ntexture;
	t_frame		stexture;
	t_frame		etexture;
	t_frame		wtexture;
	t_player	j1;
	t_parse		*p;
}				t_data;

//display.c
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			my_mlx_pixel_get(t_frame *image, int x, int y);
int			display_game(t_data *cube);
int			is_wall(t_data *cube, double posx, double posy);

//game.c
int			do_cube(t_data *cube);
t_player	init_player(int index, int jdex, char c);

//hooks.c
int			press_keys(int key, t_data *cube);
int			release_keys(int key, t_data *cube);
int			close_window(t_data *cube);
int			loop(t_data *cube);

//collision
void		move_up(t_data *cube);
void		move_down(t_data *cube);
void		move_left(t_data *cube);
void		move_right(t_data *cube);
void		wich_wall(t_data *cube, double tmp[2], double posx, double posy);

//drawing.c
void		draw_player(t_data *cube);
void		draw_minimap(t_data *cube);
void		draw_square(t_data *cube, int color, int index, int jdex);
void		draw_lines(t_data *cube);
void		draw_vision(t_data *cube);
void		draw_raycast(t_data *cube);
void		add_vect(t_data *cube);
void		draw_textures(t_data *cube, double index, double jdex);

//parsing
t_parse		*parse_map(t_data *cube, int fd);
int			check_player(char c, int *player);
int			which_param(char *str, int index);
long		create_rgb(int r, int g, int b);
long		translate_rgb(char *str);
int			rgb_to_hex(t_parse *p, char *str, int i, int n);
int			path_values(t_parse *p, char *str, int i, int n);
int			create_map(int fd, t_data *cube);
t_data		*init_cube(char *str);
int			map_verif(char *str);
void		print_map(t_data *cube);
int			verif_map_name(char *str);
int			verified_value(char c);
int			check_void(int i, int j, int size, char **map);
int			open_textures(t_data *cube);
int			translate_value(int count[2], t_parse *p, char *str, int complete[6]);
void		free_lst(t_list **l);
t_list		*ft_lstnew_dup(char *content);
int			fill_map(t_data *cube, t_list *l);
int			get_map(t_data *cube, char *str, int fd);


void		ft_memset_int(int *tab, int c, int len);
char		*ft_strdup_nospace(const char *s1);
int			ft_isspace(char c);


//free
void		free_map(char **map, int index);
void		free_split(char **split);
void		free_parse(t_parse *p, int complete[6], int i);
void		free_on_error(t_data *cube);
void		free_textures(t_data *cube, int situation);

#endif
