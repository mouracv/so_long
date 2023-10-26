/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleperei <aleperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:06:40 by aleperei          #+#    #+#             */
/*   Updated: 2023/10/06 12:44:21 by aleperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	k;

	if (!s)
		return (NULL);
	if (len == 0 || ft_strlen(s) < (int)start)
		return (ft_strdup(""));
	if (ft_strlen(s) - (int)start >= (int)len)
		sub = (char *)malloc(sizeof(char) * (len + 1));
	else
		sub = (char *)malloc(sizeof(char) * (ft_strlen(s) - (int)start + 1));
	if (!sub)
		return (NULL);
	k = 0;
	while (s[start] != '\0' && k < len)
		sub[k++] = s[start++];
	sub[k] = '\0';
	return (sub);
}

/*int main()
{
    char    str[]= "Alexsandro Pereira Moreira";
    char    *p;
    int s = 11;
    int l = 18;

    p = ft_substr(str, s, l);
    printf("P = %s\n", p);
    free(p);
    return  (0);
}*/
