/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcatrix <kcatrix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:38:26 by kcatrix           #+#    #+#             */
/*   Updated: 2022/10/04 14:45:01 by kcatrix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	verif_pipe(char *line)
{
	int	i;

	i = 0;
	while ((line[i] == 32) || (line[i] >= 9 && line[i] <= 13))
		i++;
	if (line[i] == '|')
		return (0);
	return (1);
}

char	*verif_pipe_end(char *line)
{
	int		i;
	char	*tmp;

	tmp = NULL;
	i = 0;
	if (verif_pipe(line) == 0)
	{
		printf("bash: syntax error near unexpected token `|'\n");
		return (NULL);
	}
	while (line[i])
		i++;
	while ((line[i] == 32) || (line[i] >= 9 && line[i] <= 13)
		|| (line[i] == '\0'))
		i--;
	line = verif_pipe_end2(line, i, tmp);
	return (line);
}

char	*verif_pipe_end2(char *line, int i, char *tmp)
{
	char	*tmp2;

	tmp2 = NULL;
	if ((line[i] == '|') && (g_stock.ll == 0))
	{
		g_stock.ll = 1;
		while (1)
		{
			tmp = readline(">");
			if (verif_tmp(tmp) == 0)
			{
				tmp2 = ft_mallocex(line, tmp2);
				free(line);
				line = ft_strjoin(tmp2, tmp);
				free(tmp2);
				free(tmp);
				return (line);
			}
		}
	}
	return (line);
}

int	verif_tmp(char *tmp)
{
	int		i;
	size_t	j;

	j = 0;
	i = 0;
	while (tmp[i])
	{
		if ((tmp[i] == '\0' || tmp[i] == 32 || (tmp[i] >= 9 && tmp[i] <= 13)))
			j++;
		i++;
	}
	if (j == ft_strlen(tmp))
		return (1);
	return (0);
}

void	ft_main_end(char *line)
{
	free_spli(g_stock.line2);
	free(line);
	g_stock.nbpassage = 0;
	g_stock.nbpip = 0;
}
