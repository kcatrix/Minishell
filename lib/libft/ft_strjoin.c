/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 16:11:41 by jbuan             #+#    #+#             */
/*   Updated: 2021/04/28 15:23:23 by jbuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

static int	strl(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*c;
	size_t	lena;
	size_t	lenb;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	lena = strl(s1);
	lenb = strl(s2);
	c = (char *)malloc(sizeof(char) * (lena + (lenb + 1)));
	if (!c)
		return (NULL);
	i = 0;
	j = 0 - lena;
	while (i < lena + (lenb + 1))
	{
		c[i] = s1[i];
		if (i >= lena)
			c[i] = s2[j];
		j++;
		i++;
	}
	c[i] = '\0';
	return (c);
}
