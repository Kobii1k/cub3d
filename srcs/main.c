/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagne <mgagne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 12:09:46 by cprojean          #+#    #+#             */
/*   Updated: 2023/10/10 15:06:31 by mgagne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	main(int argc, char **argv)
{
	t_data	*cube;

	if (argc != 2)
	{
		ft_printf("Your args sucks so much I can't even believe this\n");
		return (1);
	}
	cube = parse_map(argv[1]);
	if (!cube)
		return (1);
	if (do_cube(cube))
		return (1);
	return (0);
}
