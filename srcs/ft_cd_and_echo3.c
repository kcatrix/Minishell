/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_and_echo3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevyn <kevyn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:03:28 by kcatrix           #+#    #+#             */
/*   Updated: 2022/09/15 16:30:51 by kevyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	cmd_cd_dot_dot(void)
{
	int	i;

	i = 0;
	if (chdir("..") == -1)
		return ;
	while (g_stock.cpenv[i])
	{
		if (ft_memcmp(g_stock.cpenv[i], "OLDPWD=", 7) == 0 && g_stock.old == 0)
		{
			free(g_stock.cpenv[i]);
			g_stock.cpenv[i] = "OLDPWD=";
			g_stock.cpenv[i] = ft_strjoin(g_stock.cpenv[i], getpwd());
		}
		i++;
	}
	i = 0;
	while (g_stock.cpenv[i])
	{
		if (ft_memcmp(g_stock.cpenv[i], "PWD=", 4) == 0)
		{
			g_stock.cpenv[i] = ft_chk_last_path(g_stock.cpenv[i]);
		}
		i++;
	}
}

char	*ft_chk_last_path(char *pwd)
{
	char	*newpwd;
	int		i;

	i = 0;
	while (pwd[i])
		i++;
	i--;
	while (pwd[i])
	{
		if (pwd[i] == '/')
		{
			pwd[i] = '\0';
			newpwd = pwd;
			return (newpwd);
		}
		i--;
	}
	return (pwd);
}

void	cmd_cd_absolute_redirect(char *spli)
{
	if (spli[0] == '/')
		cmd_cd_absolute(spli);
	else
		cmd_cd_relative(spli);
}

void	cmd_cd_absolute(char *spli)
{
	if (chdir(spli) == -1)
	{
		printf("cd: %s: No such file or directory\n", spli);
		return ;
	}
	cmd_cd_absolute_pwd(spli);
}

void	cmd_cd_relative(char *spli)
{
	if (chdir(spli) == -1)
	{
		printf("cd: %s: No such file or directory\n", spli);
		return ;
	}
	cmd_cd_relative_pwd (spli);
}
