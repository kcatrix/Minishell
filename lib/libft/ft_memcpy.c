/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 11:41:23 by jbuan             #+#    #+#             */
/*   Updated: 2021/04/27 09:35:43 by jbuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"
#include <stdlib.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char			*d;
	unsigned int	i;

	if (!dst && !src)
		return (0);
	d = dst;
	i = 0;
	while (i < n)
	{
		*d = *(char *)src;
		src++;
		d++;
		i++;
	}
	return (dst);
}
