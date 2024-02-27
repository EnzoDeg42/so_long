/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edegraev <edegraev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:44:14 by edegraev          #+#    #+#             */
/*   Updated: 2024/01/09 15:11:14 by edegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static size_t	read_map_file(int fd, t_mlx *game)
{
	char	buffer[1];
	size_t	x;

	x = 0;
	game->num_tiles = 0;
	game->map_width = 0;
	game->map_height = 1;
	while (read(fd, buffer, sizeof(buffer)))
	{
		if (buffer[0] == '\n')
		{
			game->map_height++;
			if (game->map_width == 0)
				game->map_width = x;
			if (x != game->map_width && ft_printf("Error\nMap width\n"))
				exit(0);
			x = 0;
			continue ;
		}
		x++;
		game->num_tiles++;
	}
	return (x);
}

void	load_map(t_mlx *game, char *map_file)
{
	int		fd;
	size_t	x;

	fd = open(map_file, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nCannot open file\n");
		exit(0);
	}
	x = read_map_file(fd, game);
	close(fd);
	if (game->map_width == 0 || x != game->map_width)
	{
		ft_printf("Error\nMap is not rectangular\n");
		exit(0);
	}
}

void	create_map(t_mlx *game, char *map_file)
{
	int			fd;
	char		buffer[1];
	t_map_info	map_info;

	fd = open(map_file, O_RDONLY);
	if (fd == -1 && ft_printf("Error\nCannot open file\n"))
		exit(0);
	map_info.game = game;
	map_info.len = 0;
	map_info.x = 0;
	map_info.y = 0;
	while (read(fd, buffer, sizeof(buffer)))
	{
		if (buffer[0] == '\n')
		{
			map_info.y++;
			map_info.x = 0;
			continue ;
		}
		process_tile(game, buffer[0], &map_info);
		map_info.x++;
		map_info.len++;
	}
	close(fd);
}
