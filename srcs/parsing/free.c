/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 13:23:01 by mgagne            #+#    #+#             */
/*   Updated: 2023/11/02 16:01:56 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return ;
}

void	free_parse(t_parse *p, int complete[6], int i)
{
	if (i)
	{
		if (p)
		{
			free(p->north);
			free(p->south);
			free(p->east);
			free(p->west);
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
		}
	}
}

void	free_on_error(t_data *cube)
{
	int	index;

	index = 0;
	if (cube->ntexture.img_ptr != 0x0)
		mlx_destroy_image(cube->window.mlx_ptr, cube->ntexture.img_ptr);
	if (cube->stexture.img_ptr != 0x0)
		mlx_destroy_image(cube->window.mlx_ptr, cube->stexture.img_ptr);
	if (cube->etexture.img_ptr != 0x0)
		mlx_destroy_image(cube->window.mlx_ptr, cube->etexture.img_ptr);
	if (cube->wtexture.img_ptr != 0x0)
		mlx_destroy_image(cube->window.mlx_ptr, cube->wtexture.img_ptr);
	mlx_destroy_window(cube->window.mlx_ptr, cube->window.mlx_win);
	mlx_destroy_display(cube->window.mlx_ptr);
	free(cube->window.mlx_ptr);
	while (index < cube->height && cube->map[index])
	{
		free(cube->map[index]);
		index++;
	}
	printf("%d\n", index);
	free(cube->map);
	free_parse(cube->p, NULL, 1);
	free(cube->p);
	free(cube->keys);
	free(cube);
}
