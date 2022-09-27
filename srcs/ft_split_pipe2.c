/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_pipe2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exostiv <exostiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 07:47:33 by exostiv           #+#    #+#             */
/*   Updated: 2022/09/22 08:03:57 by exostiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	chkpospip(int i)
{
	int	y;

	y = 0;
	while (g_stock.chkpospip[y])
	{
		if (g_stock.chkpospip[y] == i)
			return (1);
		y++;
	}
	return (0);
}

void	ft_augmentpospip(void)
{
	int	i;

	i = 0;
	while (g_stock.chkpospip[i])
	{
		g_stock.chkpospip[i] = g_stock.chkpospip[i] - 1;
		i++;
	}
}

char	**ft_split_pipe2(char const *s, char c, char **a, int i)
{
	while (i < g_stock.j)
	{
		g_stock.k = 0;
		while (*s != '\0' && *s == c)
		{
			ft_augmentpospip();
			s++;
		}
		while (g_stock.chks-- > 0)
		{
			ft_augmentpospip();
			s++;
		}
		g_stock.k = futur((char *)s, c);
		a[i] = ft_substr(s, 0, g_stock.k);
		while (*s != '\0' && *s != c)
		{
			ft_augmentpospip();
			s++;
		}
		i++;
	}
	a[i] = NULL;
	return (a);
}
