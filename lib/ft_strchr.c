/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleperei <aleperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:27:48 by aleperei          #+#    #+#             */
/*   Updated: 2023/04/25 14:23:42 by aleperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	k;
	int				i;

	i = 0;
	k = c;
	while (s[i] != '\0')
	{
		if (s[i] == k)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == k)
		return ((char *)s + i);
	return (NULL);
}

/*int	main()
{
	char	str[]= "teste";

	printf("%s\n", ft_strchr(str, 'e'));
	return (0);
}*/
