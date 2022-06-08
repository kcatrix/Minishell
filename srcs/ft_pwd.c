#include "../includes/minishell.h"

void ft_pwd(void)
{
	int	i;

	i = 0;
	while (stock.cpenv[i])
	{
		if (ft_memcmp(stock.cpenv[i], "PWD=", 4) == 0)
		{
			printf("%s\n", stock.cpenv[i] + 4);
		}
		i++;
	}
}
