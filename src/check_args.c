/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleperei <aleperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 10:48:24 by aleperei          #+#    #+#             */
/*   Updated: 2023/10/25 16:18:48 by aleperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/so_long.h"

void	check_argc(int argc)
{
	if (argc == 2)
		return ;
	if (argc > 2)
	{
		ft_putstr_fd("ERROR: Too mane arguments\n", 1);
		exit(EXIT_SUCCESS);
	}
	else
	{
		ft_putstr_fd("ERROR: Too few arguments\n", 1);
		exit(EXIT_SUCCESS);
	}
}

void	check_argv(char *argv)
{
	argv = ft_strchr(argv, '.');
	if (ft_strncmp(argv, ".ber", 4) != 0)
	{
		ft_putstr_fd("ERROR: Wrong file\n", 1);
		exit(EXIT_SUCCESS);
	}
}

void	check_arg(int argc, char **argv)
{
	check_argc(argc);
	check_argv(argv[1]);
}
