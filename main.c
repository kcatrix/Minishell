#include "minishell.h"

int main(int ac, char **av, char **ev)
{
	char *line;
	while(1)
	{
		line = readline("minishell >");
		if (!line[0])
			continue;
		add_history(line);
		if(strcmp(line, "exit") == 0)
			exit();
	}
	return(0);
}
