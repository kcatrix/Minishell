/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcatrix <kcatrix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:38:50 by tnicoue           #+#    #+#             */
/*   Updated: 2022/10/04 15:40:36 by kcatrix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	supp_env(char **env)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (env[i])
	{
		if (ft_memcmp(env[i], "PATH", 4) == 0)
			x = 1;
		i++;
	}
	if (x == 0)
		return (1);
	else
		return (0);
	return (0);
}

int	main(int ac, char **av, char **env)
{
	char	*line;

	ac = 0;
	av = NULL;
	prechauffage(env);
	while (1)
	{
		verif_arn();
		if ((g_stock.nbpassage == 0) && (g_stock.nbpip == 0))
		{
			line = readline("minishell > ");
			add_history(line);
			line = verif_pipe_end(line);
		}
		ft_cmd (line, env);
		if ((g_stock.nbpassage) == g_stock.nbpip + 1)
			ft_main_end(line);
		else
			free_spli(g_stock.line2);
	}
	free(line);
}

void	prechauffage(char **env)
{
	int	i;

	i = 0;
	g_stock.cpenv = ft_cp_env(env);
	verif_export_exist(i);
	set_signal(0);
	g_stock.nbpip = 0;
	g_stock.fork = 0;
	g_stock.nbpassage = 0;
}

int	is_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (1);
	}
	return (0);
}

void	f_exit(char **spli)
{
	int	exit_status;

	exit_status = 0;
	if (spli[1])
	{
		if (is_num(spli[1]) == 1)
		{
			printf("exit\n");
			printf("minishell: exit: %s: numeric argument required\n",
				spli[1]);
			g_stock.end = 255;
			exit(g_stock.end);
		}
		if (spli[2])
		{
			printf("minishell: exit: too many arguments\n");
			g_stock.end = 1;
			return ;
		}
		exit_status = ft_atoi(spli[1]);
	}
	printf("exit\n");
	g_stock.end = exit_status;
	exit(exit_status);
}

/* CPexp = Export (env trie) Cpenv = environnement 
exportadd : on va free le export actuel apres avoir cree une copie de ce dernier 
dans cpcpenv, on remalloc le cpexp a sa longueur + 1 (parce qu on va rajouter une
variable d environnement)

Puis a l aide de strcmp et ft_preline, il va comparer les valeurs ascii des noms
de variable d environnement avant les '=',
 si ce resultat (nouvelle valeur - valeur pointee de exp)
 est inferieur a 0, la nouvelle valeur se situe a l emplacement actuel
 
*/