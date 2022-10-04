/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcatrix <kcatrix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:17:31 by kcatrix           #+#    #+#             */
/*   Updated: 2022/10/04 14:30:08 by kcatrix          ###   ########.fr       */
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

int verif_pipe(char *line)
{
	int	i;

	i = 0;
	while((line[i] == 32) || (line[i] >= 9 && line[i] <= 13))
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
	while(line[i])
		i++;
	while((line[i] == 32) || (line[i] >= 9 && line[i] <= 13) 
		|| (line[i] == '\0'))
		i--;
	line = verif_pipe_end2(line, i, tmp);
	return (line);
}

char	*verif_pipe_end2(char *line, int i, char *tmp)
{
	char *tmp2;
	
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

int 	verif_tmp(char *tmp)
{
	int		i;
	size_t j;

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