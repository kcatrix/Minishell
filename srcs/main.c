/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicoue <tnicoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:38:50 by tnicoue           #+#    #+#             */
/*   Updated: 2022/05/31 13:20:20 by tnicoue          ###   ########.fr       */
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

	stock.test = 0;
	while (1)
	{
		line = readline("minishell >");
		add_history(line);
		if (ft_strncmp(line, "exit", 4) == 0)
			exit(0);
		printf("oui\n");
		if (supp_env(env) == 1)
			return (0);
		printf("oui\n");
		id = fork();
		if (id == 0)
			return (ft_cmd(line, env));
		else
			waitpid(id, 0, 0);
	}
}
