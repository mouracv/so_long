/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleperei <aleperei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 11:46:02 by aleperei          #+#    #+#             */
/*   Updated: 2023/10/25 14:38:25 by aleperei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*head;
	void	*new_content;

	new = NULL;
	if (lst == NULL)
		return (NULL);
	while (lst != NULL)
	{
		new_content = f(lst->content);
		head = ft_lstnew(new_content);
		if (!head)
		{
			del(new_content);
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, head);
		lst = lst->next;
	}
	return (new);
}
