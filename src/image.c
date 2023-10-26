/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleperei <aleperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:17:18 by aleperei          #+#    #+#             */
/*   Updated: 2023/10/25 14:28:04 by aleperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

t_img	build_img(char *path, t_map *game)
{
	t_img	img;

	img.img_ptr = mlx_xpm_file_to_image(game->mlx, path, &(img.w), &(img.h));
	return (img);
}

void	init_img(t_map *game)
{
	game->wall = build_img("sprites/wall/wall.xpm", game);
	game->floor = build_img("sprites/floor/floor.xpm", game);
	game->player = build_img("sprites/player/skull.xpm", game);
	game->exit = build_img("sprites/exit/door.xpm", game);
	game->collec = build_img("sprites/collectables/bau.xpm", game);
	if (!game->wall.img_ptr || !game->floor.img_ptr || !game->player.img_ptr
		|| !game->exit.img_ptr || !game->collec.img_ptr)
		quit_game(game);
}

void	push(t_map *game, void *img_ptr, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->mlx_window, img_ptr, x, y);
}

void	find_img(int x, int y, t_map *game, char **map)
{
	if (map[y][x] == '1')
		push(game, game->wall.img_ptr, x * BLOCK_PX, y * BLOCK_PX);
	if (map[y][x] == '0')
		push(game, game->floor.img_ptr, x * BLOCK_PX, y * BLOCK_PX);
	if (map[y][x] == 'P')
		push(game, game->player.img_ptr, x * BLOCK_PX, y * BLOCK_PX);
	if (map[y][x] == 'C')
		push(game, game->collec.img_ptr, x * BLOCK_PX, y * BLOCK_PX);
	if (map[y][x] == 'E')
		push(game, game->exit.img_ptr, x * BLOCK_PX, y * BLOCK_PX);
}

void	draw_img(char **map, t_map *game)
{
	int	x;
	int	y;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			find_img(x, y, game, game->map);
		}
	}
}
