#include "../includes/minishell.h"

char	**parse(char **spli)
{
	int i;

	i = 0;
	while(spli[i])
	{
		if(spli[i][0] == '$')
			spli[i] = cmd_dollar(spli[i]);
		i++;
	}
	return (spli);
}

char	*cmd_dollar(char *str)
{
	int i;

	i = 0;
	while (stock.cpenv[i])
	{
		if (ft_memcmp(stock.cpenv[i], str + 1, ft_strlen(str) - 1) == 0 
			&& stock.cpenv[i][ft_strlen(str) - 1] == '=')
				return (stock.cpenv[i] + ft_strlen(str));
		i++;
	}
	return ("\0");
}
