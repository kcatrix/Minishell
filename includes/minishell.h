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

typedef struct s_stock
{
    char    **paramenv;
    char    **derive;
    int     test;
}   t_stock;

t_stock stock;

#endif
