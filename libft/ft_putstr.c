/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:47:59 by cprojean          #+#    #+#             */
/*   Updated: 2023/02/10 15:28:40 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char *str, int *count)
{
	int		index;
	char	*null;

	null = "(null)";
	index = 0;
	if (!str)
	{
		str = null;
	}
	while (str[index])
	{
		ft_putchar(str[index], count);
		index++;
	}
}
