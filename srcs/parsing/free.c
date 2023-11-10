/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagne <mgagne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 13:23:01 by mgagne            #+#    #+#             */
/*   Updated: 2023/11/10 12:51:09 by mgagne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
	return ;
}

void	free_map(char **map, int index)
{
	int	i;

	i = 0;
	while (i < index && map[i])
		free(map[i++]);
	free(map);
	return ;
}

void	free_parse(t_parse *p, int complete[6], int i)
{
	if (i)
	{
		if (p)
		{
			return (free(p->north), free(p->south),
				free(p->east), free(p->west), free(p));
		}
	}
	else
	{
		if (p)
		{
			if (complete[0])
				free(p->north);
			if (complete[1])
				free(p->south);
			if (complete[2])
				free(p->east);
			if (complete[3])
				free(p->west);
			free(p);
		}
	}
}

void	free_textures(t_data *cube, int situation)
{
	if (situation == 2)
		(void) situation;
	else if (situation == 3)
		mlx_destroy_image(cube->window.mlx_ptr, cube->ntexture.img_ptr);
	else if (situation == 4)
	{
		mlx_destroy_image(cube->window.mlx_ptr, cube->ntexture.img_ptr);
		mlx_destroy_image(cube->window.mlx_ptr, cube->stexture.img_ptr);
	}
	else if (situation == 5)
	{
		mlx_destroy_image(cube->window.mlx_ptr, cube->ntexture.img_ptr);
		mlx_destroy_image(cube->window.mlx_ptr, cube->stexture.img_ptr);
		mlx_destroy_image(cube->window.mlx_ptr, cube->etexture.img_ptr);
	}
	else
	{
		mlx_destroy_image(cube->window.mlx_ptr, cube->ntexture.img_ptr);
		mlx_destroy_image(cube->window.mlx_ptr, cube->stexture.img_ptr);
		mlx_destroy_image(cube->window.mlx_ptr, cube->etexture.img_ptr);
		mlx_destroy_image(cube->window.mlx_ptr, cube->wtexture.img_ptr);
	}
	free_on_error(cube);
}

void	free_on_error(t_data *cube)
{
	int	index;

	index = 0;
	mlx_destroy_window(cube->window.mlx_ptr, cube->window.mlx_win);
	mlx_destroy_image(cube->window.mlx_ptr, cube->window.img_ptr);
	mlx_destroy_display(cube->window.mlx_ptr);
	while (index < cube->height && cube->map[index])
		free(cube->map[index++]);
	free(cube->map);
	free_parse(cube->p, NULL, 1);
	free(cube->p);
	free(cube->keys);
	free(cube->window.mlx_ptr);
	free(cube);
}
