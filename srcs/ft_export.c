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
	while (stock.cpexp[i])
	{
		line = malloc(sizeof(char) * ft_strlen(stock.cpexp[i]) + 3);
		line = *ft_exportaff(stock.cpexp[i], &line);
		printf("declare -x %s\n", line);
		free(line);
		//segfault ici sans printf \n ?
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
	while(stock.cpexp[i])
		i++;
	cpcpenv = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while(stock.cpexp[i])
	{
		cpcpenv[i] = malloc(sizeof(char) * ft_strlen(stock.cpexp[i]) + 1);
		while(stock.cpexp[i][y])
		{
			cpcpenv[i][y] = stock.cpexp[i][y];
			y++;
		}
		cpcpenv[i][y] = '\0';
		y = 0;
		printf("crash\n");
		free(stock.cpexp[i]);
		i++;
	}
	cpcpenv[i] = NULL;
	printf("crash\n");
	free(stock.cpexp);
	stock.cpexp = malloc(sizeof(char *) * (i + 2));
	return (cpcpenv);
}

/*void	ft_veriftri(void)
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
}*/

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

void	ft_triexport(char *str)
{
	char	*save;
	char	*save2;
	int		i;

	save = NULL;
	save2 = NULL;
	i = 0;
	while (stock.cpexp[i])
	{
			if (ft_strcmp(ft_preline(str), ft_preline(stock.cpexp[i])) < 0)
			{
				save = ft_mallocex(stock.cpexp[i], save);
				free(stock.cpexp[i]);
				stock.cpexp[i] = ft_mallocex(str, stock.cpexp[i]);
				i++;
				while (stock.cpexp[i])
				{
					save2 = ft_mallocex(stock.cpexp[i], save2);
					free(stock.cpexp[i]);
					stock.cpexp[i] = ft_mallocex(save, stock.cpexp[i]);
					free(save);
					save = ft_mallocex(save2, save);
					free(save2);
					i++;
				}
				free(stock.cpexp[i]);
				stock.cpexp[i] = ft_mallocex(save, stock.cpexp[i]);
				stock.cpexp[i + 1] = NULL;
				return ;
			}
			//Attention taille du stock.cpexp pas parfaitement malloc
			i++;
	}
	if (!stock.cpexp[0])
	{
		stock.cpexp[0] = ft_mallocex(stock.cpenv[0], stock.cpexp[0]);
		return ;
	}
	free(stock.cpexp[i]);
	stock.cpexp[i] = ft_mallocex(str, stock.cpexp[i]);
	stock.cpexp[i + 1] = NULL;
	return ;
}

int	ft_verifspli(char *spli)
{
	int	i;
	int	y;

	y = 0;
	i = 0;
	while(spli[i])
	{
		if (spli[i] == '=')
		{
			while(spli[++i])
			{
				if(spli[i] != 22 && spli[i] != nul)
					y = 1;
			}
		}
		if (y == 1)
			return (0);
	}
	return (1);
}
int	ft_verifdoublon(char *spli)
{
	int	i;

	i = 0;
	while(stock.cpexp[i])
	{
		if (ft_preline(spli) == ft_preline(stock.cpexp[i] 
			&& ft_verifspli(spli) != 0))
		{
			stock.cpexp[i] = ft_mallocex(spli, stock.cpexp[i])
			return (0);
		}
		i++;
	}
	return (1);
}

void	ft_exportadd(int i, char *spli)
{
	char 	**cpcpexp;
	int		y;
	int 	z;

	y = 0;
	z = 0;
	//verif doublon
	cpcpexp = ft_mallocexportadd();
	while (cpcpexp[i])
		{
			if (ft_strcmp(ft_preline(spli), ft_preline(cpcpexp[i])) < 0)
			{
				stock.cpexp[i] = ft_mallocex(spli, stock.cpexp[i]);
				y = i;
				i++;
				while (cpcpexp[y])
				{
					stock.cpexp[i] = ft_mallocex(cpcpexp[y], stock.cpexp[i]);
					free(cpcpexp[y]);
					y++;
					i++;
				}
				stock.cpexp[i] = NULL;
				free(cpcpexp);
				return ;
			}
			stock.cpexp[i] = ft_mallocex(cpcpexp[i], stock.cpexp[i]);
			free(cpcpexp[i]);
			i++;
		}
		stock.cpexp[i] = ft_mallocex(spli, stock.cpexp[i]);
		stock.cpexp[i + 1] = NULL;
		free(cpcpexp[i]);
		free(cpcpexp);
}

void	ft_export(char **spli)
{
	int	i;

	i = 0;
	if (!stock.cpexp)
	{
		while(stock.cpenv[i])
			i++;
		stock.cpexp = malloc(sizeof(char *) * (i + 1));
		i = 0;
		while(stock.cpenv[i])
		{
			ft_triexport(stock.cpenv[i]);
			i++;
		}
	}
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
