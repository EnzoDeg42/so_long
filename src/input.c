/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edegraev <edegraev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:21:25 by edegraev          #+#    #+#             */
/*   Updated: 2023/12/31 11:06:04 by edegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, t_mlx *game)
{
	if (keycode == 65307)
		quit(game);
	if (keycode == 100 || keycode == 65363)
		player_move(game, 1, 0);
	if (keycode == 97 || keycode == 65361)
		player_move(game, -1, 0);
	if (keycode == 115 || keycode == 65364)
		player_move(game, 0, 1);
	if (keycode == 119 || keycode == 65362)
		player_move(game, 0, -1);
	update(game);
	return (0);
}

int	mouse_press(int button, int x, int y, t_mlx *game)
{
	(void)x;
	(void)y;
	if (button == 1)
		key_press(97, game);
	if (button == 3)
		key_press(100, game);
	if (button == 4)
		key_press(119, game);
	if (button == 5)
		key_press(115, game);
	return (0);
}
