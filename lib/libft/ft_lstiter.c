/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcatrix <kcatrix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:01:10 by kcatrix           #+#    #+#             */
/*   Updated: 2022/10/04 11:03:15 by kcatrix          ###   ########.fr       */
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
