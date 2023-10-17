/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagne <mgagne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:36:14 by mgagne            #+#    #+#             */
/*   Updated: 2023/10/17 18:48:58 by mgagne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

int	which_param(char *str);
int	path_values(t_parse *p, char *str, int i, int n);
int	rgb_to_hex(t_parse *p, char *str, int i, int n);

int	get_params(char *str, t_parse *p, int complete[6])
{
	int	n;
	int	i;

	n = which_param(str);
	if (n == -1)
		return (ft_printf("map error : values not found\n"), 1);
	else
	{
		if (complete[n] == 1)
			return (ft_printf("map error : duplicate value\n"), 1);
		complete[n] = 1;
		i = 2;
		if (n == 4 || n == 5)
			i = 1;
		while (str[i] == ' ')
			i++;
		if (n != 4 && n != 5)
			path_values(p, str, i, n);
		else
			rgb_to_hex(p, str, i, n);
	}
	return (0);
}

t_parse	*parse_map(int fd)
{
	t_parse	*p;
	char	*str;
	int		complete[6];

	p = malloc(sizeof(t_parse));
	if (!p)
		return (NULL);
	ft_memset(complete, 0, 6);
	str = get_next_line(fd);
	while (str)
	{
		if (get_params(str, p, complete))
			return (NULL);
		str = get_next_line(fd);
		if (complete[0])
			printf("BONJOUR\n");
	}
	return (p);
}

int	which_param(char *str)
{
	int	nb;

	nb = -1;
	if (ft_strncmp(str, "NO", 2) == 0)
		nb = 0;
	if (ft_strncmp(str, "SO", 2) == 0)
		nb = 1;
	if (ft_strncmp(str, "EA", 2) == 0)
		nb = 2;
	if (ft_strncmp(str, "WE", 2) == 0)
		nb = 3;
	if (ft_strncmp(str, "C", 1) == 0)
		nb = 4;
	if (ft_strncmp(str, "F", 1) == 0)
		nb = 5;
	return (nb);
}

int	rgb_to_hex(t_parse *p, char *str, int i, int n)
{
	char	*hex;

	hex = malloc(9 * sizeof(char));
	if (!hex)
		return (1);
	if (n == 4)
	{
		printf("%s\n\n\n", p->ceiling);
		//translate
	}
	else
	{
		printf("%s%d\n\n\n", str, i);
		//translate
	}
	return (0);
}

int	path_values(t_parse *p, char *str, int i, int n)
{
	if (n == 0)
	{
		p->north = ft_strdup(&(str[i]));
		if (!p->north)
			return (1);
	}
	if (n == 1)
	{
		p->south = ft_strdup(&(str[i]));
		if (!p->south)
			return (1);
	}
	if (n == 2)
	{
		p->east = ft_strdup(&(str[i]));
		if (!p->east)
			return (1);
	}
	if (n == 3)
	{
		p->west = ft_strdup(&(str[i]));
		if (!p->west)
			return (1);
	}
	return (0);
}
