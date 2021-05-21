# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thomas <thomas@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/04 15:35:18 by tcordonn          #+#    #+#              #
#    Updated: 2021/05/21 14:58:40 by thomas           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cub3D

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

MLX = -I ./include -lmlx -lm -framework OpenGL -framework AppKit
LMLX = -L./libft -lft -I/usr/local/include -L/usr/local/lib -lmlx -L/usr/include -lm -lbsd -lX11 -lXext
LMLX_2 = -L./libft -lft ./minilibx_linux/libmlx.a -lm -lbsd -lX11 -lXext
LMLX_3 = -L./libft -lft  -lmlx  -lm -lbsd -lX11 -lXext
BOFT = $(BO:.c=.o)
OBJ = $(SRCS:.c=.o)
HEAD = include
CFLAGS = -Wall -Werror -Wextra -lm -I $(HEAD)
CC = gcc
LIB = ./libft/libft.a
all: $(NAME)
$(NAME): $(OBJ)
	make -C ./libft
	gcc $(SRCS) $(CFLAGS) -o $(NAME) $(LMLX_3)
clean :
	make -C ./libft clean
	rm -f $(OBJ)
fclean : clean
	make -C ./libft fclean
	rm -f $(NAME)
re: fclean all
.PHONY: bonus  all clean fclean r e