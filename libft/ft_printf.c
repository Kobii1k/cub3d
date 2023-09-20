/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:36:04 by cprojean          #+#    #+#             */
/*   Updated: 2023/02/10 15:29:12 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *array, ...)
{
	size_t	index;
	va_list	variadic;
	int		count;

	count = 0;
	index = 0;
	va_start(variadic, array);
	while (array[index])
	{
		if (array[index] != '%')
			ft_putchar(array[index], &count);
		if (array[index] == '%' && array[index + 1] != '\0')
		{
			which_varia(array, variadic, &index, &count);
			if (count == -1)
				return (-1);
			index++;
		}
		index++;
	}
	va_end(variadic);
	return (count);
}
