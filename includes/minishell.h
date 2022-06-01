#ifndef MINISHELL_H
#define MINISHELL_H

#include "../lib/libft/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

int     ft_cmd(char *line, char **env);
char    **path_fct(char **env);
char    **path_finish(char **env);
int     verif_exist(char **path, char *argv);
char    **verif_option(char **spli);
void    ft_exit(int x);
void	cmd_echo(char **spli);
void	cmd_cd(char **spli, char **env);
int 	echo_option(char *spli);
char	**ft_cp_env(char **env);
char	**cmd_cd_dot(char **spli);

typedef struct s_stock
{
   	char    **cpenv;
    char    **derive;
    int     test;
}   t_stock;

t_stock stock;

#endif
