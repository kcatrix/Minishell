/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 13:21:52 by jbuan             #+#    #+#             */
/*   Updated: 2021/04/01 11:03:33 by jbuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"
#include <stdlib.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char	*s;
	char	*d;
	size_t	i;

	d = dst;
	s = (char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		if (s[i] == (char)c)
		{
			return (d + i + 1);
		}
		i++;
	}
	return (NULL);
}
