/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcatrix <kcatrix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:04:53 by kcatrix           #+#    #+#             */
/*   Updated: 2022/10/04 11:04:55 by kcatrix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"
#include <stdlib.h>

char	*ft_strchr(const char *s, int c)
{
	char	*st;

	st = (char *)s;
	while (*st != (char)c)
	{	
		if (!*st)
			return (0);
		st++;
	}
	return (st);
}
