/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chevron3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicoue <tnicoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:12:26 by kcatrix           #+#    #+#             */
/*   Updated: 2022/09/29 12:13:07 by tnicoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_chevron_droite(char **spli, int i)
{
	int	file;
	int	y;

	y = 0;
	file = open(spli[i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	spli = del_i(spli, i);
	return (file);
}

int	ft_chevron_gauche(char **spli, int i, int y)
{
	int	file;

	file = open(spli[i + 1], O_WRONLY, 0777);
	if (file < 0)
	{
		close(y);
		g_stock.chkcrash = -1;
		printf("%s: No such file or directory\n", spli[i + 1]);
	}
	del_i(spli, i);
	return (file);
}

char	**del_i(char **spli, int i)
{
	int	y;

	y = i;
	free(spli[y]);
	while (spli[y])
	{
		spli[y] = spli[y + 1];
		y++;
	}
	free(spli[i]);
	while (spli[i] && spli[i + 1])
	{
		spli[i] = spli[i + 1];
		i++;
	}
	if (spli[i])
		spli[i] = NULL;
	return (spli);
}

int	double_chevron_droite(char **spli, int i)
{
	int	file;

	file = open(spli[i + 1], O_RDWR | O_CREAT | O_APPEND, 0777);
	del_i(spli, i);
	return (file);
}

int	ft_chevron_exist(char **spli)
{
	int	i;

	i = 0;
	while (spli[i])
	{
		if ((spli[i][0] == '>' && spli[i][1] == '\0') || ((spli[i][0] == '>'
			&& spli[i][1] == '>') && spli[i][2] == '\0'))
			return (1);
		if ((spli[i][0] == '<' && spli[i][1] == '\0') || ((spli[i][0] == '<'
			&& spli[i][1] == '<') && spli[i][2] == '\0'))
			return (2);
		i++;
	}
	return (0);
}
