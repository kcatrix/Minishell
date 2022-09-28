/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicoue <tnicoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 02:38:58 by exostiv           #+#    #+#             */
/*   Updated: 2022/09/28 15:03:07 by tnicoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	fixwait(int id)
{
	waitpid(id, 0, 0);
	if (g_stock.out > 1)
		close(g_stock.out);
	if (g_stock.in > 0)
		close(g_stock.in);
	close(g_stock.pip[1]);
	fix_out_inr_redir();
}

void	fixwaitexp(int id, char **spli, int i)
{
	waitpid(id, 0, 0);
	if (spli[1] && g_stock.nbpip == 0)
	{
		if (ft_parseexport(spli[1]) == 1)
			return ;
		else if (ft_verifenv(spli[1]) == 1)
			return ;
		ft_exportadd(i, spli[1]);
	}
	if (g_stock.out > 1)
		close(g_stock.out);
	if (g_stock.in > 0)
		close(g_stock.in);
	close(g_stock.pip[1]);
	fix_out_inr_redir();
}

void	fixechopip(int in, char **spli, int i)
{
	ft_pipe2(in);
	if (!spli[1])
	{
		printf("\n");
		fix_out_inr_redir();
		exit(0);
	}
	if (echo_option(spli[1]) == 0)
		i++;
	while (spli[i])
	{
		printf("%s", spli[i++]);
		if (spli[i] != NULL)
			printf(" ");
	}
	if (echo_option(spli[1]) == 1)
		printf("\n");
	exit(0);
}

char	**fixunsetpip(char **env, char**spli, char **tmp, int i)
{
	if (ft_verifexistunset(env, spli) == 1 || g_stock.nbpip != 0)
	{
		if (g_stock.out > 1)
			close(g_stock.out);
		if (g_stock.in > 0)
			close(g_stock.in);
		close(g_stock.pip[1]);
		fix_out_inr_redir();
		return (env);
	}
	tmp = ft_cp_env(env);
	cmd_unset2(spli, tmp, env, i);
	free_spli(tmp);
	if (g_stock.out > 1)
		close(g_stock.out);
	if (g_stock.in > 0)
		close(g_stock.in);
	close(g_stock.pip[1]);
	fix_out_inr_redir();
	return (env);
}
