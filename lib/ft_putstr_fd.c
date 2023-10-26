/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleperei <aleperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:11:17 by aleperei          #+#    #+#             */
/*   Updated: 2023/10/06 12:15:28 by aleperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *c, int fd)
{
	int	i;

	i = 0;
	while (c[i] != '\0')
	{
		ft_putchar_fd(c[i], fd);
		i++;
	}
}

/*int main(void)
{
    char    *str = "Alexsandro";
    ft_putstr_fd(str, 1);
    write(1, "\n", 1);
    return (0);
}*/
