/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closed.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edegraev <edegraev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 17:45:25 by edegraev          #+#    #+#             */
/*   Updated: 2024/01/01 11:19:18 by edegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_row_closed(t_mlx *game, size_t row, size_t s_col, size_t end_col)
{
	size_t	col;

	col = s_col;
	while (col <= end_col)
	{
		if (get_tile(game, col, row)->img_type != '1')
			return (0);
		col++;
	}
	return (1);
}

static int	is_col_closed(t_mlx *game, size_t col, size_t s_row, size_t e_row)
{
	size_t	row;

	row = s_row;
	while (row <= e_row)
	{
		if (get_tile(game, col, row)->img_type != '1')
			return (0);
		row++;
	}
	return (1);
}

static int	check_last_line(t_mlx *game)
{
	size_t	i;
	size_t	x;

	i = game->map_width - 2;
	x = game->map_width - 2;
	while (i > 0)
	{
		if (get_tile(game, x, game->map_height - 1)->img_type != '1')
			return (0);
		i--;
		x--;
	}
	return (1);
}

int	map_is_closed(t_mlx *game)
{
	size_t	j;
	size_t	y;

	if (!is_row_closed(game, 0, 0, game->map_width - 1))
		return (0);
	if (!is_col_closed(game, game->map_width - 1, 1, game->map_height - 2))
		return (0);
	if (!check_last_line(game))
		return (0);
	j = game->map_height - 2;
	y = game->map_height - 2;
	while (j > 0)
	{
		if (get_tile(game, 0, y)->img_type != '1')
			return (0);
		j--;
		y--;
	}
	return (1);
}
