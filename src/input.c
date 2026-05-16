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
	if (keycode == KEY_ESC)
		quit(game);
	if (keycode == KEY_D || keycode == KEY_RIGHT)
		player_move(game, 1, 0);
	if (keycode == KEY_A || keycode == KEY_LEFT)
		player_move(game, -1, 0);
	if (keycode == KEY_S || keycode == KEY_DOWN)
		player_move(game, 0, 1);
	if (keycode == KEY_W || keycode == KEY_UP)
		player_move(game, 0, -1);
	update(game);
	return (0);
}

int	mouse_press(int button, int x, int y, t_mlx *game)
{
	(void)x;
	(void)y;
	if (button == 1)
		key_press(KEY_A, game);
	if (button == 3)
		key_press(KEY_D, game);
	if (button == 4)
		key_press(KEY_W, game);
	if (button == 5)
		key_press(KEY_S, game);
	return (0);
}
