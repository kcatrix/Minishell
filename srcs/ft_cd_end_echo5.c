/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_end_echo5.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevyn <kevyn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 12:18:57 by kevyn             #+#    #+#             */
/*   Updated: 2022/09/27 13:01:28 by kevyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	**del_quote_spe(char **spli)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	g_stock.arn2 = 0;
	while (spli[i])
	{
		while (spli[i][y])
		{
			if (spli[i][y] == '"')
				rm_char(spli[i], y);
			y++;
		}
		y = 0;
		i++;
	}
	return (spli);
}

char	**ft_checkdollar_inside(char **spli)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while (spli[i])
	{
		if (spli[i][0] != '\'')
		{
			while (spli[i][y])
			{
				if (spli[i][y] == '$')
					spli[i] = ft_replace_existe(spli[i], y);
				y++;
			}
			y = 0;
		}
		i++;
	}
	return (spli);
}

char	*ft_replace_existe(char *spli, int y)
{
	int		i;
	int		z;

	i = 0;
	z = 0;
	if ((spli[y + 1] == '?' && spli[y + 2] == '"')
		|| (spli[y + 1] == '?' && spli[y + 2] == '\0'))
		spli = ft_replace_existe_int(spli, y, i, z);
	else
		spli = ft_replace_existe_val(spli, y, i, z);
	g_stock.arn2 = 1;
	return (spli);
}

char	*ft_replace_existe_val_end(char *spli, int y, int i, char *tmp2)
{
	char	*tmp;

	i = 0;
	tmp = malloc(sizeof (char) * (ft_strlen(spli) + ft_strlen(tmp2) + 1));
	while (i != y)
	{
		tmp[i] = spli[i];
		i++;
	}
	y = 0;
	while (tmp2[y])
	{
		tmp[i] = tmp2[y];
		i++;
		y++;
	}
	y = 0;
	while (spli[y])
		y++;
	tmp = ft_add_cote(spli, y, i, tmp);
	free_protect(spli);
	return (tmp);
}

char	*ft_replace_existe_int(char *spli, int y, int i, int z)
{
	char	*tmp2;
	char	*tmp;

	tmp2 = ft_itoa(g_stock.end);
	tmp = malloc(sizeof (char) * (ft_strlen(spli) -2 + ft_strlen(tmp2) + 1));
	while (i != y)
	{
		tmp[i] = spli[i];
		i++;
	}
	while (tmp2[z])
	{
		tmp[i] = tmp2[z];
		i++;
		z++;
	}
	y = y + 2;
	tmp = ft_add_cote2(spli, y, i, tmp);
	free(tmp2);
	free(spli);
	return (tmp);
}
