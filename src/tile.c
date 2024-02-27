/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tile.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edegraev <edegraev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:16:16 by edegraev          #+#    #+#             */
/*   Updated: 2023/12/31 17:32:54 by edegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_data	*get_tile(t_mlx *game, size_t x, size_t y)
{
	t_data	*tile;
	size_t	i;

	if (x >= game->map_width || y >= game->map_height)
		return (0);
	i = 0;
	while (i < game->num_tiles)
	{
		tile = &game->map[i];
		if (tile->pos_x == x && tile->pos_y == y)
			return (tile);
		i++;
	}
	return (NULL);
}

void	set_empty_tile(t_mlx *game, size_t x, size_t y, char type)
{
	t_data	*tile;

	tile = get_tile(game, x, y);
	if (tile)
		tile->img_type = type;
}
