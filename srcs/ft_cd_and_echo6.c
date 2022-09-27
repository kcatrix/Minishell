/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_and_echo6.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevyn <kevyn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 12:25:46 by kevyn             #+#    #+#             */
/*   Updated: 2022/09/27 13:02:30 by kevyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_replace_existe_val(char *spli, int y, int i, int z)
{
	char	*tmp;

	tmp = malloc(sizeof (char) * ft_strlen(spli));
	z = y;
	while (spli[z])
	{
		tmp[i] = spli[z];
		i++;
		z++;
	}
	if (tmp[i - 1] == '"')
		tmp[i - 1] = '\0';
	tmp = ft_replace_existe_val_boucle(tmp);
	spli = ft_replace_existe_val_end(spli, y, i, tmp);
	free_protect(tmp);
	return (spli);
}

char	*ft_replace_existe_val_boucle(char *tmp)
{
	int	i;

	i = 0;
	while (g_stock.cpenv[i])
	{
		if ((ft_memcmp(g_stock.cpenv[i], tmp + 1, ft_strlen(tmp) - 1) == 0)
			&& (g_stock.cpenv[i][ft_strlen(tmp) - 1] == '='))
		{
			free_protect(tmp);
			tmp = ft_mallocex(g_stock.cpenv[i]
					+ ft_strlen(tmp), tmp);
		}
		i++;
	}
	return (tmp);
}

char	*ft_add_cote(char *spli, int y, int i, char *tmp)
{
	if (spli[y - 1] == '"')
	{
		tmp[i] = '"';
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*ft_add_cote2(char *spli, int y, int i, char *tmp)
{
	if (spli[y] == '"')
	{
		tmp[i] = '"';
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
