/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcatrix <kcatrix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:00:52 by kcatrix           #+#    #+#             */
/*   Updated: 2022/10/04 11:03:18 by kcatrix          ###   ########.fr       */
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
