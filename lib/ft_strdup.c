/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleperei <aleperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 09:09:56 by aleperei          #+#    #+#             */
/*   Updated: 2023/05/09 17:00:56 by aleperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		i;
	int		len;

	len = ft_strlen(s) + 1;
	dup = (char *) malloc(sizeof(char) * len);
	if (!dup)
		return (NULL);
	i = -1;
	ft_memcpy(dup, s, len);
	return (dup);
}

/*int main()
{
    char    array[]= "alexsandro Moreira";
    char    *p;

    printf("the string is: %s", array);
    p = ft_strdup(array);
    printf("\n");
    printf("the duplicated string is:");
    printf("%s", p);
    printf("\n");
    printf("%p", p);
    free (p);
    return (0);
}*/
