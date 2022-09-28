/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_and_echo7.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicoue <tnicoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 11:22:39 by tnicoue           #+#    #+#             */
/*   Updated: 2022/09/28 15:16:18 by tnicoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"
#include <dirent.h>
#include <errno.h>

char	*getpwd2(void)
{
	int		i;
	char	*tmp;

	tmp = NULL;
	i = 0;
	while (g_stock.cpenv[i])
	{
		if (ft_memcmp(g_stock.cpenv[i], "PWD=", 4) == 0)
		{
			tmp = ft_mallocex((g_stock.cpenv[i] + 4), tmp);
			return (tmp);
		}
		i++;
	}
	return (NULL);
}

int	ft_verifdirexist(void)
{
	char	*testdir;
	char	*testdir2;
	DIR		*dir;

	testdir2 = getpwd2();
	testdir = ft_chk_last_path(testdir2);
	dir = opendir(testdir);
	free(testdir2);
	if (dir)
	{
		closedir(dir);
		return (0);
	}
	else
		return (1);
}

int	ft_modifdirdotdot(void)
{
	int	i;

	i = 0;
	printf("cd: error retrieving directory:cannot access parent directories\n");
	return (0);
}
