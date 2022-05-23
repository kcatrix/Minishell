/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicoue <tnicoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:38:50 by tnicoue           #+#    #+#             */
/*   Updated: 2022/05/23 15:21:20 by kcatrix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int main(int ac, char** av, char **env)
{
	char	*line;
	int		id;
	int		x;

	ac = 0;
	x = 0;
	av = NULL;
	id = 0;
	while(1)
	{
		/*if(x > 0)
		{
			x--;
			exit(0);
		}*/
		line = readline("minishell >");
		add_history(line);
		if (ft_strncmp(line, "exit", 4) == 0)
			exit(0);
		id = fork();
		if(id == 0)
		{
			x++;
			return ft_cmd(line, env);
		}
		else
			waitpid(id, 0, 0);
	}
}
