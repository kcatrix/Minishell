/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:38:47 by tnicoue           #+#    #+#             */
/*   Updated: 2022/05/24 15:22:02 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
/*
EXPORT ; La commande export marque une variable d'environnement à exporter 
avec tout processus enfant nouvellement créé et permet ainsi à un processus 
enfant d'hériter de toutes les variables marquées.
*/
char	*ft_suppr(char *tmp, char *spli)
{
	int	i;

	i = 0;
	while (tmp[i] == spli[i])
	{
		i++;
	}
	tmp[i] = '\0';
	printf("tmp == %s\n", tmp);
	return (tmp);
}

int	cmd_unset(char **spli, char **env)
{
	int		i;
	char	**tmp;

	tmp = ft_cp_env(env);
	i = 0;
	while (tmp[i])
	{
		printf("oeoeoe mari\n");
		if (ft_memcmp(env[i], spli[1], ft_strlen(spli[1])) == 0)
		{
			tmp[i] = ft_suppr(tmp[i], spli[1]);
			printf("tmp[i] = %s, env[i] = %s \n", tmp[i], env[i]);
		}
		i++;
	}
	return (0);
}

int	ft_redirect(char **spli, char **env)
{
	if (ft_strncmp(spli[0], "unset", 5) == 0)
	{
		cmd_unset(spli, env);
		return (0);
	}
	return (1);
}


int	ft_cmd(char *line, char **env)
{
	char	**path;
	char	**spli;
	int		i;

	i = 0;
	if (line[0] == 0)
		return (0);
	path = path_fct(env);
	spli = ft_split(line, ' ');
	if (ft_redirect(spli, env) == 0)
		return (0);
	i = verif_exist(path, spli[0]);
	if (i == -1)
	{
		printf("%s: Command not found\n", line);
		return (-1);
	}
	//spli = verif_option(spli);
	execve(path[i], spli, env);
	return (0);
}

char	**path_fct(char **env)
{
	int		i;
	int		y;
	char	*str;
	char	**spli;

	i = 0;
	y = 0;
	while (env[i])
	{
		if (ft_memcmp(env[i], "PATH", 4) == 0)
			break ;
		i++;
	}
	while (env[i][y] != '=')
		y++;
	str = env[i] + y + 1;
	spli = ft_split(str, ':');
	return (path_finish(spli));
}

char	**path_finish(char **env)
{
	int		i;
	char	*tmp;

	i = -1;
	while (env[++i])
	{
		tmp = ft_strjoin(env[i], "/");
		free(env[i]);
		env[i] = ft_strdup(tmp);
		free(tmp);
	}
	return (env);
}

int	verif_exist(char **path, char *argv)
{
	int		i;
	int		x;

	i = -1;
	x = 1;
	while (path[++i])
	{
		path[i] = ft_strjoin(path[i], argv);
		x = access(path[i], R_OK);
		if (x == 0)
			return (i);
	}
	return (-1);
}


/*char **verif_option(char **spli)
{
	char **result;
	int i;

	i = 0;
	while(spli[i])
		i++;
	i = 1;
	result = malloc(sizeof(char *) * i);
	result[0] = spli[0];
	while(spli[i])
	{
		if(spli[i][0] == '-')
		{
			result[i] = spli[i];
		}
		else
		{
			break ;
		}
		i++;
	}
	return (result);
}*/
