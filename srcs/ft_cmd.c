/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcatrix <kcatrix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:38:47 by tnicoue           #+#    #+#             */
/*   Updated: 2022/06/27 14:16:06 by kcatrix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/minishell.h"

/*

pipe gerer les quotes correctement, gerer les pipes chelous

env affiche pas les variables vides et export oui
 
EXPORT ; La commande export marque une variable d'environnement à exporter 
avec tout processus enfant nouvellement créé et permet ainsi à un processus 
enfant d'hériter de toutes les variables marquées.
*/
/*char	**ft_verifparam(char *env, t_stock *env2)
{
	int	i;

	i = 0;
	while(env[i])
	{
		
	}
}*/
/*char	*ft_suppr(char *tmp, char *spli)
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
}*/

void	free_spli(char **spli)
{
	int i;

	i = 0;
	while (spli[i])
	{
		free(spli[i]);
		i++;
	}
}

char **ft_cp_env(char **env)
{
	int	i;
	int	j;
	char **tmp;

	i = 0;
	while(env[i])
		i++;
	tmp = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while(env[i])
	{
		tmp[i] = malloc(sizeof(char) * ft_strlen(env[i]) + 1);
		j = 0;
		while(env[i][j])
		{
			tmp[i][j] = env[i][j];
			j++;
		}
		tmp[i][j] = '\0';
		i++;
	}
	return (tmp);
}

// securitee a rajouter pour verifier l existence du parametre au sein de l env
// stocker les differents parametre dans un tableau
char **cmd_unset(char **spli, char **env)
{
	int		i;
	int		y;
	char	**tmp;

	i = 0;
	y = 0;
	tmp = ft_cp_env(env);
	free_spli(env);
	free(env);
	while (tmp[i])
		i++;
	printf("i = %d\n", i);
	printf("jean\n");
	env = malloc(sizeof(char *) * i);
	i = 0;
	while (tmp[i])
	{//A MODIFIER, MALLOC
		printf("%d i\n", i);
		printf("bon\n");
		if (ft_memcmp(tmp[i], spli[1], ft_strlen(spli[1])) == 0 
			&& (tmp[i][ft_strlen(spli[1])] == '=') && printf("JPPALED\n"))
		{
			printf("JPPALED\n");
			while(tmp[i][y] != '=')
				y++;
			tmp[i][y] = '\0';
			printf("a rien\n");
			return (tmp);
		}
		i++;
	}
	printf("du tout\n");
	return (tmp);
}

int	ft_redirect(char **spli, char **env)
{
	int	i;

	i = 0;
	if (ft_strcmp(spli[0], "unset") == 0)
	{
		if (!spli[1])
			return (0);
		stock.cpenv = cmd_unset(spli, stock.cpenv);
		stock.cpexp = cmd_unset(spli, stock.cpexp);
		free_spli(spli);
		return (0);
	}
	else if (ft_strcmp(spli[0], "echo") == 0)
	{
		cmd_echo(spli);
		return(0);
	}
	else if (ft_strcmp(spli[0], "cd") == 0)
	{
		cmd_cd(spli, env);
		return(0);
	}
	else if (ft_strcmp(spli[0], "PWD") == 0 || ft_strcmp(spli[0], "pwd") == 0)
	{
		ft_pwd();
		free_spli(spli);
		return(0);
	}
	else if (ft_strcmp(spli[0], "env") == 0 || ft_strcmp(spli[0], "ENV") == 0)
	{
		ft_env();
		free_spli(spli);
		return(0);
	}
	else if (ft_strcmp(spli[0], "export") == 0)
	{
		ft_export(spli);
		free_spli(spli);
		return(0);
	}
	else if (ft_strcmp(spli[0], "exit") == 0)
	{
		f_exit(spli);
		return(0);
	}
	return (1);
}


int	ft_cmd(char *line, char **env)
{
	char	**path;
	char	**spli;
	int		i;
	int		id;

	i = 0;
	if (line[0] == 0)
		return (0);
	path = path_fct(env);
	//split use
	spli = ft_split(line, ' ');
	//split
	spli = parse(spli);
	ft_verif_chevron(spli);
	if (ft_redirect(spli, env) == 0)
	{
		free_spli(path);
		return (0);
	}
	if (path == NULL)
	{
		printf("%s: No such file or directory\n", spli[0]);
		return(0);
	}
	i = verif_exist(path, spli[0]);
	if (i == -1 || !path)
	{
		printf("%s: Command not found\n", line);
		return (-1);
	}
	id = fork();
	if (id == 0)
		execve(path[i], spli, env);
	else
	{
		waitpid(id, 0, 0);
		free_spli(path);
	}
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
	if (env[i] == NULL)
		return(NULL);

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
