/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicoue <tnicoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 11:21:16 by kevyn             #+#    #+#             */
/*   Updated: 2022/09/29 12:21:22 by tnicoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_verifenv(char *spli)
{
	char	*prespli;
	char	*preenv;
	int		i;

	prespli = ft_preline(spli);
	i = 0;
	while (g_stock.cpenv[i])
	{
		preenv = ft_preline(g_stock.cpenv[i]);
		if (ft_strcmp(prespli, preenv) == 0)
		{
			free(g_stock.cpenv[i]);
			g_stock.cpenv[i] = ft_mallocex(spli, g_stock.cpenv[i]);
			ft_verifenv2(preenv, prespli, spli);
			return (1);
		}
		free(preenv);
		i++;
	}
	free(prespli);
	return (0);
}

char	**ft_mallocunset(char **stockset)
{
	int		i;
	int		y;
	char	**cpcpenv;

	i = 0;
	y = 0;
	while (stockset[i])
		i++;
	cpcpenv = malloc(sizeof(char *) * (i + 1));
	i = 0;
	cpcpenv = ft_mallocunset_boucle(cpcpenv, i, y, stockset);
	return (cpcpenv);
}

char	**ft_mallocunset_boucle(char **cpcpenv, int i, int y, char **stockset)
{
	while (stockset[i])
	{
		cpcpenv[i] = malloc(sizeof(char) * ft_strlen(stockset[i]) + 1);
		while (stockset[i][y])
		{
			cpcpenv[i][y] = stockset[i][y];
			y++;
		}
		cpcpenv[i][y] = '\0';
		y = 0;
		free(stockset[i]);
		i++;
	}
	cpcpenv[i] = NULL;
	free(g_stock.cpexp);
	g_stock.cpexp = malloc(sizeof(char *) * (i + 2));
	return (cpcpenv);
}

char	**ft_mallocexportadd(void)
{
	int		i;
	int		y;
	char	**cpcpenv;

	i = 0;
	y = 0;
	while (g_stock.cpexp[i])
		i++;
	cpcpenv = malloc(sizeof(char *) * (i + 1));
	i = 0;
	cpcpenv = ft_mallocexportadd_boucle(cpcpenv, i, y);
	return (cpcpenv);
}

char	**ft_mallocexportadd_boucle(char **cpcpenv, int i, int y)
{
	while (g_stock.cpexp[i])
	{
		cpcpenv[i] = malloc(sizeof(char) * ft_strlen(g_stock.cpexp[i]) + 1);
		while (g_stock.cpexp[i][y])
		{
			cpcpenv[i][y] = g_stock.cpexp[i][y];
			y++;
		}
		cpcpenv[i][y] = '\0';
		y = 0;
		free_protect(g_stock.cpexp[i]);
		i++;
	}
	cpcpenv[i] = NULL;
	free(g_stock.cpexp);
	g_stock.cpexp = malloc(sizeof(char *) * (i + 2));
	return (cpcpenv);
}
