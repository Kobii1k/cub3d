/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgagne <mgagne@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:29:44 by mgagne            #+#    #+#             */
/*   Updated: 2023/11/14 14:43:04 by mgagne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

t_data	*init_cube(char *str)
{
	t_data	*cube;
	int		fd;
	int		index;

	fd = map_verif(str);
	if (fd == -1)
		return (NULL);
	cube = malloc(sizeof(t_data));
	if (!cube)
		return (printf("malloc error\n"), close(fd), NULL);
	cube->p = parse_map(cube, fd);
	if (!cube->p)
		return (printf("malloc error\n"), close(fd), free(cube), NULL);
	cube->keys = malloc(sizeof(int) * 7);
	if (!cube->keys)
		return (printf("malloc error\n"), free_parse(cube->p, NULL, 1),
			close(fd), free_map(cube), free(cube), NULL);
	index = 0;
	while ((index + 1) <= ESCk)
	{
		cube->keys[index] = 0;
		index++;
	}
	return (close(fd), cube->count = 0, cube);
}

void	free_lst(t_list **l)
{
	t_list	*tmp;

	if (l)
	{
		while (*l)
		{
			tmp = (*l)->next;
			free((*l)->content);
			free((*l));
			*l = tmp;
		}
	}
	return ;
}

t_list	*ft_lstnew_dup(char *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (printf("malloc error\n"), NULL);
	new->content = ft_strdup(content);
	if (!new->content)
		return (printf("malloc error\n"), NULL);
	new->next = NULL;
	return (new);
}

int	fill_map(t_data *cube, t_list *l)
{
	int		index;
	t_list	*tmp;

	cube->map = malloc(sizeof(char *) * cube->height);
	if (!cube->map)
		return (free_lst(&l), printf("malloc error\n"), 1);
	index = 0;
	tmp = l;
	while (index < cube->height)
	{
		cube->map[index] = ft_strdup(l->content);
		l = l->next;
		index++;
	}
	return (free_lst(&tmp), 0);
}

int	get_map(t_data *cube, char *str, int fd)
{
	int		index;
	t_list	*l;
	t_list	*tmp;

	index = 0;
	l = NULL;
	while (str && str[0])
	{
		if (str[0])
		{
			tmp = ft_lstnew_dup(str);
			if (!tmp)
				return (free_lst(&l), free(str), printf("malloc error\n"), 1);
			ft_lstadd_back(&l, tmp);
			index++;
		}
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	str = get_next_line(fd);
	if (str && str[0])
		return (free_lst(&l), free(str), printf("map error: empty line\n"), 1);
	cube->height = index;
	return (free(str), fill_map(cube, l));
}
