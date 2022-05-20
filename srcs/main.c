#include "../includes/minishell.h"


int main(int ac, char** av, char **env)
{
	ac = 0;
	av = NULL;
	char *line;
	while(1)
	{
		line = readline("minishell >");
		ft_cmd(line, env);
	}
}
