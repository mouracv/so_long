/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleperei <aleperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 10:20:03 by aleperei          #+#    #+#             */
/*   Updated: 2023/10/25 14:39:42 by aleperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*dup;
	size_t	total;

	total = n * size;
	dup = malloc(total);
	if (!dup)
		return (NULL);
	ft_memset(dup, 0, total);
	return (dup);
}
