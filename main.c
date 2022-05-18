#include "minishell.h"

int main()
{
	char *line;
	while(1)
	{
		line = readline("minishell >");
		if (!line[0])
			continue;
		add_history(line);
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