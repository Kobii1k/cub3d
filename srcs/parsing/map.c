/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 15:06:02 by mgagne            #+#    #+#             */
/*   Updated: 2023/10/28 12:36:08 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int		check_map(char *str);

int	create_map(int fd, t_data *cube)
{
	char	*str;
	int		index;

	index = 0;
	str = get_next_line(fd);
	if (!str)
		return (1);
	cube->map = malloc(sizeof(char *) * 60);
	while (str && str[0] != '1')
	{
		if (str[0] && str[0] != ' ' && str[0] != '1')
			return (ft_printf("map error : unexpected value\n"), 1);
		free(str);
		str = get_next_line(fd);
	}
	while (str)
	{
		cube->map[index] = ft_strdup(str);
		free(str);
		str = get_next_line(fd);
		index++;
	}
	ft_printf("%d\n\n", index);
	cube->height = index;
	return (0);
}

t_data	*init_cube(char *str)
{
	t_data	*cube;
	int		fd;
	int		index;

	fd = check_map(str);
	if (fd == -1)
		return (NULL);
	cube = malloc(sizeof(t_data));
	if (!cube)
		return (close(fd), NULL);
	cube->p = parse_map(cube, fd);
	if (!cube->p)
		return (NULL);
	cube->keys = malloc(sizeof(int) * 7);
	if (!cube->keys)
		return (close(fd), free(cube), NULL);
	index = 1;
	while (index <= ESCk)
	{
		cube->keys[index - 1] = 0;
		index++;
	}
	print_map(cube);
	close(fd);
	return (cube);
}

int		check_map(char *str)
{
	int		fd;

	if (verif_map_name(str) == -1)
	{
		ft_printf("map error : bad file extension\n");
		return (-1);
	}
	fd = open(str, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("map error : no access to file\n");
		return (-1);
	}
	return (fd);
}

void	print_map(t_data *cube)
{
	int	index;

	if (!cube->map)
		ft_printf("Error with the map\n");
	index = 0;
	while (index < cube->height)
	{
		ft_printf("%s\n", cube->map[index]);
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
