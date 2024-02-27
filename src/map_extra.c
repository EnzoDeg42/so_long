/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_extra.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edegraev <edegraev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 13:31:56 by edegraev          #+#    #+#             */
/*   Updated: 2024/01/05 10:13:15 by edegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	texture_to_char(char *texture_name)
{
	if (ft_strcmp(texture_name, "bricks") == 0)
		return ('1');
	else if (ft_strcmp(texture_name, "potion") == 0)
		return ('C');
	else if (ft_strcmp(texture_name, "bh") == 0)
		return ('E');
	else if (ft_strcmp(texture_name, "empty") == 0)
		return (0);
	else if (ft_strcmp(texture_name, "sachi") == 0)
		return ('P');
	return ('0');
}

static void	set_tile(t_mlx *game, char *texture_name, int len)
{
	char	*full_texture_name;
	char	type;

	type = texture_to_char(texture_name);
	if (texture_name[0] != '\0')
	{
		full_texture_name = get_texture_name(texture_name, game->texture_size);
		game->map[len].img_ptr = mlx_xpm_file_to_image(game->mlx,
				full_texture_name,
				&game->map[len].width, &game->map[len].height);
		free(full_texture_name);
	}
	game->map[len].visited = 0;
	game->map[len].img_type = type;
	if (type == 'C')
		game->path.points_exist++;
	else if (type == 'E')
		game->path.exit_exist++;
}

static void	set_tile_pos(t_mlx *game, int len, int x, int y)
{
	game->map[len].pos_x = x;
	game->map[len].pos_y = y;
}

static void	set_tile_player(t_mlx *game, int len, int x, int y)
{
	char	*full_texture_name;

	game->path.spawn_exist++;
	if (game->path.spawn_exist > 1)
	{
		ft_printf("Error\nThere is more than one player spawn on the map\n");
		quit(game);
	}
	full_texture_name = get_texture_name("sachi", game->texture_size);
	game->player.img_ptr = mlx_xpm_file_to_image(game->mlx,
			full_texture_name, &game->player.width,
			&game->player.height);
	free(full_texture_name);
	set_tile(game, "empty", len);
	set_tile_pos(game, len, x, y);
	game->player.pos_x = x * game->tile_size;
	game->player.pos_y = y * game->tile_size;
}

void	process_tile(t_mlx *game, char type, t_map_info *map_info)
{
	if (type == '1')
		set_tile(game, "bricks", map_info->len);
	else if (type == 'C')
		set_tile(game, "potion", map_info->len);
	else if (type == 'E')
		set_tile(game, "bh", map_info->len);
	else if (type == 'P')
		set_tile_player(game, map_info->len, map_info->x, map_info->y);
	else if (type == '0')
		set_tile(game, "empty", map_info->len);
	else
	{
		ft_printf("Error\nInvalid character in map (%c)\n", type);
		quit(game);
	}
	set_tile_pos(game, map_info->len, map_info->x, map_info->y);
}
