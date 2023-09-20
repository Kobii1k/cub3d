/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:58:14 by cprojean          #+#    #+#             */
/*   Updated: 2023/02/08 18:37:36 by cprojean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char	*get_next_line(int fd);

char	*next_get_next_line(char *buf, char *array, ssize_t reader, int fd);

char	*ft_strnjoin(char *s1, char *s2, size_t index);

//size_t	ft_strlen(char *str);

void	ft_buf_reset(char *buf, int index);

ssize_t	where_backslash(char *buf);

#endif
