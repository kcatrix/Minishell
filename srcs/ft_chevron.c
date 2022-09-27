/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chevron.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exostiv <exostiv@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 14:49:32 by kcatrix           #+#    #+#             */
/*   Updated: 2022/09/12 05:25:14 by exostiv          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_verif_chevron(char **spli)
{
	int	i;

	i = 0;
	while (spli[i])
	{
		if ((spli[i][0] == '>' && spli[i][1] == '\0')
			|| ((spli[i][0] == '>' && spli[i][1] == '>') && spli[i][2] == '\0'))
		{
			ft_chevron_redirect(spli, i);
			return (0);
		}
		if ((spli[i][0] == '<' && spli[i][1] == '\0')
			|| ((spli[i][0] == '<' && spli[i][1] == '<') && spli[i][2] == '\0'))
		{
			ft_chevron_redirect2(spli, i);
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_chevron_redirect(char **spli, int i)
{
	int	y;

	y = -1;
	y = ft_chevron_redirect_boucle(spli, i, y);
	if (y == -1)
		return (-1);
	if (y != -1)
		g_stock.out = y;
	return (y);
}

int	ft_chevron_redirect_boucle(char **spli, int i, int y)
{
	while (ft_chevron_exist(spli) != 0)
	{
		while (spli[i] && spli[i][0] == '>' && spli[i][1] == '\0')
		{	
			close(y);
			y = ft_chevron_droite(spli, i);
		}
		while (spli[i] && spli[i][0] == '<' && spli[i][1] == '\0')
		{
			if (ft_chevron_gauche(spli, i, y) == -1)
				return (-1);
		}
		while (spli[i] && spli[i][0] == '>'
			&& spli[i][1] == '>' && spli[i][2] == '\0')
		{
			close (y);
			y = double_chevron_droite(spli, i);
		}
		while (spli[i] && spli[i][0] == '<'
			&& spli[i][1] == '<' && spli[i][2] == '\0')
			heredoc(spli, i);
	}
	return (y);
}
