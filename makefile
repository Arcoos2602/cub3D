# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thomas <thomas@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/04 15:35:18 by tcordonn          #+#    #+#              #
#    Updated: 2021/05/21 15:29:36 by thomas           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS := srcs/init.c \
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

NAME = Cub3D

MLX_DIR = minilibx_linux
MLX = libmlx.a 
CC = clang

CFLAGS = -Wall -Wextra -Werror

OBJ_DIR = obj
SRC_DIR = srcs
HEAD = includes

all:
	$(MAKE) -j $(NAME)

$(NAME): $(OBJ)
		${CC} $(CFLAGS) -o $(NAME) $(OBJ) -L $(MLX_DIR) -lmlx -lm -lbsd -lX11 -lXext

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		@mkdir -p $(OBJ_DIR)
		${CC} $(CFLAGS) -I $(HEAD) -I $(MLX_DIR) -c $< -o $@

.gitignore:
		@echo $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean:	clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re