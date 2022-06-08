#include "../includes/minishell.h"


char	*ft_exportaff(char *line)
{
	char *newline;
	int	i;
	
	newline = malloc(sizeof(char) * ft_strlen(line) + 3);
	i = 0;
	while (line[i])
	{
		newline[i] = line[i];
		if (line[i] == '=')
		{
			i++;
			newline[i] = '"';
			i++;
			while (line[i])
			{
				newline[i] = line[i - 1];
				i++;
			}
			newline[i] = line[i - 1];
			newline[++i] = '"';
			newline[++i] = '\0';
		}
		i++;
	}
	return (newline);
}
void	ft_export_noarg(void)
{
	int	i;
	char *line;

	i = 0;
	while (stock.cpenv[i])
	{
		line = ft_exportaff(stock.cpenv[i]);
		printf("declare -x %s\n", line);
		i++;
	}
}

char *ft_preline(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '=')
		{
			line[i] = '\0';
		}
		i++;
	}
	return (line);
}

int	veriflen(char **spli, int i)
{
	if (ft_strlen(spli[1]) > ft_strlen(ft_preline(stock.cpenv[i])))
		return (ft_strlen(spli[1]));
	else
		return(ft_strlen(ft_preline(stock.cpenv[i])));
		
}

int	ft_parseexport(char *spli)
{
	int	i;
	char *line;

	line = ft_preline(spli);
	i = 0;
	while (spli[i])
	{
		if (ft_isalpha(line[i]) != 1)
		{
			printf("export : '%s': not a valid identifier", spli);
			return (1);
		}
		i++;
	}
	return (0);
}


void	ft_export(char **spli)
{
	int	i;
	char	*lineenv;
	char	*lineenv2;

	i = 0;
	
	if (!spli[1])
		ft_export_noarg();
	else
	{
		if (ft_parseexport(spli[1]) == 1)
			return;
		while (stock.cpenv[i])
		{
			if (ft_strcmp(ft_preline(spli[1]), ft_preline(stock.cpenv[i])) < 0)
			{
				lineenv = stock.cpenv[i];
				stock.cpenv[i] = spli[i];
				while (stock.cpenv[++i])
				{
					lineenv2 = stock.cpenv[i];
					stock.cpenv[i] = lineenv;
					if (stock.cpenv[i + 1])
						lineenv = stock.cpenv[i + 1];
				}
			}
			i++;
		}
	}
}
