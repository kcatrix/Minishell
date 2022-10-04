/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicoue <tnicoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:45:21 by kcatrix           #+#    #+#             */
/*   Updated: 2022/09/29 12:13:35 by tnicoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**ft_sup_dollar(char **spli, int y)
{
	char	**spli2;
	int		i;

	i = 0;
	while (spli[i])
		i++;
	spli2 = malloc(sizeof (char *) * i);
	i = 0;
	spli2 = ft_sup_dollar_boucle(spli, spli2, y, i);
	return (spli2);
}

char	**ft_sup_dollar_boucle(char **spli, char **spli2, int y, int i)
{
	while (spli[i])
	{
		if (i == y)
		{
			free(spli[y++]);
			while (spli[y])
			{
				spli2[y - 1] = ft_mallocex(spli[y], spli2[y - 1]);
				free(spli[y]);
				y++;
			}
			spli2[y - 1] = NULL;
			free(spli);
			return (spli2);
		}
		spli2[i] = ft_mallocex(spli[i], spli2[i]);
		free(spli[i]);
		i++;
	}
	return (spli2);
}

void	del_quote(char *cmd)
{
	size_t	i;
	char	quote;

	remove_backslash(cmd);
	i = 0;
	while (cmd[i])
	{
		if ((cmd[i] == '"' && cmd[i - 1] != '\\')
			|| (cmd[i] == '\'' && cmd[i - 1] != '\\'))
		{
			quote = cmd[i];
			rm_char(cmd, i++);
			while (cmd[i] != quote)
			{
				if (cmd[i] == '\\')
					i++;
				i++;
			}
			rm_char(cmd, i);
		}
		i++;
	}
}

void	rm_char(char *str, size_t index)
{
	while (str[index])
	{
		str[index] = str[index + 1];
		index++;
	}
}

void	skip(char *str, size_t *i)
{
	char	c;

	c = str[*i];
	(*i)++;
	while (str[*i] != c)
		(*i)++;
	(*i)++;
}
