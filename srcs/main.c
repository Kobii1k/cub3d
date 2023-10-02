/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:09:46 by cprojean          #+#    #+#             */
/*   Updated: 2023/10/01 21:25:41 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

t_data	parse_map(char *str);
int	verif_map_name(char *str);

int main(int argc, char **argv)
{
	t_data	*cube;

	if (argc != 2)
	{
		ft_printf("Your args sucks so much I can't even believe this\n");
		exit(1);
	}
	parse_map(argv[1]);
	do_cube();
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
	return (cube);
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

void	do_cube(void)
{
	t_data	cube;

	// init_cube(cube);
	cube.mlx_ptr = mlx_init();
	cube.mlx_win = mlx_new_window(cube.mlx_ptr, WINWIDTH, WINHEIGTH, "cub3d");
	cube.img_ptr = mlx_new_image(cube.mlx_ptr, WINWIDTH, WINHEIGTH);
	cube.img_addr = mlx_get_data_addr(cube.img_ptr, &cube.bits_per_pixel, \
	&cube.line_length, &cube.endian);
	mlx_loop();
	mlx_destroy_image(cube.mlx_ptr, cube.img_ptr);
	mlx_destroy_window(cube.mlx_ptr, cube.mlx_win);
	free(cube.mlx_ptr);
}
