# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thomas <thomas@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/04 15:35:18 by tcordonn          #+#    #+#              #
#    Updated: 2021/05/21 13:01:00 by thomas           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Cub3D
HEAD := -I./includes/ -I./minilibx_opengl_20191021 -I./libft/includes

CFLAGS = -Wall -Wextra -Werror

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

LMLX = minilibx_opengl_20191021/libmlx.a -framework OpenGL -framework AppKit

LMLX_2 = -L./libft -lft ./minilibx-linux/libmlx.a -lm -lbsd -lX11 -lXext

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./Libft
	gcc -g $(HEAD) $(LMLX) $(OBJS) -o $(NAME) -L./libft -lft

G: $(OBJS)
	make -C ./Libft
	gcc -g3 -fsanitize=address $(CFLAGS) $(HEAD) $(LMLX) $(OBJS) -o $(NAME) -L./libft -lft

clean:
	rm -rf $(OBJS) objs
	make clean -sC libft

fclean:
	make fclean -sC libft
	rm -rf $(NAME) $(OBJS) objs screen.bmp

re:	fclean
	make all
