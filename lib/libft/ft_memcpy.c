/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcatrix <kcatrix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:02:18 by kcatrix           #+#    #+#             */
/*   Updated: 2022/10/04 11:03:01 by kcatrix          ###   ########.fr       */
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
