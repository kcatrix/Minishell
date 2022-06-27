#include "../includes/minishell.h"

void	ft_verif_chevron(char **spli)
{
	int	i;

	i = 0;
	while (spli[i])
	{
		if (spli[i][0] == '<' || spli[i][0] == '>')
		{
			//ft_chevron_redirect(spli, i);
			return ;
		}
		i++;		
	}
}
/*
void ft_chevron_redirect(char **spli, int i)
{
	int y;

	y = 0;
	while (spli[i][y])
	{
		if (spli[i][y] == '<')
		{

		}
		y++;
	}
}*/