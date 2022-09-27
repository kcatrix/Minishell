/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevyn <kevyn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:46:53 by kevyn             #+#    #+#             */
/*   Updated: 2022/09/16 13:52:10 by kevyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	verif_ex_exist(void)
{
	if (!g_stock.cpexp[0])
	{
		g_stock.cpexp[0] = ft_mallocex(g_stock.cpenv[0], g_stock.cpexp[0]);
		return (1);
	}
	return (0);
}

char	*ft_first_tri(char *str, int i)
{
	free(g_stock.save);
	free(g_stock.save2);
	g_stock.save = ft_mallocex(g_stock.cpexp[i], g_stock.save);
	free(g_stock.cpexp[i]);
	g_stock.cpexp[i] = ft_mallocex(str, g_stock.cpexp[i]);
	i++;
	while (g_stock.cpexp[i])
	{
		g_stock.save2 = ft_mallocex(g_stock.cpexp[i], g_stock.save2);
		free(g_stock.cpexp[i]);
		g_stock.cpexp[i] = ft_mallocex(g_stock.save, g_stock.cpexp[i]);
		free(g_stock.save);
		g_stock.save = ft_mallocex(g_stock.save2, g_stock.save);
		free(g_stock.save2);
		i++;
	}
	free(g_stock.cpexp[i]);
	g_stock.cpexp[i] = ft_mallocex(g_stock.save, g_stock.cpexp[i]);
	free(g_stock.save);
	g_stock.cpexp[i + 1] = NULL;
	return (str);
}

char	**ft_exptoenv2_boucle(char **cpcpenv, int i, int y)
{
	while (g_stock.cpenv[i])
	{
		cpcpenv[i] = malloc(sizeof(char) * ft_strlen(g_stock.cpenv[i]) + 1);
		while (g_stock.cpenv[i][y])
		{
			cpcpenv[i][y] = g_stock.cpenv[i][y];
			y++;
		}
		cpcpenv[i][y] = '\0';
		y = 0;
		free(g_stock.cpenv[i]);
		i++;
	}
	cpcpenv[i] = NULL;
	free(g_stock.cpenv);
	g_stock.cpenv = malloc(sizeof(char *) * (i + 2));
	return (cpcpenv);
}

void	verif_export_exist(int i)
{
	if (!g_stock.cpexp)
	{
		while (g_stock.cpenv[i])
			i++;
		g_stock.cpexp = malloc(sizeof(char *) * (i + 1));
		i = 0;
		while (g_stock.cpenv[i])
		{
			ft_triexport(g_stock.cpenv[i]);
			i++;
		}
		signal(SIGINT, interrupt_signal);
		signal(SIGQUIT, quit_signal);
		signal(11, quit_signal);
	}
}
