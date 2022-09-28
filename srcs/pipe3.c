/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicoue <tnicoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 07:03:23 by exostiv           #+#    #+#             */
/*   Updated: 2022/09/28 16:02:51 by tnicoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	fixunsetpip2(char **spli)
{
	int	in;
	int	id;

	if (!spli[1])
	{
		pipe(g_stock.pip);
		in = g_stock.pip[0];
		id = fork();
		if (id == 0)
		{
			ft_pipe2(in);
			exit(0);
		}
		else
		{
			fixwait(id);
			return (0);
		}
	}
	return (1);
}

char	*ft_replace_absolute(char **spli)
{
	int		x;
	int		y;
	int		i;
	char	*tmp;

	tmp = NULL;
	i = 0;
	y = 0;
	x = access(spli[0], R_OK);
	if (x == 0)
	{
		while (spli[0][i])
			i++;
		while (spli[0][i--] != '/')
			y++;
		tmp = ft_mallocex(spli[0] + i + 2, tmp);
		free(spli[0]);
	}
	return (tmp);
}

char	*ft_replace_quote(char *spli)
{
	char	*tmp;
	int		i;
	int		y;

	i = 0;
	y = 0;
	tmp = malloc(sizeof (char) * ft_strlen(spli) + 5);
	tmp[i++] = '"';
	tmp[i++] = '\'';
	while (spli[y])
	{
		tmp[i] = spli[y];
		i++;
		y++;
	}
	tmp[i++] = '\'';
	tmp[i++] = '"';
	tmp[i] = '\0';
	free(spli);
	return (tmp);
}

void	fixcd(void)
{
	int	in;
	int	id;

	pipe(g_stock.pip);
	in = g_stock.pip[0];
	id = fork();
	if (id == 0)
	{
		ft_pipe2(in);
		exit(0);
	}
	else
	{
		fixwait(id);
		return ;
	}
	return ;
}

int	ft_arn(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != 32 && line[i] != '\0')
			return (0);
		i++;
	}
	return (1);
}
