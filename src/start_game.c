/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleperei <aleperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:33:19 by aleperei          #+#    #+#             */
/*   Updated: 2023/10/25 14:32:26 by aleperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

int	on_keypress(int keycode, t_map *game)
{
	int	prv_x;
	int	prv_y;

	prv_x = game->pl_x;
	prv_y = game->pl_y;
	if (keycode == ESC)
		quit_game(game);
	if (keycode == ARROW_UP || keycode == KEY_W)
		game->pl_y--;
	if (keycode == ARROW_LEFT || keycode == KEY_A)
		game->pl_x--;
	if (keycode == ARROW_RIGHT || keycode == KEY_D)
		game->pl_x++;
	if (keycode == ARROW_DOWN || keycode == KEY_S)
		game->pl_y++;
	update_map(game, prv_x, prv_y);
	return (0);
}

void	start_game(t_map *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_error("Error: Error initializing Minilibx library", game);
	game->mlx_window = mlx_new_window(game->mlx, game->map_length * BLOCK_PX, \
		game->map_heigth * BLOCK_PX, "so_long");
	init_img(game);
	draw_img(game->map, game);
	mlx_hook(game->mlx_window, 02, (1L << 0), on_keypress, game);
	mlx_hook(game->mlx_window, 17, 0, quit_game, game);
	mlx_loop(game->mlx);
}
