/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicoue <tnicoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 10:38:50 by tnicoue           #+#    #+#             */
/*   Updated: 2022/05/23 13:53:41 by kcatrix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int main(int ac, char** av, char **env)
{
	char	*line;
	int		id;

	ac = 0;
	av = NULL;
	id = 0;
	while(1)
	{
		line = readline("minishell >");
		add_history(line);
		id = fork();
		if(id == 0)
			ft_cmd(line, env);
		else
		{
			wait(NULL);
			//continue;
		}
	}
}
