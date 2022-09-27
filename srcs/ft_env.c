/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exostiv <exostiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:14:19 by kcatrix           #+#    #+#             */
/*   Updated: 2022/09/22 06:56:15 by exostiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	verifline(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '=')
			return (0);
		i++;
	}
	return (1);
}

void	ft_env(void)
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
			if (verifline(g_stock.cpenv[i]) == 0)
				printf("%s\n", g_stock.cpenv[i]);
			i++;
		}
		exit(0);
	}
	else
		fixwait(id);
}
