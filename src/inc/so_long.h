/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleperei <aleperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 14:22:24 by aleperei          #+#    #+#             */
/*   Updated: 2023/10/25 14:27:08 by aleperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../../GNL/get_next_line.h"
# include "../../ft_printf/ft_printf.h"
# include "../../libft/libft.h"
# include "../../mlx_linux/mlx.h"
# include "constants.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct img_info
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		endian;
	int		line_len;
	int		w;
	int		h;
}			t_img;

typedef struct info_map
{
	char	**map;
	char	**flood_fill_map;
	int		map_length;
	int		map_heigth;
	int		num_c;
	int		num_p;
	int		num_e;
	int		pl_x;
	int		pl_y;
	int		ext_x;
	int		ext_y;
	int		move_count;

	t_img	wall;
	t_img	floor;
	t_img	player;
	t_img	collec;
	t_img	exit;

	void	*mlx;
	void	*mlx_window;
}			t_map;

/*check arguments*/
void		check_argc(int argc);
void		check_argv(char *argv);
void		check_arg(int argc, char **argv);

/*check if map repect the rules*/
void		check_map(t_map *game);
int			check_line(char *line);
int			valid_path(t_map *game);
void		check_other(t_map *game);
void		check_map_form(t_map *game);
int			check_empty_line(char *map);
void		get_map(t_map *game, char *fpaht);
void		save_xy(t_map *game, char c, int y, int x);
void		flood_fill(char **map, int x, int y, int *counter);

/*Starting game and  creating the sprites*/
void		init_img(t_map *game);
void		start_game(t_map *game);
t_img		build_img(char *path, t_map *game);
void		draw_img(char **map, t_map *game);
void		find_img(int x, int y, t_map *game, char **map);
void		push(t_map *game, void *img_ptr, int x, int y);
void		draw_player(t_map *game, int x, int y);
void		update_map(t_map *game, int prv_x, int prv_y);

/*Error and Frees*/
int			quit_game(t_map *game);
void		destroy_img(t_map *game);
void		ft_error(char *str, t_map *game);

#endif