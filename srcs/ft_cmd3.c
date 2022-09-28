/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicoue <tnicoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 11:48:32 by kevyn             #+#    #+#             */
/*   Updated: 2022/09/28 15:31:02 by tnicoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_redirect_2(char **spli)
{
	if (ft_strcmp(spli[0], "PWD") == 0 || ft_strcmp(spli[0], "pwd") == 0)
	{
		ft_pwd();
		return (0);
	}
	else if ((ft_strcmp(spli[0], "env") == 0
			|| ft_strcmp(spli[0], "ENV") == 0) && ft_path_exist() == 0)
	{
		ft_env();
		return (0);
	}
	else if (ft_strcmp(spli[0], "export") == 0)
	{
		ft_export(spli);
		return (0);
	}
	else if (ft_strcmp(spli[0], "exit") == 0)
	{
		f_exit(spli);
		return (0);
	}
	return (1);
}

char	**cmd_unset2(char **spli, char **tmp, char **env, int i)
{
	while (tmp[i])
	{
		if (ft_memcmp(env[i], spli[1], ft_strlen(spli[1])) == 0
			&& ((env[i][ft_strlen(spli[1])] == '=')
			|| (env[i][ft_strlen(spli[1])] == '\0')))
		{
			while (tmp[i + 1])
			{
				free(env[i]);
				env[i] = ft_mallocex(tmp[i + 1], env[i]);
				i++;
			}
			free(env[i]);
			env[i] = NULL;
			return (env);
		}
		free(env[i]);
		env[i] = ft_mallocex(tmp[i], env[i]);
		i++;
	}
	return (env);
}

void	ft_exec(char **spli, char **path, char **env, int i)
{
	int	id;
	int	in;

	g_stock.i = i;
	in = g_stock.pip[0];
	pipe(g_stock.pip);
	id = fork();
	if (id == 0)
	{
		child_process(path, spli, env, in);
	}
	else
	{
		g_stock.fork = id;
		waitpid(id, 0, 0);
		close(g_stock.pip[1]);
		if (g_stock.out > 1)
			close(g_stock.out);
		if (g_stock.in > 0)
			close(g_stock.in);
		free_spli(path);
		free_spli(spli);
	}
}

void	init_var_cmd(char *line)
{
	int	i;
	int	y;

	y = 0;
	i = 0;
	g_stock.chkcrash = 0;
	g_stock.in = 0;
	g_stock.out = 1;
	line = arn_creat(line, i, y);
	g_stock.chks = 0;
	g_stock.line2 = ft_split_pipe(line, '|');
	if (g_stock.chkpospip)
		free(g_stock.chkpospip);
}

int	ft_parse_cmd(char **spli, char **path)
{
	if (g_stock.chkcrash < 0)
	{
		g_stock.out = 1;
		g_stock.in = 0;
		if (path)
			free_spli(path);
		return (0);
	}
	if (ft_redirect(spli) == 0)
	{
		if (path)
			free_spli(path);
		return (0);
	}
	if (path == NULL)
	{
		printf("%s: No such file or directory\n", spli[0]);
		return (0);
	}
	return (1);
}
