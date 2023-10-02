/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:09:46 by cprojean          #+#    #+#             */
/*   Updated: 2023/10/02 20:58:18 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

t_data		parse_map(char *str);
int			verif_map_name(char *str);
void		draw_player(t_data *cube);
t_player	init_player(t_player *j1);
char		**create_map(int fd);
void	print_map(char **str);
void	draw_square(t_data *cube, int color, int index, int jdex);

int main(int argc, char **argv)
{
	t_data	cube;
	if (argc != 2)
	{
		ft_printf("Your args sucks so much I can't even believe this\n");
		exit(1);
	}
	cube = parse_map(argv[1]);
	do_cube(cube);
}

t_data	parse_map(char *str)
{
	t_data	cube;
	int		fd;

	if (verif_map_name(str) == -1)
	{	
		ft_printf("Error map extension\n");
		exit(1);
	}
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error on acces to file\n");
		exit(1);
	}
	ft_bzero(&cube, sizeof(t_data));
	cube.map = create_map(fd);
	print_map(cube.map);
	return (cube);
}

void	print_map(char **str)
{
	int	index;

	if (!str)
		ft_printf("Error with the map");
	index = 0;
	while (index < 10)
	{
		ft_printf("%s\n", str[index]);
		index++;
	}
}

char	**create_map(int fd)
{
	char	**map;
	int		index;
	int		jdex;

	(void) fd;
	index = 0;
	jdex = 0;
	map = malloc(sizeof(char *) * 10);
	while (index < 10)
	{
		map[index] = malloc(sizeof(char) * 10);
		index++;
	}
	index = 0;
	while (index < 10)
	{
		jdex = 0;
		while (jdex < 10)
		{
			if ((jdex == 0 || index == 0) || ((jdex == 9 || index == 9)))
				map[index][jdex] = '1';
			else if ((jdex * 3) % 5 == 0)
				map[index][jdex] = '1';
			else
				map[index][jdex] = '0';
			jdex++;
		}
		index++;
	}
	return (map);
}

int	verif_map_name(char *str)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '.')
			tmp = i;
		i++;
	}
	if (!str[tmp + 1] || str[tmp + 1] != 'c')
		return (-1);
	if (!str[tmp + 2] || str[tmp + 2] != 'u')
		return (-1);
	if (!str[tmp + 3] || str[tmp + 3] != 'b')
		return (-1);
	if (str[tmp + 4])
		return (-1);
	return (0);
}

void	do_cube(t_data cube)
{
	t_player	j1;

	// init_cube(cube);
	ft_bzero(&j1, sizeof(t_player));
	j1 = init_player(&j1);
	cube.j1 = &j1;
	cube.mlx_ptr = mlx_init();
	if (cube.mlx_ptr == 0x0)
		exit(1);
	cube.mlx_win = mlx_new_window(cube.mlx_ptr, WINWIDTH, WINHEIGTH, "cub3d");
	cube.img_ptr = mlx_new_image(cube.mlx_ptr, WINWIDTH, WINHEIGTH);
	cube.img_addr = mlx_get_data_addr(cube.img_ptr, &cube.bits_per_pixel, \
	&cube.line_length, &cube.endian);
	draw_map2D(&cube);
	draw_player(&cube);
	mlx_hook(cube.mlx_win, 2, (1L << 0), moove_keys, &cube);
	mlx_loop(cube.mlx_ptr);
	mlx_destroy_image(cube.mlx_ptr, cube.img_ptr);
	mlx_destroy_window(cube.mlx_ptr, cube.mlx_win);
	free(cube.mlx_ptr);
}

t_player	init_player(t_player *j1)
{
	j1->posx = 150;
	j1->posy = 150;
	return (*j1);
}

void	draw_player(t_data *cube)
{
	int	index_max;
	int	jndex_max;
	int	tmpx;
	int	tmpy;

	ft_printf("%d %d\n", cube->j1->posx, cube->j1->posy);
	index_max = cube->j1->posx + 30;
	tmpy = cube->j1->posy;
	tmpx = cube->j1->posx;
	jndex_max = cube->j1->posy + 30;
	while (cube->j1->posx < index_max)
	{
		cube->j1->posy = tmpy;
		while (cube->j1->posy < jndex_max)
		{
			my_mlx_pixel_put(cube, cube->j1->posx, cube->j1->posy, 0xFFFFFF);
			cube->j1->posy += 1;
		}
		cube->j1->posx += 1;
	}
	cube->j1->posx = tmpx;
	cube->j1->posy = tmpy;
	mlx_put_image_to_window(cube->mlx_ptr, cube->mlx_win, cube->img_ptr, 0, 0);
}

void	draw_map2D(t_data *cube)
{
	int	index;
	int	jdex;
	int	color;

	index = 0;
	jdex = 0;
	while (index < 10)
	{
		jdex = 0;
		while (jdex < 10)
		{
			if (cube->map[index][jdex] == '1')
				color = 0xFFFFFF;
			else
				color = 0x000000;
			draw_square(cube, color, index, jdex);
			jdex++;
		}
		index++;
	}
}

void	draw_square(t_data *cube, int color, int index, int jdex)
{
	int	tmpind;
	int	tmpjdex;

	index = index * 100;
	jdex = jdex * 100;
	tmpind = index;
	tmpjdex = jdex;
	while (index < tmpind + 100)
	{
		jdex = tmpjdex;
		while (jdex < tmpjdex + 100)
		{
			my_mlx_pixel_put(cube, index, jdex, color);
			jdex++;
		}
		index++;
	}
}
