/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleperei <aleperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 12:20:34 by aleperei          #+#    #+#             */
/*   Updated: 2023/10/25 14:29:45 by aleperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

int	check_line(char *line)
{
	while (*line)
	{
		if (*line != '1')
			return (1);
		line++;
	}
	return (0);
}

int	check_empty_line(char *map)
{
	int	i;

	i = -1;
	while (map[++i] != '\0')
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
		{
			return (1);
		}
	}
	return (0);
}

void	save_xy(t_map *game, char c, int y, int x)
{
	if (c == 'P')
	{
		game->pl_y = y;
		game->pl_x = x;
		game->num_p++;
	}
	else if (c == 'E')
	{
		game->ext_y = y;
		game->ext_x = x;
		game->num_e++;
	}
}

void	check_other(t_map *game)
{
	int	y;
	int	x;

	y = -1;
	while (game->map[++y] != NULL)
	{
		x = -1;
		while (game->map[y][++x] != '\0')
		{
			if (game->map[y][x] == 'C')
				game->num_c++;
			else if (game->map[y][x] == 'P')
				save_xy(game, 'P', y, x);
			else if (game->map[y][x] == 'E')
				save_xy(game, 'E', y, x);
			else if (game->map[y][x] != '1' && game->map[y][x] != '0')
				ft_error("ERROR: Found a strange caracter!\n", game);
		}
	}
	if (game->num_p != 1 || game->num_e != 1)
		ft_error("ERROR: See if you have one player and one exit only!\n",
			game);
	else if (game->num_c < 1)
		ft_error("ERROR: You don't have any collectables!\n", game);
}
