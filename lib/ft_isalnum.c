/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleperei <aleperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 10:05:31 by aleperei          #+#    #+#             */
/*   Updated: 2023/04/13 16:18:00 by aleperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int nb)
{
	if ((nb >= 65 && nb <= 90) || (nb >= 97 && nb <= 122))
		return (1);
	else
		if (nb >= 48 && nb <= 57)
			return (1);
	else
		return (0);
}

/*#include <stdio.h>

int	main()
{
	printf("%d", ft_isalnum('a'));
	return(0);
}*/
