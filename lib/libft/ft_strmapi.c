/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcatrix <kcatrix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:06:00 by kcatrix           #+#    #+#             */
/*   Updated: 2022/10/04 11:06:02 by kcatrix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*a;
	int		i;
	int		j;			

	if (!s || !f)
		return (0);
	i = ft_strlen(s);
	a = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!a)
		return (NULL);
	j = 0;
	while (s[j])
	{
		a[j] = f(j, s[j]);
		j++;
	}
	a[j] = '\0';
	return (a);
}
