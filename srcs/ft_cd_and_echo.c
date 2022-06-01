#include "../includes/minishell.h"

void	cmd_echo(char **spli)
{
	int	i;

	i = 1;
	if(echo_option(spli[1]) == 0)
		i++;
	while(spli[i])
	{
		printf("%s", spli[i++]);
		if(spli[i] != NULL)
			printf(" ");
	}
	if(echo_option(spli[1]) == 1)
		printf("\n");
}

int	echo_option(char *spli)
{
    int i;

    i = 1;
    if(spli[0] == '-')
    {
        while(spli[i])
        {
            if(spli[i] == 'n')
            {
                i++;
            }
            else
                return (1);
        }
    }
    else
        return(1);
    return(0);
}
