# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tnicoue <tnicoue@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/07 21:50:04 by tnicoue           #+#    #+#              #
#    Updated: 2022/06/10 15:04:46 by kevyn            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = Minishell

CC = gcc

OBJECTS	= ./bin
 
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address

SRCS = main.c ft_cmd.c ft_cd_and_echo.c parse.c ft_export.c ft_pwd.c ft_env.c

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

