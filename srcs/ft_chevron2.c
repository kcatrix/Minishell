/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chevron2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exostiv <exostiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 15:03:11 by kevyn             #+#    #+#             */
/*   Updated: 2022/09/12 06:21:59 by exostiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	heredoc(char **spli, int i)
{
	char	*line;
	int		pipes[2];

	pipe(pipes);
	while (1)
	{
		line = readline(">");
		if (ft_strcmp(line, spli[i + 1]) == 0)
		{
			del_i(spli, i);
			free(line);
			close(pipes[1]);
			return (pipes[0]);
		}
		write(pipes[1], line, ft_strlen(line));
		write(pipes[1], "\n", 1);
		free(line);
	}
}

int	ft_chevron_redirect2(char **spli, int i)
{
	int	y;

	y = -1;
	if (spli[i][0] == '<' && spli[i][1] == '\0')
	{	
		if (ft_prepchevgauche(spli, i) < 0)
			return (0);
	}
	else
		g_stock.in = heredoc(spli, i);
	y = ft_chevron_redirect2_boucle(spli, i, y);
	if (y == -1)
		return (-1);
	if (y != -1)
		g_stock.out = y;
	return (y);
}

int	ft_chevron_redirect2_boucle(char **spli, int i, int y)
{
	while (ft_chevron_exist(spli) != 0)
	{
		while (spli[i] && spli[i][0] == '>' && spli[i][1] == '\0')
		{	
			close(y);
			y = ft_chevron_droite(spli, i);
		}
		while (spli[i] && spli[i][0] == '<' && spli[i][1] == '\0')
		{
			if (ft_chevron_gauche(spli, i, y) == -1)
				return (-1);
		}
		while (spli[i] && spli[i][0] == '>'
			&& spli[i][1] == '>' && spli[i][2] == '\0')
		{
			close (y);
			y = double_chevron_droite(spli, i);
		}
		while (spli[i] && spli[i][0] == '<'
			&& spli[i][1] == '<' && spli[i][2] == '\0')
			heredoc(spli, i);
	}
	return (y);
}

int	ft_prepchevgauche(char **spli, int i)
{
	int	file;

	file = open(spli[i + 1], O_RDONLY, 0777);
	if (file < 0)
	{
		g_stock.chkcrash = -1;
		printf("%s: No such file or directory\n", spli[i + 1]);
		return (file);
	}
	g_stock.in = file;
	del_i(spli, i);
	return (file);
}
