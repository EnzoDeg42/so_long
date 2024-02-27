/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edegraev <edegraev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 10:44:22 by edegraev          #+#    #+#             */
/*   Updated: 2024/01/04 08:59:29 by edegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update(t_mlx *game)
{
	size_t	i;

	mlx_clear_window(game->mlx, game->mlx_win);
	i = 0;
	while (i < game->num_tiles)
	{
		if (game->map[i].img_ptr && game->map[i].img_type != '0')
			mlx_put_image_to_window(game->mlx, game->mlx_win,
				game->map[i].img_ptr, game->map[i].pos_x * game->tile_size,
				game->map[i].pos_y * game->tile_size);
		i++;
	}
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->player.img_ptr,
		game->player.pos_x, game->player.pos_y);
}

int	quit(t_mlx *game)
{
	size_t	i;

	i = 0;
	while (i < game->num_tiles)
	{
		if (game->map[i].img_ptr != NULL)
		{
			mlx_destroy_image(game->mlx, game->map[i].img_ptr);
			game->map[i].img_ptr = NULL;
		}
		else
		{
			free(game->map[i].img_ptr);
			game->map[i].img_ptr = NULL;
		}
		i++;
	}
	if (game->player.img_ptr != NULL)
		mlx_destroy_image(game->mlx, game->player.img_ptr);
	game->player.img_ptr = NULL;
	mlx_destroy_window(game->mlx, game->mlx_win);
	mlx_destroy_display(game->mlx);
	free(game->map);
	free(game->mlx);
	exit(0);
}

void	set_game_values(t_mlx *game)
{
	game->texture_size = 2;
	game->path.exit_found = 0;
	game->path.exit_exist = 0;
	game->path.points_found = 0;
	game->path.spawn_exist = 0;
	game->path.points_exist = 0;
	game->player_points = 0;
	game->player_step = 0;
	game->player.img_ptr = NULL;
}
