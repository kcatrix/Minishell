/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 17:30:32 by jbuan             #+#    #+#             */
/*   Updated: 2021/04/20 16:42:50 by jbuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"
#include <stdlib.h>

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*st;

	i = 0;
	st = (char *)s;
	i = ft_strlen(st);
	while (i >= 0)
	{
		if (st[i] == (char)c)
			return (st + i);
		i--;
	}
	return (0);
}
