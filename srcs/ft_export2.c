/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicoue <tnicoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 11:03:32 by kevyn             #+#    #+#             */
/*   Updated: 2022/09/29 12:21:18 by tnicoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_export(char **spli)
{
	int	in;
	int	id;
	int	i;

	i = 0;
	pipe(g_stock.pip);
	in = g_stock.pip[0];
	id = fork();
	if (id == 0 && !spli[1])
	{
		ft_pipe2(in);
		if (!spli[1])
			ft_export_noarg();
		exit(0);
	}
	if (id == 0)
		exit(0);
	else
		fixwaitexp(id, spli, i);
}

void	ft_exptoenv(char *spli)
{
	char	**cpcpenv;
	int		i;

	i = 0;
	cpcpenv = ft_exptoenv2();
	while (cpcpenv[i])
	{
		g_stock.cpenv[i] = ft_mallocex(cpcpenv[i], g_stock.cpenv[i]);
		if (cpcpenv[i])
			free(cpcpenv[i]);
		i++;
	}
	g_stock.cpenv[i] = ft_mallocex(spli, g_stock.cpenv[i]);
	g_stock.cpenv[i + 1] = NULL;
	if (cpcpenv)
		free(cpcpenv);
	return ;
}

int	ft_verifspli(char *spli)
{
	int	i;
	int	y;

	y = 0;
	i = 0;
	while (spli[i])
	{
		if (spli[i] == '=')
		{
			y = 1;
			while (spli[++i])
			{
				if (spli[i] != 22 && spli[i] != '\0')
					y = 1;
			}
		}
		i++;
	}
	return (y);
}

int	ft_verifdoublon(char *spli)
{
	int		i;
	char	*prespli;
	char	*preexp;

	i = 0;
	while (g_stock.cpexp[i])
	{
		prespli = ft_preline(spli);
		preexp = ft_preline(g_stock.cpexp[i]);
		if (strcmp(prespli, preexp) == 0)
		{
			if (ft_verifspli(spli) != 0)
				g_stock.cpexp[i] = ft_mallocex(spli, g_stock.cpexp[i]);
			free(prespli);
			free(preexp);
			return (0);
		}
		free(prespli);
		free(preexp);
		i++;
	}
	return (1);
}

char	*ft_mallocex(char *str, char *str2)
{
	int	i;

	i = 0;
	if (!str || !ft_strlen(str))
		return (NULL);
	str2 = malloc(sizeof(char) * (ft_strlen(str) + 1));
	while (str[i])
	{
		str2[i] = str[i];
		i++;
	}
	str2[i] = '\0';
	return (str2);
}
