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
	//ft_veriftri();
	while (stock.cpenv[i])
	{
		line = malloc(sizeof(char) * ft_strlen(stock.cpenv[i]) + 3);
		line = *ft_exportaff(stock.cpenv[i], &line);
		printf("declare -x %s\n", line);
		free(line);
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
	int		y;
	char	**cpcpenv;

	i = 0;
	y = 0;
	while(stock.cpenv[i])
		i++;
	cpcpenv = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while(stock.cpenv[i])
	{
		cpcpenv[i] = malloc(sizeof(char) * ft_strlen(stock.cpenv[i]) + 1);
		while(stock.cpenv[i][y])
		{
			cpcpenv[i][y] = stock.cpenv[i][y];
			y++;
		}
		y = 0;
		free(stock.cpenv[i]);
		i++;
	}
	cpcpenv[i] = NULL;
	free(stock.cpenv);
	stock.cpenv = malloc(sizeof(char *) * (i + 2));
	return (cpcpenv);
}

void	ft_veriftri(void)
{
	int i;
	
	i = 0;
	while(stock.cpenv[i])
	{
		if (ft_strcmp(ft_preline(stock.cpenv[i]), ft_preline(stock.cpenv[i + 1])) > 0)
		{
			if (stock.cpenv[i + 2] == NULL)
			{
				break;
				return(0);
			}
		}
		else
		{
			break;
			return(1);
		}
		i++;
	}
}

void	ft_triexport(void)
{
	int	i;

	i = 0;
	while(
}

char	*ft_mallocex(char *str, char *str2)
{
	int	i;

	i = 0;
	
	str2 = malloc(sizeof(char) * (ft_strlen(str) + 1));
	while(str[i])
	{
		str2[i] = str[i];
		i++;
	}
	str2[i] = '\0';
	return (str2);
}

void	ft_exportadd(int i, char *spli)
{
	char 	**cpcpenv;
	int		y;
	int 	z;

	y = 0;
	z = 0;
	cpcpenv = ft_mallocexportadd();
	while (cpcpenv[i])
		{
			if (ft_strcmp(ft_preline(spli), ft_preline(cpcpenv[i])) < 0)
			{
				stock.cpenv[i] = ft_mallocex(spli, stock.cpenv[i]);
				y = i;
				i++;
				while (cpcpenv[y])
				{
					stock.cpenv[i] = ft_mallocex(cpcpenv[y], stock.cpenv[i]);
					free(cpcpenv[y]);
					y++;
					i++;
				}
				stock.cpenv[i] = NULL;
				free(cpcpenv);
				return ;
			}
			stock.cpenv[i] = ft_mallocex(cpcpenv[i], stock.cpenv[i]);
			free(cpcpenv[i]);
			i++;
		}
		stock.cpenv[i] = ft_mallocex(spli, stock.cpenv[i]);
		stock.cpenv[i + 1] = NULL;
		free(cpcpenv[i]);
		free(cpcpenv);
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
