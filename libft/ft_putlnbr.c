/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 23:16:37 by cprojean          #+#    #+#             */
/*   Updated: 2023/02/10 15:28:55 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putlnbr(unsigned int x, int *count)
{
	char	mod;

	if (x > 9)
	{
		mod = x % 10 + 48;
		x = x / 10;
		ft_putlnbr(x, count);
		ft_putchar(mod, count);
	}
	else if (x < 10)
	{
		mod = (x % 10) + 48;
		ft_putchar(mod, count);
	}
}
