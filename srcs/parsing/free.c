/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagne <mgagne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 13:23:01 by mgagne            #+#    #+#             */
/*   Updated: 2023/10/29 13:32:24 by mgagne           ###   ########.fr       */
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

void	free_parse(t_parse *p)
{
	if (p->north)
		free(p->north);
	if (p->south)
		free(p->south);
	if (p->east)
		free(p->east);
	if (p->west)
		free(p->west);
	free(p);
	return ;
}
