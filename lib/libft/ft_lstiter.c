/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 14:17:56 by jbuan             #+#    #+#             */
/*   Updated: 2021/05/03 18:46:33 by jbuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstiter(t_list *lst, void (*f) (void *))
{
	t_list	*last;

	last = lst;
	while (lst)
	{
		last = lst->next;
		f (lst->content);
		lst = last;
	}
	return ;
}
