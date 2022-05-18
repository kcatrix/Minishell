#include "minishell.h"

void ft_ajout(char **path2)
{
	int i;

	i = 0;
	while(path2[i])
	{
		path2[i] = ft_strjoin(path2[i], "/");
		i++;
	}
}

int ft_verifaccess(char **str, char *argv)
{
	int i;
	char **str2;

	str2 = malloc(sizeof(char*) * 5 + 1);
	i = 0;
	while(str[i])
	{
		ft_strjoin(str[i], argv);
		str2[i] = ft_strjoin(str[i], argv);
		str2[i] = ft_strjoin(str2[i], "/");
		i++;
	}
	i = 0;
	while(str2[i])
	{
		printf("%s path2\n", str2[i]);
		if(execve(str2[i], R_OK) == 0)
			return(0);
		i++;
	}
	return(-1);
}

int main(int ac, char** av, char **env)
{
	ac = 0;
	av = NULL;
	char *line;
	int i = 0;
	char *path; 
	char **path2;
	char **argv;

	while(env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			{
				printf("voila le path %s \n", env[i] + 5);
				path = env[i] + 5;
				path2 = ft_split(path, ':');
				ft_ajout(path2);
			}
		i++;
	}
	
	
	i = 0;
	while (path2[i])
	{
		printf("Path2 = %s\n", path2[i]);
		i++;
	}
	while(1)
	{
		line = readline("minishell >");
		argv = ft_split(line,' ');
		printf("1\n");
		if (ft_verifaccess(path2, argv[0]) == 0)
		{
			printf("ok\n");
			//fonction verif en fonction de la fonction
		}
		else
			printf("%s: command not found\n", argv[0]);
		if (!line[0])
			continue;
		add_history(line);


	//sert a verifier la ligne entree, sera en 





		//split sur la line, verif avec les differents path + le premier argument 
//		checkcmd(line);
		if(strcmp(line, "exit") == 0) //souspartie
			exit(100);
	}
	return(0);
}

/*int checkcmd()
{
	if (ACCESS(line) == 

}*/