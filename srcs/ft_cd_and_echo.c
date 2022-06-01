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

void	cmd_cd(char **spli, char **env)
{
	env = NULL;
	stock.cpenv = ft_cp_env(env);
	
	if (strcmp(spli[1], ".") == 0)
		env = cmd_cd_dot(spli);
	if (strcmp(spli[1], "..") == 0)
		printf("c'est un points points");
	//chdir(/usr)
	//chdir(..)
}

char **cmd_cd_dot(char **spli)
{ 
//	int     i;
 //   char    **tmp;

	spli = NULL;


/*
    tmp = ft_cp_env(env);
    i = 0;
    while (tmp[i])
    {
        if (ft_memcmp(tmp[i], "OLDPWD=", 7)) == 0 
        {
            while(tmp[i])
            {
                tmp[i] = tmp[i + 1];
                i++;
            }
        }
        i++;
    }*/
  	 return (NULL);
}
