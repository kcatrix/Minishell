/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 14:42:35 by jbuan             #+#    #+#             */
/*   Updated: 2021/05/03 18:46:45 by jbuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f) (void *), void (*del) (void *))
{
	t_list	*new1;
	t_list	*new2;

	new1 = NULL;
	if (lst)
	{
		while (lst)
		{
			new2 = ft_lstnew(f(lst->content));
			if (!new2)
			{
				ft_lstclear(&new1, del);
				return (NULL);
			}
			ft_lstadd_back(&new1, new2);
			lst = lst->next;
		}
		return (new1);
	}
	else
		return (NULL);
}
