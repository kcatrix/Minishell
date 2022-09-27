/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exostiv <exostiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:41:24 by kcatrix           #+#    #+#             */
/*   Updated: 2022/09/22 06:55:53 by exostiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_pwd(void)
{
	int	i;
	int	id;
	int	in;

	i = 0;
	pipe(g_stock.pip);
	in = g_stock.pip[0];
	id = fork();
	if (id == 0)
	{
		ft_pipe2(in);
		while (g_stock.cpenv[i])
		{
			if (ft_memcmp(g_stock.cpenv[i], "PWD=", 4) == 0)
			{
				printf("%s\n", g_stock.cpenv[i] + 4);
			}
			i++;
		}
		exit (0);
	}
	else
		fixwait(id);
}

int	ft_path_exist(void)
{
	int		i;
	int		x;
	char	**path;

	x = -1;
	i = 0;
	path = NULL;
	if (ft_path_exist_boucle(path, i, x) == 0)
		return (0);
	if (path)
		free_spli(path);
	return (1);
}

int	ft_path_exist_boucle(char **path, int i, int x)
{
	char	*tmp;

	tmp = NULL;
	while (g_stock.cpenv[i])
	{
		if (ft_path_exist_boucle_end(path, i, x, tmp) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_path_exist_boucle_end(char **path, int i, int x, char *tmp)
{
	if (ft_memcmp(g_stock.cpenv[i], "PATH=", 5) == 0)
	{
		path = ft_split(g_stock.cpenv[i] + 5, ':');
		i = 0;
		while (path[i])
		{
			tmp = ft_mallocex(path[i], tmp);
			free(path[i]);
			path[i] = ft_strjoin(tmp, "/env");
			x = access(path[i], R_OK);
			if (x == 0)
			{
				free(tmp);
				free_spli(path);
				return (0);
			}
			free(tmp);
			i++;
		}
		free_spli(path);
	}
	return (1);
}

int	last_check(int i, char **path, char *line, char **spli)
{
	if (i == -1 || !path)
	{
		printf("%s: Command not found\n", line);
		if (path)
			free_spli(path);
		free_spli(spli);
		g_stock.end = 127;
		return (-1);
	}
	return (0);
}
