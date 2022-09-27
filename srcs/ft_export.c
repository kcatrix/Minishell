/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exostiv <exostiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:15:16 by kcatrix           #+#    #+#             */
/*   Updated: 2022/09/23 02:07:09 by exostiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_triexport(char *str)
{
	int		i;

	g_stock.save = NULL;
	g_stock.save2 = NULL;
	i = 0;
	while (g_stock.cpexp[i])
	{
		g_stock.save = ft_preline(str);
		g_stock.save2 = ft_preline(g_stock.cpexp[i]);
		if (ft_strcmp(g_stock.save, g_stock.save2) < 0)
		{
			str = ft_first_tri(str, i);
			return ;
		}
		free(g_stock.save);
		free(g_stock.save2);
		i++;
	}
	if (verif_ex_exist() == 1)
		return ;
	free(g_stock.cpexp[i]);
	g_stock.cpexp[i] = ft_mallocex(str, g_stock.cpexp[i]);
	g_stock.cpexp[i + 1] = NULL;
	return ;
}

char	**ft_exptoenv2(void)
{
	int		i;
	int		y;
	char	**cpcpenv;

	i = 0;
	y = 0;
	while (g_stock.cpenv[i])
		i++;
	cpcpenv = malloc(sizeof(char *) * (i + 1));
	i = 0;
	cpcpenv = ft_exptoenv2_boucle(cpcpenv, i, y);
	return (cpcpenv);
}

void	ft_exportadd(int i, char *spli)
{
	char	**cpcpexp;
	int		y;
	int		z;

	y = 0;
	z = 0;
	if (ft_verifdoublon(spli) == 0)
		return ;
	cpcpexp = ft_mallocexportadd();
	ft_exptoenv(spli);
	ft_exportadd_boucle(cpcpexp, i, spli);
}

void	ft_exportadd_boucle(char **cpcpexp, int i, char *spli)
{
	char	*prespli;
	char	*preexp;

	while (cpcpexp[i])
	{
		prespli = ft_preline(spli);
		preexp = ft_preline(cpcpexp[i]);
		if (ft_strcmp(prespli, preexp) < 0)
		{
			g_stock.cpexp[i] = ft_mallocex(spli, g_stock.cpexp[i]);
			ft_exportadd_boucle2(cpcpexp, prespli, preexp, i);
			return ;
		}
		free(prespli);
		free(preexp);
		g_stock.cpexp[i] = ft_mallocex(cpcpexp[i], g_stock.cpexp[i]);
		free(cpcpexp[i]);
		i++;
	}
	cpcpexp = ft_exportadd_boucle_end(cpcpexp, i, spli);
}

char	**ft_exportadd_boucle_end(char **cpcpexp, int i, char *spli)
{
	g_stock.cpexp[i] = ft_mallocex(spli, g_stock.cpexp[i]);
	g_stock.cpexp[i + 1] = NULL;
	free(cpcpexp[i]);
	free(cpcpexp);
	return (cpcpexp);
}
