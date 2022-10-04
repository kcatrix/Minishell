# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kcatrix <kcatrix@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/07 21:50:04 by tnicoue           #+#    #+#              #
#    Updated: 2022/10/04 14:39:28 by kcatrix          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = Minishell

CC = gcc

OBJECTS	= ./bin
 
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address

SRCS = main.c ft_cmd.c ft_cd_and_echo.c parse.c \
		ft_export.c ft_pwd.c ft_env.c ft_chevron.c \
		signal.c ft_chevron2.c ft_cd_and_echo2.c \
		ft_cd_and_echo3.c ft_chevron3.c ft_cmd2.c \
		ft_export2.c ft_export3.c ft_export4.c parse2.c \
		ft_cmd3.c ft_export5.c parse.3.c pipe.c ft_cmd4.c \
		ft_cd_and_echo4.c ft_split_pipe.c ft_split_pipe2.c \
		pipe2.c pipe3.c ft_export6.c ft_cd_end_echo5.c \
		ft_cd_and_echo6.c ft_cd_and_echo7.c parse4.c
		
RM = rm -f

ifndef BONUS
SOURCES	= ./srcs/
OBJS	= $(addprefix $(SOURCES),$(SRCS:.c=.o))
else
SOURCES	= ./srcs_bonus
OBJS	= $(SRCS_BONUS:.c=.o)
endif

LIBPATH = ./lib/libft/libft.a

all: ${NAME}

bonus:
	@echo "\033[1;32m""Compilation de ${NAME}..."
	@make BONUS=1 ${NAME}

${NAME}: ${OBJS}
		@echo "\033[1;36m""Compilation de ${NAME}..."
	   	@$(MAKE) -j -s --no-print-directory -C lib/libft
		$(CC) $(LIBPATH) $(OBJS) $(CFLAGS) libreadline.a -lreadline -lncurses -o $(NAME)

${OBJECTS}/%.o: ${SOURCES}/%.c
	@echo "Compilation de ${notdir $<}."
	@$(CC) $(CFLAGS) -Imlx -c $< -o $@

clean :
		@echo "\033[1;32m""Supression des fichiers binaires (.o)..."
	   	@$(MAKE) -s --no-print-directory -C lib/libft/ clean
		${RM} ${OBJS}

fclean: clean
		@echo "\033[1;32m""Supression des executables et librairies..."
		@$(MAKE) -s --no-print-directory -C lib/libft/ fclean
		${RM} ${NAME}
		${RM} *.out
		
re: fclean all
	@echo "\033[0m"

.PHONY: all clean fclean re

