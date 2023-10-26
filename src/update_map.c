/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleperei <aleperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:19:26 by aleperei          #+#    #+#             */
/*   Updated: 2023/10/25 14:32:57 by aleperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

void	draw_player(t_map *game, int x, int y)
{
	if (game->map[y][x] == 'E' && game->num_c == 0)
	{
		quit_game(game);
	}
	game->map[y][x] = 'P';
	game->move_count++;
	ft_printf("Moves: %d\n", game->move_count);
	find_img(x, y, game, game->map);
}

void	update_map(t_map *game, int prv_x, int prv_y)
{
	if (game->map[game->pl_y][game->pl_x] != '1')
	{
		if (game->map[game->pl_y][game->pl_x] == 'E')
		{
			if (game->num_c == 0)
				return (draw_player(game, game->pl_x, game->pl_y));
			game->pl_x = prv_x;
			game->pl_y = prv_y;
			return ;
		}
		if (game->map[game->pl_y][game->pl_x] == 'C')
			game->num_c--;
		if (game->map[prv_y][prv_x] == 'P')
		{
			game->map[prv_y][prv_x] = '0';
			find_img(prv_x, prv_y, game, game->map);
		}
		draw_player(game, game->pl_x, game->pl_y);
	}
	else
	{
		game->pl_x = prv_x;
		game->pl_y = prv_y;
	}
}
