/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edegraev <edegraev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 21:34:24 by edegraev          #+#    #+#             */
/*   Updated: 2024/01/11 10:45:19 by edegraev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_texture_name(char *name, int scale)
{
	char	*str_scale;
	char	*str;

	str_scale = ft_itoa(scale);
	str = malloc(sizeof(char) * (strlen("assets/textures/") + strlen(name)
				+ strlen("_x") + strlen(str_scale) + strlen(".xpm") + 1));
	if (!str)
		return (NULL);
	strcpy(str, "assets/textures/");
	strcat(str, name);
	strcat(str, "_x");
	strcat(str, str_scale);
	strcat(str, ".xpm");
	free(str_scale);
	return (str);
}

void	run_game_loop(t_mlx *game)
{
	recursive_explorer(game, game->player.pos_x / game->tile_size,
		game->player.pos_y / game->tile_size);
	map_check_error(game);
	update(game);
	mlx_key_hook(game->mlx_win, key_press, game);
	mlx_mouse_hook(game->mlx_win, mouse_press, game);
	mlx_hook(game->mlx_win, 17, 0, quit, game);
	mlx_loop(game->mlx);
}

int	game_init(int argc, char **argv, t_mlx *game)
{
	(void)argc;
	game->tile_size = 32 * game->texture_size;
	load_map(game, argv[1]);
	if (game->num_tiles == 0)
	{
		ft_printf("Error\nMap is empty\n");
		return (0);
	}
	game->map = malloc(game->num_tiles * sizeof(t_data));
	if (!game->map)
		return (0);
	ft_memset(game->map, 0, game->num_tiles * sizeof(t_data));
	game->mlx = mlx_init();
	if (!game->mlx)
		return (0);
	game->mlx_win = mlx_new_window(game->mlx, game->map_width * game->tile_size,
			game->map_height * game->tile_size, "sachi");
	create_map(game, argv[1]);
	if (!map_is_closed(game))
	{
		ft_printf("Error\nMap is not closed\n");
		quit(game);
	}
	spawn_check_error(game);
	return (1);
}

int	main(int argc, char **argv)
{
	t_mlx	game;

	if (argc != 2 && argc != 3)
	{
		ft_printf("./so_long <map.ber> [size=1-4]\n");
		return (0);
	}
	set_game_values(&game);
	if (argc == 3)
	{
		game.texture_size = atoi(argv[2]);
		if (game.texture_size < 1 || game.texture_size > 4)
		{
			ft_printf("Error\nTexture size must be between 1 and 4\n");
			return (0);
		}
	}
	if (game_init(argc, argv, &game) == 0)
		return (0);
	run_game_loop(&game);
	return (0);
}
