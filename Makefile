# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edegraev <edegraev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/15 11:56:11 by edegraev          #+#    #+#              #
#    Updated: 2024/01/16 16:52:18 by edegraev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRC = src/closed.c src/ft_itoa.c src/ft_strcmp.c src/input.c src/map_extra.c src/path.c src/tile.c src/error.c src/ft_memset.c src/game.c src/map.c src/move.c src/so_long.c
CC = cc
CFLAGS = -Wall -Wextra -Werror

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Darwin)
	MLX_DIR = minilibx-mac
	MLX_LIB = $(MLX_DIR)/libmlx.a
	LDFLAGS = -framework OpenGL -framework AppKit
	SRC += src/mlx_destroy_display.c
else
	MLX_DIR = minilibx-linux
	MLX_LIB = $(MLX_DIR)/libmlx_Linux.a
	LDFLAGS = -lXext -lX11 -lm -lbsd
endif

OBJ = $(SRC:.c=.o)

%.o: %.c
	$(CC) -c $< -o $@ -I./include $(CFLAGS)

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(MLX_DIR)
	$(MAKE) -C ft_printf
	$(CC) $(OBJ) $(MLX_LIB) ft_printf/libftprintf.a -L./$(MLX_DIR) $(LDFLAGS) -o $(NAME)

clean:
	rm -rf $(OBJ) ft_printf/*.o $(MLX_DIR)/*.o
	$(MAKE) -C ft_printf clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -rf $(OBJ) $(NAME) ft_printf/libftprintf.a $(MLX_DIR)/libmlx*.a
	$(MAKE) -C ft_printf fclean
	$(MAKE) -C $(MLX_DIR) clean

norm:
	norminette $(SRC) include/so_long.h

re: fclean all

.PHONY: all clean fclean re 