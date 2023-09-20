/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which_varia.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:48:03 by cprojean          #+#    #+#             */
/*   Updated: 2023/02/10 15:28:15 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	which_varia(const char *array, va_list variadic, size_t *i, int *count)
{
	char	dash;

	dash = '%';
	if (array[*i + 1] == 'c')
		ft_putchar(va_arg(variadic, int), count);
	else if (array[*i + 1] == 's')
		ft_putstr(va_arg(variadic, char *), count);
	else if (array[*i + 1] == 'p')
	{
		ft_putstr("0x", count);
		ft_print_address(va_arg(variadic, size_t), count);
	}
	else if ((array[*i + 1] == 'd') || (array[*i + 1] == 'i'))
		ft_putnbr(va_arg(variadic, int), count);
	else if (array[*i + 1] == 'u')
		ft_putlnbr(va_arg(variadic, unsigned int), count);
	else if (array[*i + 1] == 'x')
		ft_convert_hexa_min(va_arg(variadic, unsigned int), count);
	else if (array[*i + 1] == 'X')
		ft_convert_hexa_maj(va_arg(variadic, unsigned int), count);
	else if (array[*i + 1] == '%')
	{
		ft_putchar(dash, count);
	}
}
