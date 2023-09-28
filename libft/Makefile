# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cprojean <cprojean@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/10 14:30:05 by cprojean          #+#    #+#              #
#    Updated: 2023/09/28 12:28:44 by cprojean         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =				libft.a

NAME_bonus =		libftbonus.a

CC =				cc

CFLAGS =			-Wall -Werror -Wextra

HEADERS =			libft.h

ARFLAGS =			rcs

rm =				rm -rf

SRCS =				ft_atoi.c               \
					ft_itoa.c               \
					ft_bzero.c              \
					ft_calloc.c             \
					ft_isalnum.c            \
					ft_isalpha.c            \
					ft_isascii.c            \
					ft_isdigit.c            \
					ft_isprint.c            \
					ft_memcpy.c             \
					ft_memmove.c            \
					ft_memset.c             \
					ft_strchr.c             \
					ft_strlcat.c            \
					ft_strlcpy.c            \
					ft_strlen.c             \
					ft_strncmp.c            \
					ft_strnstr.c            \
					ft_strrchr.c            \
					ft_tolower.c            \
					ft_toupper.c            \
					ft_memcmp.c             \
					ft_memchr.c             \
					ft_strdup.c             \
					ft_substr.c             \
					ft_strjoin.c            \
					ft_split.c              \
					ft_strtrim.c            \
					ft_strmapi.c            \
					ft_striteri.c           \
					ft_putchar_fd.c         \
					ft_putstr_fd.c          \
					ft_putendl_fd.c         \
					ft_putnbr_fd.c          \
					get_next_line.c         \
					get_next_line_utils.c   \
					which_varia.c           \
					ft_printf.c             \
					ft_print_address.c      \
					ft_convert_hexa_maj.c   \
					ft_convert_hexa_min.c   \
					ft_putchar.c            \
					ft_putlnbr.c            \
					ft_putnbr.c             \
					ft_putstr.c             \




SRCS_bonus =		ft_lstnew.c             \
					ft_lstadd_front.c       \
					ft_lstlast.c            \
					ft_lstsize.c            \
					ft_lstadd_back.c        \
					ft_lstdelone.c          \
					ft_lstclear.c           \
					ft_lstiter.c            \
					ft_lstmap.c             \

PRINTF		=		ft_print_address.c		\
					ft_printf.c				\
					ft_convert_hexa_maj.c	\
					ft_convert_hexa_min.c	\
					ft_putchar.c			\
					ft_putstr.c				\
					ft_putnbr.c				\
					ft_putlnbr.c			\
					which_varia.c			\

OBJS =				${SRCS:.c=.o}

${NAME} :			${OBJS}
					ar ${ARFLAGS} ${NAME} ${OBJS}

OBJS_bonus =		${SRCS_bonus:.c=.o}

${NAME_bonus} :		${OBJS} ${OBJS_bonus}
					ar ${ARFLAGS} ${NAME} ${OBJS} ${OBJS_bonus}

all:				${NAME}

bonus :				${OBJS} ${OBJS_bonus}
					ar ${ARFLAGS} ${NAME} ${OBJS} ${OBJS_bonus}

%.o : %.c			
					$(CC) -c $(CFLAGS) $< -o $@

clean:
					${RM} ${OBJS} ${OBJS_bonus}

fclean:				clean
					${RM} ${NAME}

re :				fclean all

.PHONY :			all make clean fclean re bonus

.SILENT : $(OBJS) $(OBJS_bonus) $(NAME) $(NAME_bonus)