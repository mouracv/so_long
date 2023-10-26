/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleperei <aleperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:09:38 by aleperei          #+#    #+#             */
/*   Updated: 2023/04/26 15:32:53 by aleperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(long int n1)
{
	int	i;

	i = 0;
	if (n1 == 0)
		return (1);
	if (n1 < 0)
	{
		i++;
		n1 *= -1;
	}
	while (n1 != 0)
	{
		i++;
		n1 = n1 / 10;
	}
	return (i);
}

static void	ft_write(int len, long int n1, char *str)
{
	while (n1 > 0)
	{
		str[len] = (n1 % 10) + 48;
		n1 /= 10;
		len--;
	}
}

char	*ft_itoa(int n)
{
	long int	n1;
	char		*str;
	int			len;

	n1 = n;
	len = ft_len(n1);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len--] = '\0';
	if (n1 == 0)
	{
		str[0] = 48;
		return (str);
	}
	else if (n1 < 0)
	{
		str[0] = '-';
		n1 *= -1;
	}
	ft_write(len, n1, str);
	return (str);
}

/*int main()
{
    printf("%s\n", ft_itoa(12121));
    return (0);
}*/
