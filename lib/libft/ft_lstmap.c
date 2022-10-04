/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcatrix <kcatrix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:01:25 by kcatrix           #+#    #+#             */
/*   Updated: 2022/10/04 11:03:11 by kcatrix          ###   ########.fr       */
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
