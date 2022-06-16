/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicoue <tnicoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:38:50 by tnicoue           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/06/16 16:30:04 by kcatrix          ###   ########.fr       */
=======
/*   Updated: 2022/06/16 16:20:31 by tnicoue          ###   ########.fr       */
>>>>>>> 65c52b7f12dbe882ed2159b41e5a93c4cfc2c8e6
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
	int		id;

	ac = 0;
	av = NULL;
	id = 0;

	stock.cpenv = ft_cp_env(env);
	while (1)
	{
		line = readline("minishell >");
		add_history(line);
		ft_cmd(line, env);
	}
	free(line);
}

int	is_num(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (1);
	}
	return (0);
}

void f_exit(char **spli)
{
	int	exit_status;

	exit_status = 0;
	if (spli[1])
	{
		if (is_num(spli[1]) == 1)
		{
			printf("minishell: exit: %s: numeric argument required\n",
				spli[1]);
			return ;
		}
		if (spli[2])
		{
			printf("minishell: exit: too many arguments\n");
			return ;
		}
		exit_status = ft_atoi(spli[1]);
	}
	printf("exit\n");
	//free_lines();
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




/*i = 1 2 3 4 5 6  7  8 
8

stock.cpexp (new)

	1 2 4 5 6 8 12
i = 1 2 3 4 5 6 7





	*/
 

>>>>>>> 65c52b7f12dbe882ed2159b41e5a93c4cfc2c8e6
