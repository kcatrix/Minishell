#include "../includes/minishell.h"

int	verifline(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '=')
			return (0);
		i++;
	}
	return (1);
}

/*void	ft_recup_export()
{
	recuperer le export
}*/

void	ft_env(void)
{
	int	i;

	i = 0;
	//ft_recup_export()
	while (stock.cpenv[i])
	{
		if (verifline(stock.cpenv[i]) == 0)
			printf("%s\n", stock.cpenv[i]);
		i++;
	}
}

