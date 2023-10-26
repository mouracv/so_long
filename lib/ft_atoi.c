/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleperei <aleperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 12:19:14 by aleperei          #+#    #+#             */
/*   Updated: 2023/05/09 13:22:17 by aleperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		i;
	int		sinal;
	int		num;
	char	*str;

	str = (char *)nptr;
	i = 0;
	num = 0;
	sinal = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sinal = -1;
		i++;
	}
	while (str[i] != '\0' && (str[i] >= '0' && str[i] <= '9'))
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num * sinal);
}

/*int main()
{
    int p;
    int c;

    p = ft_atoi("+-76376");
    printf("ft_atoi = %d\n", p);
    c = atoi("+-76376");
    printf("atoi = %d\n", c);
    return (0);
}*/
