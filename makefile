# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thomas <thomas@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/04 15:35:18 by tcordonn          #+#    #+#              #
#    Updated: 2021/05/21 13:59:00 by thomas           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS := \
	srcs/init.c \
	srcs/init2.c \
	srcs/main.c \
	srcs/parser/check_map.c \
	srcs/parser/check_map2.c \
	srcs/parser/parse_scene.c \
	srcs/parser/parse_scene2.c \
	srcs/raycasting.c \
	srcs/get_next_line.c \
	srcs/parser/utils_parser.c \
	srcs/parser/save.c \
	srcs/raycasting2.c \
	srcs/utils.c \
	srcs/event.c \
	srcs/event2.c \
	srcs/event3.c \
	srcs/exit.c \
	srcs/exit2.c \
	srcs/texture.c \
	srcs/start.c \
	srcs/bitmap.c \
	srcs/texture2.c \
	srcs/sprite.c \
	srcs/sprite2.c

OBJS		=	$(SRCS:.c=.o)

RM			=	rm -f

CC			= clang
FLAGS		= -Wall -Werror -Wextra

MLX			= ./minilibx_linux/libmlx.a
MLXLINUX	= ./minilibx_linux/libmlx_Linux.a

NAME		=	Cub3D


all: $(NAME)

$(NAME): $(OBJS)
	@make -s do_configure -C minilibx-linux -f Makefile
	${CC} ${OBJS} $(HEADERS) $(MLX) $(MLXLINUX) -L minilibx_linux -lX11 -lXext -lm -o $(NAME)
	@echo "Cub3d done"

$(MLX):
	@make -C mlx
	@mv mlx/$(MLX) .

clean:
	@make -C mlx clean
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(MLX)

re: fclean all

.PHONY: all clean fclean re
