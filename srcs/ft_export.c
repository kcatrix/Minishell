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
		i++;
	i--;
	while ((i >= 0 && ft_isdigit(line[i]) == 1) || ( i >= 0 && line[i] == '_'))
		i--;
	if(i == -1)
		return (1);
	while ((i >= 0 && ft_isalpha(line[i]) == 1 ) || ( i >= 0 && line[i] == '_'))
		i--;
	if (i == -1)
		return (0);
	return (1);
}

int	ft_verifenv(char *spli)
{
	int	i;

	i = 0;
	while(stock.cpenv[i])
	{
		if (ft_strcmp(ft_preline(spli), ft_preline(stock.cpenv[i])) == 0)
		{
			free(stock.cpenv[i]);
			stock.cpenv[i] = ft_mallocex(spli, stock.cpenv[i]);
			i = 0;
			while (stock.cpexp[i])
			{
				if (ft_strcmp(ft_preline(spli), ft_preline(stock.cpexp[i])) == 0)
				{
					free(stock.cpexp[i]);
					stock.cpexp[i] = ft_mallocex(spli, stock.cpexp[i]);
				}
				i++;
			}
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
		free(stock.cpexp[i]);
		i++;
	}
	cpcpenv[i] = NULL;
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
	
	if (str == NULL)
		return(str);
	str2 = malloc(sizeof(char) * (ft_strlen(str) + 1));
	printf("oerkgokegr\n");
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
			y = 1;
			while(spli[++i])
			{
				if(spli[i] != 22 && spli[i] != '\0')
					y = 1;
			}
		}
		i++;
	}
	return (y);
}
int	ft_verifdoublon(char *spli)
{
	int	i;

	i = 0;
	printf("kukuku\n");
	while(stock.cpexp[i])
	{
		if (strcmp(ft_preline(spli), ft_preline(stock.cpexp[i])) == 0)
		{
			printf("oui\n");
			if (ft_verifspli(spli) != 0)
				stock.cpexp[i] = ft_mallocex(spli, stock.cpexp[i]);
			return (0);
		}
		printf("non\n");
		i++;
	}
	return (1);
}

 char	**ft_exptoenv2(void)
{
	int		i;
	int		y;
	char	**cpcpenv;

	i = 0;
	y = 0;
	printf("AAAaaaaaaAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n");
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
		cpcpenv[i][y] = '\0';
		y = 0;
		free(stock.cpenv[i]);
		i++;
	}
	cpcpenv[i] = NULL;
	free(stock.cpenv);
	stock.cpenv = malloc(sizeof(char *) * (i + 2));
	return (cpcpenv);
}

 void	ft_exptoenv(char *spli)
 {
	 char 	**cpcpenv;
	 int	i;

	 i = 0;
	 cpcpenv = ft_exptoenv2();
	 while (cpcpenv[i])
	 {
		stock.cpenv[i] = ft_mallocex(cpcpenv[i], stock.cpenv[i]);
		i++;
	 }
	 stock.cpenv[i] = ft_mallocex(spli, stock.cpenv[i]);
	 stock.cpenv[i + 1] = NULL;
	 printf("AAAaaaaaaAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n");
	 return ;
 }

void	ft_exportadd(int i, char *spli)
{
	char 	**cpcpexp;
	int		y;
	int 	z;

	y = 0;
	z = 0;
	printf("avantverifdoublon\n");
	if (ft_verifdoublon(spli) == 0)
	{
		printf("verifdoublon\n");
		return ;
	}
	printf("ufdp\n");
	cpcpexp = ft_mallocexportadd();
	ft_exptoenv(spli);
	printf("ufdp\n");
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
	printf("debutexport\n");
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
		{
			printf("parseexport\n");
			return;
		}
		else if (ft_verifenv(spli[1]) == 1)
		{
			printf("verifnev\n");
			return;
		}
		printf("preadd\n");
		ft_exportadd(i, spli[1]);
	}
}
