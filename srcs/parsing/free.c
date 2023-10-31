/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagne <mgagne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 13:23:01 by mgagne            #+#    #+#             */
/*   Updated: 2023/10/31 16:07:06 by mgagne           ###   ########.fr       */
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

void	free_parse(t_parse *p, int complete[6])
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
	return ;
}
