/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevyn <kevyn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 13:30:01 by kevyn             #+#    #+#             */
/*   Updated: 2022/09/16 15:31:14 by kevyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	child_process(char **path, char **spli, char **env, int in)
{
	if (g_stock.nbpip == 0
		|| (g_stock.nbpip > 0 && g_stock.nbpassage == g_stock.nbpip + 1))
	{
		dup2(g_stock.out, STDOUT_FILENO);
		dup2(g_stock.in, STDIN_FILENO);
	}
	if (g_stock.pip[0] && g_stock.nbpassage != 1)
	{
		if (g_stock.in != 0)
			dup2(g_stock.in, STDIN_FILENO);
		else
			dup2(in, STDIN_FILENO);
	}
	ft_pipe();
	execve(path[g_stock.i], spli, env);
}
