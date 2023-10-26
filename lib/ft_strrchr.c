/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleperei <aleperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 14:39:23 by aleperei          #+#    #+#             */
/*   Updated: 2023/04/25 14:50:47 by aleperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(s);
	while (j >= 0)
	{
		if (s[j] == ((char) c))
		{
			return ((char *)s + j);
		}
		j--;
	}
	return (NULL);
}

/*int	main()
{
	char	str[]= "bank account kabron";

	printf("%s\n", ft_strrchr(str, '@'));
	return (0);
}*/
