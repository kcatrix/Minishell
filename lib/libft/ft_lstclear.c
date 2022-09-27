/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 09:38:16 by jbuan             #+#    #+#             */
/*   Updated: 2021/05/03 18:46:16 by jbuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del) (void *))
{
	t_list	*last;

	last = *lst;
	while (last)
	{
		last = (*lst)->next;
		del ((*lst)->content);
		free (*lst);
		(*lst) = last;
	}
	return ;
}
