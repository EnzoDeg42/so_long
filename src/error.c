/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edegraev <edegraev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 11:07:40 by edegraev          #+#    #+#             */
/*   Updated: 2024/01/05 10:11:39 by edegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_check_error(t_mlx *game)
{
	if (game->path.exit_found > 1)
	{
		ft_printf("Error\nThere are more than one exit on the map\n");
		quit(game);
	}
	if (game->path.points_exist < 1)
	{
		ft_printf("Error\nThere are no collectibles on the map\n");
		quit(game);
	}
	if (game->path.exit_found != 1 || game->path.exit_exist != 1)
	{
		ft_printf("Error\nThe number of exits is not identical to the number");
		ft_printf(" on the map [%d/%d]\n", game->path.exit_found,
			game->path.exit_exist);
		quit(game);
	}
	if (game->path.points_found != game->path.points_exist)
	{
		ft_printf("Error\nThe number of accessible collectibles is not ");
		ft_printf("identical to the number on the map [%d/%d]\n",
			game->path.points_found, game->path.points_exist);
		quit(game);
	}
}

void	spawn_check_error(t_mlx *game)
{
	if (game->path.spawn_exist < 1)
	{
		ft_printf("Error\nThere is no player spawn on the map\n");
		quit(game);
	}
	if (game->path.spawn_exist > 1)
	{
		ft_printf("Error\nThere is more than one player spawn on the map\n");
		quit(game);
	}
}
