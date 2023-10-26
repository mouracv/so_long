/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleperei <aleperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:52:15 by aleperei          #+#    #+#             */
/*   Updated: 2023/10/25 14:40:51 by aleperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

char	*ext_map(int fd)
{
	char	*line;
	char	*all;

	line = NULL;
	all = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		all = ft_strjoin_free(all, line);
		free(line);
	}
	return (all);
}

void	get_map(t_map *game, char *fpaht)
{
	int		fd;
	char	*all;

	all = NULL;
	fd = open(fpaht, O_RDONLY);
	if (fd == -1)
		ft_error("ERROR: File was not opened.\n", game);
	all = ext_map(fd);
	close(fd);
	if (!all)
		ft_error("ERROR: Empty file!\n", game);
	if (check_empty_line(all) == 1)
	{
		free(all);
		ft_error("ERROR: Empty line in the map!\n", game);
	}
	game->map = ft_split(all, '\n');
	game->flood_fill_map = ft_split(all, '\n');
	free(all);
}

void	check_map_walls(t_map *game)
{
	int	i;

	i = 0;
	if (check_line(game->map[0]) || check_line(game->map[game->map_heigth - 1]))
		ft_error("ERROR: Map not surround for walls\n", game);
	while (game->map[i] != NULL)
	{
		if (game->map[i][0] != '1' || game->map[i][game->map_length - 1] != '1')
		{
			ft_error("ERROR: Map not surround for walls\n", game);
		}
		i++;
	}
	return ;
}

void	check_map_form(t_map *game)
{
	int	heigth;
	int	i;

	heigth = 0;
	i = 1;
	game->map_length = ft_strlen(game->map[0]);
	while (game->map[heigth] != NULL)
		heigth++;
	game->map_heigth = heigth;
	while (game->map[i] != NULL)
	{
		if ((game->map_length) != ft_strlen(game->map[i]))
			ft_error("ERROR: Map is not rectangular.\n", game);
		i++;
	}
}

void	check_map(t_map *game)
{
	check_map_form(game);
	check_map_walls(game);
	check_other(game);
	if (valid_path(game) == 1)
		ft_error("ERROR: MAp is not playable.\n", game);
}
