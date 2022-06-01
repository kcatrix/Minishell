/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 08:44:18 by jbuan             #+#    #+#             */
/*   Updated: 2022/06/01 16:19:55 by kevyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"
#include <stdlib.h>

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*st1;
	unsigned char	*st2;
	size_t			i;

	i = 0;
	st1 = (unsigned char *)s1;
	st2 = (unsigned char *)s2;
	while (st1[i] || st2[i])
	{
		if (st1[i] != st2[i])
			return (st1[i] - st2[i]);
		i++;
	}
	return (0);
}
