/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleperei <aleperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:33:47 by aleperei          #+#    #+#             */
/*   Updated: 2023/10/25 14:29:20 by aleperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

void	flood_fill(char **map, int x, int y, int *counter)
{
	if (map[y][x] == 'C' || map[y][x] == 'E')
		*counter += 1;
	if (map[y][x] == 'E')
	{
		map[y][x] = '1';
		return ;
	}
	map[y][x] = 'P';
	if (map[y][x + 1] != '1' && map[y][x + 1] != 'P')
		flood_fill(map, x + 1, y, counter);
	if (map[y][x - 1] != '1' && map[y][x - 1] != 'P')
		flood_fill(map, x - 1, y, counter);
	if (map[y + 1][x] != '1' && map[y + 1][x] != 'P')
		flood_fill(map, x, y + 1, counter);
	if (map[y - 1][x] != '1' && map[y - 1][x] != 'P')
		flood_fill(map, x, y - 1, counter);
}

int	valid_path(t_map *game)
{
	int	counter;

	counter = 0;
	flood_fill(game->flood_fill_map, game->pl_x, game->pl_y, &counter);
	free_split(game->flood_fill_map);
	game->flood_fill_map = NULL;
	if (counter != (game->num_c + game->num_e))
		return (1);
	else
		return (0);
}
