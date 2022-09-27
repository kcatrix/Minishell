/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevyn <kevyn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 19:08:29 by kevyn             #+#    #+#             */
/*   Updated: 2022/09/12 15:12:57 by kevyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	interrupt_signal(int signal)
{
	(void) signal;
	if (g_stock.fork)
	{
		kill(g_stock.fork, SIGINT);
		write(1, "\n", 1);
		g_stock.fork = 0;
	}
	else
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	quit_signal(int signum)
{
	if (signum == 11)
	{
		printf("exit\n");
		exit(0);
	}
}

void	set_signal(int is_printed)
{
	struct termios	t;

	tcgetattr(0, &t);
	if (is_printed)
		(&t)->c_lflag |= ECHOCTL;
	else
		(&t)->c_lflag &= ~ECHOCTL;
	tcsetattr(0, TCSANOW, &t);
}
