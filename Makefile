# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cprojean <cprojean@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 11:36:52 by cprojean          #+#    #+#              #
#    Updated: 2023/11/14 13:20:14 by cprojean         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(shell uname -s), Linux)
	MLXLIB		=	minilibx/libmlx.a
	MLXFLAGS	=	-lmlx_Linux -L/usr/lib -Iminilibx -lXext -lX11 -lz
	MLXINC		=	-I/usr/include -Iminilibx
	MLXDIR		=	minilibx/
endif
ifeq ($(shell uname -s), Darwin)
	MLXDIR	=	./mlx/
	MLXFLAGS =	-lmlx -framework OpenGL -framework AppKit
	MLXINC		=	-Imlx
	# MLXFLAGS	=	-lmlx -L/usr/lib -Iminilibx -lXext -lX11 -lz
	MLXLIB		=	minilibx/libmlx_Darwin.a
endif

NAME = cub3D

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3 -Ofast

libftFLAGS = -L./libft -lft

LIB = libft/libft.a

MKDIR = mkdir -p

RM = rm -rf

DIR_OBJ = .obj/

DIR_SRCS = srcs/

DIR_GAME = $(DIR_SRCS)game/

DIR_PARS = $(DIR_SRCS)parsing/

DIR_INCLUDES = inc/

HEADERS = $(DIR_INCLUDES)cub3d.h

SRCS =	$(DIR_SRCS)main.c			\
		$(DIR_GAME)display.c		\
		$(DIR_GAME)hooks.c			\
		$(DIR_GAME)game.c			\
		$(DIR_GAME)minimap.c		\
		$(DIR_GAME)loop.c			\
		$(DIR_PARS)map.c			\
		$(DIR_PARS)parsing.c		\
		$(DIR_PARS)parsing_utils.c	\
		$(DIR_PARS)free.c			\
		$(DIR_PARS)rgb_path.c		\
		$(DIR_PARS)init.c			\
		$(DIR_GAME)lines.c			\
		$(DIR_GAME)raycast.c		\
		$(DIR_GAME)move.c			\
		$(DIR_GAME)texture.c		\

OBJS =	$(patsubst %.c, $(DIR_OBJ)%.o, $(SRCS))

all	:		makelib $(NAME)

$(DIR_OBJ)%.o: %.c $(LIB) $(HEADERS)
				@mkdir -p $(shell dirname $@)
				$(CC) $(CFLAGS) -c $< -o $@ -I $(DIR_INCLUDES) -Iminilibx -Ilibft

$(NAME): $(LIB) $(MLXLIB) $(OBJS)
	make -C $(MLXDIR)
	$(CC) $(OBJS) -L$(MLXDIR) -lm $(MLXFLAGS) $(libftFLAGS) -o $(NAME)

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
