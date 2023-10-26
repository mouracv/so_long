/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_and_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleperei <aleperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 11:16:10 by aleperei          #+#    #+#             */
/*   Updated: 2023/10/25 14:28:56 by aleperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

void	ft_error(char *str, t_map *game)
{
	free_split(game->map);
	free_split(game->flood_fill_map);
	free(game);
	ft_putstr_fd(str, 1);
	exit(EXIT_SUCCESS);
}

void	destroy_img(t_map *game)
{
	if (game->floor.img_ptr)
		mlx_destroy_image(game->mlx, game->floor.img_ptr);
	if (game->wall.img_ptr)
		mlx_destroy_image(game->mlx, game->wall.img_ptr);
	if (game->collec.img_ptr)
		mlx_destroy_image(game->mlx, game->collec.img_ptr);
	if (game->exit.img_ptr)
		mlx_destroy_image(game->mlx, game->exit.img_ptr);
	if (game->player.img_ptr)
		mlx_destroy_image(game->mlx, game->player.img_ptr);
}

int	quit_game(t_map *game)
{
	destroy_img(game);
	mlx_destroy_window(game->mlx, game->mlx_window);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_split(game->map);
	free(game);
	exit(EXIT_SUCCESS);
}
