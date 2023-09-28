# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cprojean <cprojean@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 11:36:52 by cprojean          #+#    #+#              #
#    Updated: 2023/09/28 14:39:41 by cprojean         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(shell uname -s), Linux)
	MLXDIR	=	./minilibx/
	MLXFLAGS	=	-Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
endif
ifeq ($(shell uname -s), Darwin)
	MLXDIR	=	./mlx/
	MLXFLAGS =	-lmlx -framework OpenGL -framework AppKit
endif

NAME = cub3d

CC = cc

CFLAGS = -Wall -Wextra -Werror -g -Ofast

libftFLAGS = -L./libft -lft

LIB = libft/libft.a

MKDIR = mkdir -p

RM = rm -rf

DIR_OBJ = ./.obj/

DIR_SRCS = srcs/

DIR_INCLUDES = ./inc/

HEADERS = $(DIR_INCLUDES)cub3d.h

SRCS =	$(DIR_SRCS)main.c	\

OBJS =	$(patsubst %.c, $(DIR_OBJ)%.o, $(SRCS))
 
all	:		makelib $(NAME)

$(DIR_OBJ)%.o: %.c $(LIB) $(HEADERS)
				@mkdir -p $(shell dirname $@)
				$(CC) -I/usr/include -Imlx_linux $(CFLAGS) -c $< -o $@

$(NAME): $(LIB) $(OBJS) $(MLX) Makefile
	$(CC) $(OBJS) -L$(MLXDIR) $(MLXFLAGS) $(libftFLAGS) -o $(NAME)

makelib:
			$(MAKE) -C libft
			$(MAKE) all -C $(MLXDIR)

clean :
			$(MAKE) clean -C libft
			$(MAKE) clean -C $(MLXDIR)
			$(RM) $(OBJS)

fclean :	clean
			$(MAKE) fclean -C libft
			@$(RM) $(DIR_OBJ)
			$(RM) $(NAME)

re :		fclean all

.PHONY : libft all clean re fclean

# .SILENT :	$(OBJS) $(MLXc) $(NAME) libft