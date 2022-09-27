/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevyn <kevyn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 11:26:09 by kevyn             #+#    #+#             */
/*   Updated: 2022/09/27 12:24:36 by kevyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**parse(char **spli)
{
	int	i;

	i = 0;
	if (spli[0][0] == '/')
		spli[0] = ft_replace_absolute(spli);
	while (ft_checkdollar(spli) == 1)
	{
		while (spli[i])
		{
			if (spli[i][0] == '$' && spli[i][1] == '?' && spli[i][2] == '\0')
				spli = cmd_dollar_int(spli, i);
			else if ((spli[i][0] == '$') ||
					(spli[i][0] == '"' && spli[i][1] == '$'))
				spli = cmd_dollar(spli, i);
			else if (spli[i] != NULL)
				i++;
		}
		i = 0;
	}
	i = 0;
	spli = ft_checkdollar_inside(spli);
	return (spli);
}

int	ft_checkdollar(char **spli)
{
	int	i;

	i = 0;
	while (spli[i])
	{
		if ((spli[i][0] == '$') ||
			(spli[i][0] == '"' && spli[i][1] == '$'))
			return (1);
		i++;
	}
	return (0);
}

int	verif_space(char *line)
{
	size_t	i;

	i = 0;
	while ((line[i] == 32) || (line[i] >= 9 && line[i] <= 13))
		i++;
	if (i == ft_strlen(line))
		return (0);
	return (1);
}

char	**cmd_dollar(char **spli, int y)
{
	int	i;

	i = 0;
	del_quote(spli[y]);
	while (g_stock.cpenv[i])
	{
		if (ft_memcmp(g_stock.cpenv[i],
				spli[y] + 1, ft_strlen(spli[y]) - 1) == 0
			&& g_stock.cpenv[i][ft_strlen(spli[y]) - 1] == '=')
		{
			free(spli[y]);
			spli[y] = ft_mallocex(g_stock.cpenv[i]
					+ ft_strlen(spli[y]), spli[y]);
			return (spli);
		}
		i++;
	}
	spli = ft_sup_dollar(spli, y);
	return (spli);
}

void	remove_backslash(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '"')
			skip(str, &i);
		if (str[i] == '\'')
			skip(str, &i);
		if (str[i] == '\\')
			rm_char(str, i--);
		i++;
	}
}
