#include "../includes/minishell.h"


char	**ft_exportaff(char *line, char **newline)
{
	int	i;
	
	i = 0;
	while (line[i])
	{
		newline[0][i] = line[i];
		if (line[i] == '=')
		{
			i++;
			newline[0][i] = '"';
			i++;
			while (line[i])
			{
				newline[0][i] = line[i - 1];
				i++;
			}
			newline[0][i] = line[i - 1];
			newline[0][++i] = '"';
			newline[0][++i] = '\0';
			return (newline);
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
		line = malloc(sizeof(char) * ft_strlen(stock.cpenv[i]) + 3);
		line = *ft_exportaff(stock.cpenv[i], &line);
		printf("declare -x %s\n", line);
		//free(line);
		printf("okgoogle\n");
		i++;
	}
}

char *ft_preline(char *line)
{
	char	*line2;
	int		i;

	i = 0;
	line2 = malloc(sizeof(char) * ft_strlen(line) + 1);
	while (line[i])
	{
		line2[i] = line[i];
		i++;
	}
	line2[i] = '\0';
	i = 0;
	while (line2[i])
	{
		if (line2[i] == '=')
		{
			line2[i] = '\0';
		}
		i++;
	}
	return (line2);
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
	while (line[i])
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


int	ft_verifenv(char *spli)
{
	int	i;

	i = 0;
	while(stock.cpenv[i])
	{
		if (ft_strcmp(ft_preline(spli), ft_preline(stock.cpenv[i])) == 0)
		{
			stock.cpenv[i] = spli;
			return (1);
		}
		i++;
	}
	return (0);
}

char	**ft_mallocexportadd(void)
{
	int		i;
	char	**cpcpenv;

	i = 0;
	while(stock.cpenv[i])
		i++;
	cpcpenv = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while(stock.cpenv[i])
	{
		//CHANGER LES MALLOC FAST
		cpcpenv[i] = malloc(sizeof(char) * ft_strlen(stock.cpenv[i]) + 1);
		cpcpenv[i] = stock.cpenv[i];
		printf("fdpdemalloc\n");
		//free(stock.cpenv[i]);
		printf("fdpdemalloc2\n");
		i++;
	}
	cpcpenv[i] = "\0";
	printf("no\n");
	free(stock.cpenv);
	printf("no\n");
	stock.cpenv = malloc(sizeof(char *) * (i + 2));
	return (cpcpenv);
}

/*void	ft_veriftri(

void	ft_triexport(void)
{
	int	i;

	i = 0;
	while(
}*/

void	ft_exportadd(int i, char *spli)
{
	char 	**cpcpenv;
	int		y;

	y = 0;
	cpcpenv = ft_mallocexportadd();
	while (cpcpenv[i])
		{
			printf("no2\n");
			if (ft_strcmp(ft_preline(spli), ft_preline(cpcpenv[i])) < 0)
			{
				stock.cpenv[i] = malloc(sizeof(char) * ft_strlen(spli) + 1);
				stock.cpenv[i] = spli;
				y = i;
				i++;
				while (cpcpenv[y])
				{
					stock.cpenv[i] = malloc(sizeof(char) * ft_strlen(cpcpenv[y]) + 1);
					stock.cpenv[i] = cpcpenv[y];
					printf("cpcpenv[i] = %s\n", stock.cpenv[i]);
					//free(cpcpenv[i - 1]);
					//CHANGER LES MALLOCS FAST
					y++;
					i++;
				}
				printf("cpcpenv[i - 2] = %s\n", cpcpenv[y - 1]);
				return ;
			}
			stock.cpenv[i] = malloc(sizeof(char) * ft_strlen(cpcpenv[i]) + 1);
			stock.cpenv[i] = cpcpenv[i];
			//free(cpcpenv[i]);
			i++;
		}
		if (ft_strcmp(ft_preline(spli), ft_preline(stock.cpenv[i - 1])) > 0)
		{
			printf("Spli = %s\n", spli);
			stock.cpenv[i] = malloc(sizeof(char) * ft_strlen(spli) + 1);
			stock.cpenv[i] = spli;
			stock.cpenv[i + 1] = NULL;
		}
		free(cpcpenv);
		printf("no\n");
}

void	ft_export(char **spli)
{
	int	i;

	i = 0;
	if (!spli[1])
		ft_export_noarg();
	else
	{
		if (ft_parseexport(spli[1]) == 1)
			return;
		else if (ft_verifenv(spli[1]) == 1)
			return;
		ft_exportadd(i, spli[1]);
	}
}
