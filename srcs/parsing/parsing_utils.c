/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagne <mgagne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:07:54 by mgagne            #+#    #+#             */
/*   Updated: 2023/10/18 13:50:25 by mgagne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	free_s(char **split)
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
