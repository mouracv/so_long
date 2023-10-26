/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleperei <aleperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 14:43:11 by aleperei          #+#    #+#             */
/*   Updated: 2023/05/09 13:23:59 by aleperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*str1;
	char	*str2;

	str1 = (char *)dest;
	str2 = (char *)src;
	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		str1[i] = str2[i];
		i++;
	}
	return (str1);
}

/*int main(void)
{
    char	str[]= "hello world";
	char	str2[15];
    char*	i;
	char* j;

	j = memcpy(str2, str, 20);
    i = ft_memcpy(str2, str, 20);
    printf("ft_memcpy = %s\n  memcpy = %s\n", i, j);
    return (0);
}*/
