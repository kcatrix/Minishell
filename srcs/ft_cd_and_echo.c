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
	free_spli(spli);
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
        if (i == 1)
            return(1);
    }
    else
        return(1);
    return(0);
}

void	cmd_cd(char **spli, char **env)
{
	stock.cpenv = ft_cp_env(env);
	if (!spli[1])
        cmd_cd_noarg();
	else if (strcmp(spli[1], ".") == 0)
		cmd_cd_dot();
	else if (strcmp(spli[1], "..") == 0)
        cmd_cd_dot_dot(); 
    else
        cmd_cd_absolute_redirect(spli[1]);
	free_spli(spli);
}

char **cmd_cd_dot(void)
{ 
    int     i;

    i = 0;   
    while(stock.cpenv[i])
    {
        if (ft_memcmp(stock.cpenv[i], "OLDPWD=", 7) == 0)
        {
            stock.cpenv[i] = "OLDPWD=";
            stock.cpenv[i] = ft_strjoin(stock.cpenv[i], getpwd());
        }
        i++;
    }
  	return (NULL);
}

char *getpwd(void)
{
    int i;
    int j;

    i = 0;
    j = 4;
    while(stock.cpenv[i])
    {
        if (ft_memcmp(stock.cpenv[i], "PWD=", 4) == 0)
            return(stock.cpenv[i] + 4);
        i++;
    }
    return(NULL);
}

void    cmd_cd_dot_dot(void)
{
    int i;

    i = 0;

    if (chdir("..") == -1)
        return;
    while(stock.cpenv[i])
    {
        if (ft_memcmp(stock.cpenv[i], "OLDPWD=", 7) == 0)
        {
            stock.cpenv[i] = "OLDPWD=";
            stock.cpenv[i] = ft_strjoin(stock.cpenv[i], getpwd());
        }
        i++;
    }
    i = 0;
    while(stock.cpenv[i])
    {
        if (ft_memcmp(stock.cpenv[i], "PWD=", 4) == 0)
        {
            stock.cpenv[i] = ft_chk_last_path(stock.cpenv[i]);
        }
        i++;
    }
}

char    *ft_chk_last_path(char *pwd)
{
    char *newPWD;
    int i;

    i = 0;
    while (pwd[i])
        i++;
    i--;
    while (pwd[i])
    {
        if(pwd[i] == '/')
        {
            pwd[i] = '\0';
            newPWD = pwd;
            return(newPWD);
        }
        i--;
    }
    return(pwd);
}

void    cmd_cd_absolute_redirect(char *spli)
{
    if(spli[0] == '/')
        cmd_cd_absolute(spli);
    else
        cmd_cd_relative(spli);
}

void    cmd_cd_absolute(char *spli)
{
    {
        printf("cd: %s: No such file or directory\n", spli);
        return;
    }
    cmd_cd_absolute_pwd(spli);
}

void    cmd_cd_relative(char *spli)
{
    if (chdir(spli) == -1)
    {
        printf("cd: %s: No such file or directory\n", spli);
        return;
    }
    cmd_cd_relative_pwd(spli);
}

void    cmd_cd_absolute_pwd(char *spli)
{
    int i;

    i = 0;

    while(stock.cpenv[i])
    {
        if (ft_memcmp(stock.cpenv[i], "OLDPWD=", 7) == 0)
        {
			free(stock.cpenv[i]);
            stock.cpenv[i] = "OLDPWD=";
            stock.cpenv[i] = ft_strjoin(stock.cpenv[i], getpwd());
        }
        i++;
    }
    i = 0;
    while(stock.cpenv[i])
    {
        if (ft_memcmp(stock.cpenv[i], "PWD=", 4) == 0)
            stock.cpenv[i] = ft_strjoin("PWD=", spli);
        i++;
    }
}

void    cmd_cd_relative_pwd(char *spli)
{
    int i;

    i = 0;
    while(stock.cpenv[i])
    {
        if (ft_memcmp(stock.cpenv[i], "OLDPWD=", 7) == 0)
        {
			free(stock.cpenv[i]);
            stock.cpenv[i] = "OLDPWD=";
            stock.cpenv[i] = ft_strjoin(stock.cpenv[i], getpwd());
        }
        i++;
    }
    i = 0;
    while(stock.cpenv[i])
    {
        if (ft_memcmp(stock.cpenv[i], "PWD=", 4) == 0)
        {
            stock.cpenv[i] = ft_strjoin(stock.cpenv[i], "/");
            if(verifpwd(spli) == 0)
                spli[ft_strlen(spli) - 1] = '\0';
            stock.cpenv[i] = ft_strjoin(stock.cpenv[i], spli);
        }
        i++;
    }
}

int verifpwd(char *spli)
{
    int i;

    i = 0;
    while(spli[i])
        i++;
    i--;
    if (spli[i] == '/')
        return(0);
    else
        return(1);
}

void	cmd_cd_noarg(void)
{
	int i;

	i = 0;
	while(stock.cpenv[i])
	{
        if (ft_memcmp(stock.cpenv[i], "HOME=", 5) == 0)
		{
			chdir(stock.cpenv[i] + 5);
			cmd_cd_pwd(stock.cpenv[i] + 5);
		}
        i++;
	}
}

void    cmd_cd_pwd(char *home)
{
    int i;

    i = 0;
    while(stock.cpenv[i])
    {
        if (ft_memcmp(stock.cpenv[i], "OLDPWD=", 7) == 0)
        {
			free(stock.cpenv[i]);
            stock.cpenv[i] = "OLDPWD=";
            stock.cpenv[i] = ft_strjoin(stock.cpenv[i], getpwd());
        }
        i++;
    }
    i = 0;
    while(stock.cpenv[i])
    {
        if (ft_memcmp(stock.cpenv[i], "PWD=", 4) == 0)
        {
			free(stock.cpenv[i]);
			stock.cpenv[i] = "PWD=";
            stock.cpenv[i] = ft_strjoin(stock.cpenv[i], home);
        }
        i++;
    }
}
