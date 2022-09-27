/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exostiv <exostiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 14:18:41 by kevyn             #+#    #+#             */
/*   Updated: 2022/09/22 07:46:19 by exostiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	strlen_pipe(char *line)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (line[i])
	{
		if (line[i] == '|')
			y++;
		i++;
	}
	return (y);
}

void	ft_pipe(void)
{
	if (g_stock.nbpip > 0 && g_stock.nbpassage <= g_stock.nbpip)
	{
		if (g_stock.out != 1)
			dup2(g_stock.out, STDOUT_FILENO);
		else
			dup2(g_stock.pip[1], STDOUT_FILENO);
	}
}

void	cmd_cd_boucle(char **unparun)
{
	int	i;

	i = 0;
	while (unparun[i])
	{
		g_stock.old = i;
		if (strcmp(unparun[i], ".") == 0)
			cmd_cd_dot();
		else if (strcmp(unparun[i], "..") == 0)
			cmd_cd_dot_dot();
		else
			cmd_cd_absolute_redirect(unparun[i]);
		i++;
	}
}

void	free_protect(char *str)
{
	if (str)
		free(str);
}

void	ft_pipe2(int in)
{
	if (g_stock.nbpip == 0
		|| (g_stock.nbpip > 0 && g_stock.nbpassage == g_stock.nbpip + 1))
	{
		dup2(g_stock.out, STDOUT_FILENO);
		dup2(g_stock.in, STDIN_FILENO);
	}
	if (g_stock.pip[0] && g_stock.nbpassage != 1)
	{
		if (g_stock.in != 0)
			dup2(g_stock.in, STDIN_FILENO);
		else
			dup2(in, STDIN_FILENO);
	}
	if (g_stock.nbpip > 0 && g_stock.nbpassage <= g_stock.nbpip)
	{
		if (g_stock.out != 1)
			dup2(g_stock.out, STDOUT_FILENO);
		else
			dup2(g_stock.pip[1], STDOUT_FILENO);
	}
}
