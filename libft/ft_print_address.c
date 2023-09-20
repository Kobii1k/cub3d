/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_address.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:58:21 by cprojean          #+#    #+#             */
/*   Updated: 2023/02/10 15:29:22 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_address(size_t number, int *count)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	if (number >= 16)
	{
		ft_print_address(number / 16, count);
		ft_putchar(hexa[number % 16], count);
	}
	else
		ft_putchar(hexa[number % 16], count);
}
