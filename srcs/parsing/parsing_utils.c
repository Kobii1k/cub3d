/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagne <mgagne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:07:54 by mgagne            #+#    #+#             */
/*   Updated: 2023/10/31 18:29:05 by mgagne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	verified_value(char c, int *player)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		if (*player == 0)
		{
			*player = 1;
			return (1);
		}
		else
			return (ft_printf("map error : multiple player value\n"), 0);
	}
	return (1);

}

int	which_param(char *str, int index)
{
	int	nb;

	nb = -1;
	if (ft_strncmp(&str[index], "NO", 2) == 0)
		nb = 0;
	if (ft_strncmp(&str[index], "SO", 2) == 0)
		nb = 1;
	if (ft_strncmp(&str[index], "EA", 2) == 0)
		nb = 2;
	if (ft_strncmp(&str[index], "WE", 2) == 0)
		nb = 3;
	if (ft_strncmp(&str[index], "C", 1) == 0)
		nb = 4;
	if (ft_strncmp(&str[index], "F", 1) == 0)
		nb = 5;
	return (nb);
}

char	*ft_strdup_nospace(const char *s1)
{
	int		size;
	int		runner;
	char	*dup;

	runner = 0;
	size = 0;
	while (s1[size] != '\0' && !ft_isspace(s1[size]))
		size++;
	dup = malloc(sizeof(char) * size + 1);
	if (dup == 0)
		return (0);
	while (runner < size)
	{
		dup[runner] = s1[runner];
		runner++;
	}
	dup[runner] = '\0';
	return (dup);
}

void	ft_memset_int(int *tab, int c, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		tab[i] = c;
		i++;
	}
	return ;
}

int	ft_isspace(char c)
{
	return (c == ' ' || c == '	');
}