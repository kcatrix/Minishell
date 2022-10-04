/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcatrix <kcatrix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:06:31 by kcatrix           #+#    #+#             */
/*   Updated: 2022/10/04 11:06:32 by kcatrix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

static int	egal(const char *set, char c)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*a;
	size_t	i;
	size_t	j;
	size_t	k;

	if (!s1 || !set)
		return (0);
	i = 0;
	while (s1[i] && egal(set, s1[i]))
		i++;
	j = ft_strlen(s1);
	while (j > i && egal(set, s1[j - 1]))
		j--;
	a = (char *)malloc(sizeof(*s1) * (j - i + 1));
	if (!a)
		return (0);
	k = 0;
	while (i < j)
		a[k++] = s1[i++];
	a[k] = 0;
	return (a);
}
