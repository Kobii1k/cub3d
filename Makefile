# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cprojean <cprojean@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 11:36:52 by cprojean          #+#    #+#              #
#    Updated: 2023/10/02 16:12:09 by cprojean         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(shell uname -s), Linux)
	MLXDIR		=	minilibx/
	MLXFLAGS	=	-lmlx_Linux -L/usr/lib -Iminilibx -lXext -lX11 -lz
	MLXINC		=	-I/usr/include -Iminilibx 
	MLXLIB		=	minilibx/libmlx.a
endif
ifeq ($(shell uname -s), Darwin)
	MLXDIR	=	./mlx/
	MLXFLAGS =	-lmlx -framework OpenGL -framework AppKit
	MLXINC		=	-Imlx
	MLXLIB		=	mlx/libmlx.a
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

SRCS =	$(DIR_SRCS)main.c		\
		$(DIR_SRCS)display.c	\
		$(DIR_SRCS)hooks.c		\
		
OBJS =	$(patsubst %.c, $(DIR_OBJ)%.o, $(SRCS))
 
all	:		makelib $(NAME)

$(DIR_OBJ)%.o: %.c $(HEADERS)
				@mkdir -p $(shell dirname $@)
				$(CC) $(CFLAGS) -c $< -o $@ -I $(HEADERS) -Iminilibx -Ilibft

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

.SILENT :	$(OBJS) $(MLXc) $(NAME) libft