/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleperei <aleperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:14:07 by aleperei          #+#    #+#             */
/*   Updated: 2023/10/18 13:26:20 by aleperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 9
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_strlen_gnl(char *str);
int		check_nl(char *buffer);

char	*get_next_line(int fd);
char	*free_tmp(char *tmp);
char	*ft_strjoin_free(char *s1, char *s2);
char	*ft_strchr_gnl(char *s, char c);
char	*ft_substr_gnl(char *s, unsigned int start, size_t len);
char	*read_file(int fd, int byte, char *tmp);

void	ft_strcpy(char *dest, char *src);
void	ft_move(char *str);

#endif