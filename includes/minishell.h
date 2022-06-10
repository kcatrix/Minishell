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
char    *getpwd(void);
void	cmd_cd(char **spli, char **env);
int 	echo_option(char *spli);
char	**ft_cp_env(char **env);
char	**cmd_cd_dot(void);
char    *ft_chk_last_path(char *pwd);
void    cmd_cd_dot_dot(void);
void    cmd_cd_relative_pwd(char *spli);
int     verifpwd(char *spli);
void    cmd_cd_absolute_pwd(char *spli);
void    cmd_cd_relative(char *spli);
void    cmd_cd_absolute(char *spli);
void    cmd_cd_absolute_redirect(char *spli);
void    cmd_cd_pwd(char *home);
void    cmd_cd_noarg(void);
char    **parse(char **spli);
char	*cmd_dollar(char *str);
void	ft_export(char **spli);
void	ft_pwd(void);
void	ft_env(void);
void    free_spli(char **spli);

typedef struct s_stock
{
   	char    **cpenv;
    char    **derive;
    int     test;
}   t_stock;

t_stock stock;

#endif
