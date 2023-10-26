/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleperei <aleperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:07:02 by aleperei          #+#    #+#             */
/*   Updated: 2023/10/18 13:40:37 by aleperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	len;
	size_t	i;
	size_t	j;

	len = (ft_strlen(s1) + ft_strlen(s2)) + 1;
	new = (char *)malloc(sizeof(char) * len);
	i = 0;
	j = 0;
	if (!new)
		return (NULL);
	while (s1[j] != '\0' && i < len)
		new[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0' && i < len)
		new[i++] = s2[j++];
	new[i] = '\0';
	return (new);
}

/*int	main(void)
{
    char	dest[] = "Alexsandro ";
    char	src[] = "Pereira Moreira";
    char    *p;

    p = ft_strjoin(dest, src);
    printf("P %s\n", p);
    free(p);
    return (0);
}*/
