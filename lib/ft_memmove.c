/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleperei <aleperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:38:27 by aleperei          #+#    #+#             */
/*   Updated: 2023/10/25 14:39:20 by aleperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*str1;
	char	*str2;

	str1 = (char *)dest;
	str2 = (char *)src;
	if (str1 > str2)
	{
		while (n > 0)
		{
			n--;
			str1[n] = str2[n];
		}
	}
	else
	{
		ft_memcpy(str1, str2, n);
	}
	return (dest);
}
