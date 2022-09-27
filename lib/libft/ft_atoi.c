/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 18:20:41 by jbuan             #+#    #+#             */
/*   Updated: 2021/05/02 15:17:16 by jbuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int	ft_atoi(const char *str)
{
	int					i;
	int					j;
	unsigned long int	k;

	i = 0;
	j = 1;
	k = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			j = j * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		k = k * 10 + str[i++] - '0';
	if (k > 4294967295 && j == 1)
		return (-1);
	else if (k > 4294967295 && j == -1)
		return (0);
	return (j * k);
}
