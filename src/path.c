/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edegraev <edegraev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:00:54 by edegraev          #+#    #+#             */
/*   Updated: 2024/01/01 10:41:43 by edegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_case_type(t_mlx *game, int x, int y, char type)
{
	return (get_tile(game, x, y)->img_type == type);
}

void	recursive_explorer(t_mlx *game, int x, int y)
{
	if (get_tile(game, x, y)->img_type == 'E')
		game->path.exit_found++;
	if (get_tile(game, x, y)->img_type == 'C')
		game->path.points_found++;
	get_tile(game, x, y)->visited = 1;
	if (is_case_type(game, x + 1, y, '1') == 0
		&& get_tile(game, x + 1, y)->visited == 0)
		recursive_explorer(game, x + 1, y);
	if (is_case_type(game, x - 1, y, '1') == 0
		&& get_tile(game, x - 1, y)->visited == 0)
		recursive_explorer(game, x - 1, y);
	if (is_case_type(game, x, y + 1, '1') == 0
		&& get_tile(game, x, y + 1)->visited == 0)
		recursive_explorer(game, x, y + 1);
	if (is_case_type(game, x, y - 1, '1') == 0
		&& get_tile(game, x, y - 1)->visited == 0)
		recursive_explorer(game, x, y - 1);
}
