/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleperei <aleperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 12:03:25 by aleperei          #+#    #+#             */
/*   Updated: 2023/04/20 09:30:04 by aleperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (str[i] == ((unsigned char)c))
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}

/*int	main()
{
	char	str[]= {'1','2','3','a','r','t','c',};
	char	*str1;
	char	*str2;

	str1 = ft_memchr(str, '@', 7);
	str2 = memchr(str, '@', 7);

	printf("%s \n",str1);
	printf("%s \n",str2);
	return (0);
}*/
