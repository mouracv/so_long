/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleperei <aleperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 14:22:09 by aleperei          #+#    #+#             */
/*   Updated: 2023/10/25 14:30:41 by aleperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

int	main(int argc, char **argv)
{
	t_map	*game;

	check_arg(argc, argv);
	game = ft_calloc(1, sizeof(t_map));
	get_map(game, argv[1]);
	check_map(game);
	start_game(game);
	return (0);
}
