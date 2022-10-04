/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcatrix <kcatrix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:04:47 by kcatrix           #+#    #+#             */
/*   Updated: 2022/10/04 11:04:49 by kcatrix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static int	compte(const char *s, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (i == 0 && s[i] != c)
			j++;
		else if (s[i] != c && (i > 0 && s[i - 1] == c))
			j++;
		i++;
	}
	return (j);
}

static int	futur(const char *s, char c)
{
	int		i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**a;
	int		i;
	int		j;
	int		k;

	if (!s)
		return (0);
	j = compte((char *)s, c);
	a = malloc(sizeof(char *) * (j + 1));
	if (!a)
		return (0);
	i = 0;
	while (i < j)
	{
		k = 0;
		while (*s != '\0' && *s == c)
			s++;
		k = futur((char *)s, c);
		a[i] = ft_substr(s, 0, k);
		while (*s != '\0' && *s != c)
			s++;
		i++;
	}
	a[i] = NULL;
	return (a);
}
