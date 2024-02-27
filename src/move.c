/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edegraev <edegraev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 15:55:28 by edegraev          #+#    #+#             */
/*   Updated: 2023/12/31 14:12:29 by edegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	update_player_position(t_mlx *game, int dx, int dy)
{
	game->player.pos_x += dx * game->tile_size;
	game->player.pos_y += dy * game->tile_size;
	game->player_step++;
	ft_printf("step: %ld\n", game->player_step);
}

size_t	player_move(t_mlx *game, int dx, int dy)
{
	int		x;
	int		y;
	t_data	tile;

	x = game->player.pos_x / game->tile_size + dx;
	y = game->player.pos_y / game->tile_size + dy;
	tile = *get_tile(game, x, y);
	if (tile.img_type == '1')
		return (0);
	if (tile.img_type == 'C')
	{
		game->player_points++;
		set_empty_tile(game, x, y, '0');
	}
	if (tile.img_type == 'E' && game->player_points == game->path.points_exist)
	{
		ft_printf("You win!\n");
		quit(game);
	}
	update_player_position(game, dx, dy);
	return (1);
}
