/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exostiv <exostiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 08:09:03 by exostiv           #+#    #+#             */
/*   Updated: 2022/09/23 02:58:05 by exostiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_exportadd_boucle2(char **cpcpexp, char*prespli, char *preexp, int i)
{
	int	y;

	y = i;
	i++;
	while (cpcpexp[y])
	{
		g_stock.cpexp[i] = ft_mallocex(cpcpexp[y], g_stock.cpexp[i]);
		free_protect(cpcpexp[y]);
		y++;
		i++;
	}
	g_stock.cpexp[i] = NULL;
	free(prespli);
	free(preexp);
	free(cpcpexp);
	return ;
}

void	ft_verifenv2(char *preenv, char *prespli, char *spli)
{
	char	*preexp;
	int		i;

	i = 0;
	while (g_stock.cpexp[i])
	{
		preexp = ft_preline(g_stock.cpexp[i]);
		if (ft_strcmp(prespli, preexp) == 0 && ft_verifspli(spli) != 0)
		{
			free(g_stock.cpexp[i]);
			g_stock.cpexp[i] = ft_mallocex(spli, g_stock.cpexp[i]);
		}
		free(preexp);
		i++;
	}
	free(preenv);
	free(prespli);
	return ;
}

char	**ft_exportaff2(char **newline, char *line, int i)
{
	i++;
	newline[0][i] = '"';
	i++;
	while (line[i])
	{
		newline[0][i] = line[i - 1];
		i++;
	}
	if (line[i] || line[i - 1])
	{
		newline[0][i] = line[i - 1];
		newline[0][++i] = '"';
		newline[0][++i] = '\0';
	}
	else
	{
		newline[0][i++] = '"';
		newline[0][i] = '\0';
	}
	return (newline);
}

int	ft_cmd_suite(char **spli, char **path, char **env)
{
	int	i;

	i = 0;
	ft_verif_chevron(spli);
	if (ft_parse_cmd(spli, path) == 0)
	{
		if (spli)
			free_spli(spli);
		return (0);
	}
	i = verif_exist(path, spli[0]);
	if (last_check(i, path, spli[0], spli) == -1)
		return (-1);
	ft_exec(spli, path, env, i);
	g_stock.end = 0;
	return (0);
}
