/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleperei <aleperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:51:39 by aleperei          #+#    #+#             */
/*   Updated: 2023/05/02 15:14:32 by aleperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	return (str);
}

/*int	main()
{
	char	str[10];
	char	*str1;
	char	*str2;

	str1 = ft_memset(str, 'a', 6);
	str2 = memset(str, 'a', 6);

	printf("%s \n",str1);
	printf("%s \n",str2);
	return (0);
}*/
