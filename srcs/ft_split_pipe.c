/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exostiv <exostiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 06:57:24 by exostiv           #+#    #+#             */
/*   Updated: 2022/09/22 07:02:33 by exostiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <stdio.h>
#include <stdlib.h>

static void	ft_subspli(const char *s)
{
	int	i;
	int	x;

	i = 0;
	x = -1;
	g_stock.chkpospip = malloc(sizeof(int) * 10);
	while (s[i])
	{	
		if (s[i] == '"' || s[i] == '\'')
		{
			while (s[i] == '"' || s[i] == '\'')
				i++;
			while (s[i] && s[i] != '"' && s[i] != '\'')
			{	
				if (s[i] == '|')
					g_stock.chkpospip[++x] = i;
				i++;
			}
			while (s[i] == '"' || s[i] == '\'')
				i++;
		}
		i++;
	}
	g_stock.chkpospip[++x] = '\0';
}

int	compte(const char *s, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	ft_subspli(s);
	while (s[i])
	{
		if (i == 0 && s[i] != c)
			j++;
		else if (s[i] != c && (i > 0 && s[i - 1] == c))
		{
			if (chkpospip((i - 1)) == 0)
				j++;
		}
		i++;
	}
	g_stock.nbpip = (j - 1);
	return (j);
}

int	futur(const char *s, char c)
{
	int		i;

	g_stock.chks = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] != c && s[i])
		{
			if (g_stock.chks > 0)
				g_stock.chks++;
			i++;
		}
		if (chkpospip((i)) != 0)
		{
			g_stock.chks++;
			i++;
		}
		else
		{
			return (i);
		}
	}
	return (i);
}

char	**ft_split_pipe(char const *s, char c)
{
	char	**a;
	int		i;

	if (!s)
		return (0);
	g_stock.j = compte((char *)s, c);
	a = malloc(sizeof(char *) * (g_stock.j + 1));
	if (!a)
		return (0);
	i = 0;
	ft_split_pipe2(s, c, a, i);
	return (a);
}
