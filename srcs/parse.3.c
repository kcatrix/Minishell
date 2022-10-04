/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcatrix <kcatrix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:17:31 by kcatrix           #+#    #+#             */
/*   Updated: 2022/10/04 14:38:49 by kcatrix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**cmd_dollar_int(char **spli, int i)
{
	free(spli[i]);
	spli[i] = ft_mallocex(ft_itoa(g_stock.end), spli[i]);
	return (spli);
}

void	fix_out_inr_redir(void)
{
	g_stock.end = 0;
	if (g_stock.out > 1)
		close(g_stock.out);
	if (g_stock.in > 0)
		close(g_stock.in);
	if (g_stock.out != 1)
		dup2(0, STDOUT_FILENO);
	if (g_stock.in != 0)
		dup2(1, STDIN_FILENO);
}

void	verif_arn(void)
{
	char	*line;

	g_stock.fork = 0;
	g_stock.ll = 0;
	if (g_stock.arn > 0)
	{
		while (g_stock.arn != 0)
		{
			line = readline("");
			printf("\n");
			free(line);
			g_stock.arn--;
		}
	}
}

char	*arn_creat(char *line, int i, int y)
{
	char	**spli;

	spli = NULL;
	if (ft_strncmp("cat", line, 3) == 0 && ft_arn(line + 3) == 0)
	{
		spli = ft_split(line, ' ');
		while ((spli[i][0] == '|' && spli[i][1] == '\0')
				|| ft_strcmp("cat", spli[i]) == 0)
		{
			if (ft_strcmp("cat", spli[i]) == 0)
				y++;
			i++;
		}
		if (ft_strcmp("ls", spli[i]) == 0
			&& spli[i + 1] == NULL && spli[i - 1][0] == '|')
		{
			line = "ls";
			g_stock.arn = y;
			free_spli(spli);
			return (line);
		}
	}
	if (spli)
		free_spli(spli);
	return (line);
}
