/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:09:46 by cprojean          #+#    #+#             */
/*   Updated: 2023/10/03 15:01:22 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

t_data		parse_map(char *str);
void		print_map(char **str);
int			verif_map_name(char *str);

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
