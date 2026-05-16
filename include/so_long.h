/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edegraev <edegraev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 17:04:01 by edegraev          #+#    #+#             */
/*   Updated: 2026/05/16 14:25:31 by edegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>

# ifdef __APPLE__
#  include "../minilibx-mac/mlx.h"
# else
#  include "../minilibx-linux/mlx.h"
# endif
# include "../ft_printf/include/ft_printf.h"
# include "../ft_printf/include/libft.h"

# ifdef __APPLE__
#  define KEY_ESC 53
#  define KEY_W 13
#  define KEY_A 0
#  define KEY_S 1
#  define KEY_D 2
#  define KEY_UP 126
#  define KEY_DOWN 125
#  define KEY_LEFT 123
#  define KEY_RIGHT 124
# else
#  define KEY_ESC 65307
#  define KEY_W 119
#  define KEY_A 97
#  define KEY_S 115
#  define KEY_D 100
#  define KEY_UP 65362
#  define KEY_DOWN 65364
#  define KEY_LEFT 65361
#  define KEY_RIGHT 65363
# endif

typedef struct s_data
{
	void	*img_ptr;
	char	img_type;
	int		width;
	int		height;
	size_t	pos_x;
	size_t	pos_y;
	int		visited;
}				t_data;

typedef struct s_path
{
	int	exit_found;
	int	exit_exist;
	int	points_exist;
	int	points_found;
	int	spawn_exist;
}				t_path;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
	t_data	player;
	t_data	*map;
	t_path	path;
	size_t	num_tiles;
	size_t	tile_size;
	size_t	texture_size;
	size_t	map_width;
	size_t	map_height;
	int		player_step;
	int		player_points;
}				t_mlx;

typedef struct s_map_info
{
	t_mlx	*game;
	int		len;
	int		x;
	int		y;
}			t_map_info;

//  closed.c
int		map_is_closed(t_mlx *game);

// error.c
void	map_check_error(t_mlx *game);
void	spawn_check_error(t_mlx *game);

// ft_itoa.c
char	*ft_itoa(int n);

// ft_strcmp.c
int		ft_strcmp(char *s1, char *s2);

// game.c
void	update(t_mlx *game);
int		quit(t_mlx *game);
void	set_game_values(t_mlx *game);

// input.c
int		key_press(int keycode, t_mlx *game);
int		mouse_press(int button, int x, int y, t_mlx *game);

// map_ext.c
void	process_tile(t_mlx *game, char type, t_map_info *map_info);

// map.c
void	load_map(t_mlx *game, char *map_file);
void	create_map(t_mlx *game, char *map_file);

// move.c
size_t	player_move(t_mlx *game, int dx, int dy);

// path.c
void	recursive_explorer(t_mlx *game, int x, int y);

// so_long.c
char	*get_texture_name(char *name, int scale);
int		main(int argc, char **argv);

// tile.c
t_data	*get_tile(t_mlx *game, size_t x, size_t y);
void	set_empty_tile(t_mlx *game, size_t x, size_t y, char type);

// mlx_destroy_display.c
int		mlx_destroy_display(void *mlx_ptr);

#endif