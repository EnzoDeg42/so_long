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
OBJ = $(SRC:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -lXext -lX11 -lm -lbsd

%.o: %.c
	$(CC) -c $< -o $@ -I./include $(CFLAGS)

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C minilibx-linux
	$(MAKE) -C ft_printf
	$(CC) $(OBJ) minilibx-linux/libmlx_Linux.a ft_printf/libftprintf.a -L./minilibx-linux $(LDFLAGS) -o $(NAME)

clean:
	rm -rf $(OBJ) ft_printf/*.o minilibx-linux/*.o
	$(MAKE) -C ft_printf clean
	$(MAKE) -C minilibx-linux clean

fclean: clean
	rm -rf $(OBJ) $(NAME) ft_printf/libftprintf.a minilibx-linux/libmlx_Linux.a minilibx-linux/libmlx.a
	$(MAKE) -C ft_printf fclean
	$(MAKE) -C minilibx-linux clean

norm:
	norminette $(SRC) include/so_long.h

re: fclean all

.PHONY: all clean fclean re 