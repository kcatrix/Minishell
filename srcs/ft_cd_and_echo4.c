/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd_and_echo4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevyn <kevyn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 14:13:40 by kevyn             #+#    #+#             */
/*   Updated: 2022/09/16 14:15:28 by kevyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	cmd_cd_noarg(void)
{
	int	i;

	i = 0;
	while (g_stock.cpenv[i])
	{
		if (ft_memcmp(g_stock.cpenv[i], "HOME=", 5) == 0)
		{
			chdir(g_stock.cpenv[i] + 5);
			cmd_cd_pwd(g_stock.cpenv[i] + 5);
		}
		i++;
	}
}
