# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aleperei <aleperei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/13 13:20:43 by aleperei          #+#    #+#              #
#    Updated: 2023/10/25 14:08:46 by aleperei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

cc = cc

CFLAGS = -Wall -Werror -Wextra -g
RM = rm -f

SRCS =	src/so_long.c src/check_args.c src/check_map.c src/check_map_2.c src/start_game.c \
		src/flood_fill.c  src/image.c  src/error_and_free.c src/update_map.c \
		GNL/get_next_line.c  GNL/get_next_line_utils.c \
		ft_printf/ft_printf.c  ft_printf/ft_putchar.c  ft_printf/ft_putstr.c  ft_printf/ft_putnbr.c\

MLX = mlx_linux

LIBFT_DIR = ./lib

LIBFT = ./lib/libft.a

OJBS = $(SRCS:.c=.o)

$(NAME):	$(OJBS)
	make -C $(MLX)
	make -C $(LIBFT_DIR)
	$(CC) $(CFLAGS) -lm $(OJBS) $(LIBFT) -L ./mlx_linux -lmlx -Ilmlx -lXext -lX11 -o $(NAME)

all: $(NAME)

clean:
		make clean -C $(LIBFT_DIR)
		$(RM) $(OJBS)

fclean:	clean
		make fclean -C $(LIBFT_DIR)
		$(RM) $(NAME)

download_mlx:
	@ curl -O https://cdn.intra.42.fr/document/document/32342/minilibx-linux.tgz && tar -xvzf minilibx-linux.tgz
	@ tar -xvzf minilibx-linux.tgz && mv minilibx-linux $(MLX)
	@ rm -rf minilibx-linux.tgz

delete_all: fclean 
	@ rm -rf $(MLX)

re: fclean all

.PHONY: all clean fclean re