# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cprojean <cprojean@42lyon.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 11:36:52 by cprojean          #+#    #+#              #
#    Updated: 2023/09/20 13:22:56 by cprojean         ###   ########.fr        #
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

MKDIR = mkdir -p

RM = rm -rf

DIR_OBJ = ./.obj/

DIR_SRCS = srcs/

DIR_INCLUDES = ./inc/

HEADERS = cub3d.h

SRCS =	

OBJS =			$(patsubst %.c, $(DIR_OBJ)%.o, $(SRCS))

$(DIR_OBJ)%.o: %.c $(HEADERS)
				@mkdir -p $(shell dirname $@)
				$(CC) $(CFLAGS) -I inc -c $< -o $@

%.o: %.c

	$(CC) $(libftFLAGS) -I/usr/include -Imlx_linux -O3 $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) $(libft) Makefile $(MLX) Makefile
	$(MAKE) bonus -C libft
	$(MAKE) all -C $(MLXDIR)
	$(CC) $(OBJS) -L$(MLXDIR) $(MLXFLAGS) $(libftFLAGS) -o $(NAME)


all	:		$(NAME)

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