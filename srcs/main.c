/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:09:46 by cprojean          #+#    #+#             */
/*   Updated: 2023/11/13 15:55:24 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	main(int argc, char **argv)
{
	t_data	*cube;

	if (argc != 2)
	{
		ft_printf("🤷❓❓❓❓🤷❓❓❓❓❓ ARGS ❓❓❓❓❓🤷❓❓❓❓🤷\n");
		return (1);
	}
	cube = init_cube(argv[1]);
	if (!cube)
		return (1);
	if (do_cube(cube))
		return (1);
	return (0);
}
