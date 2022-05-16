################################# COLORS ######################################
# This is a minimal set of ANSI/VT100 color codes
_END=$'\x1b[0m'
_BOLD=$'\x1b[1m'
_UNDER=$'\x1b[4m'
_REV=$'\x1b[7m'

# Colors
_GREY=$'\x1b[30m'
_RED=$'\x1b[31m'
_GREEN=$'\x1b[32m'
_YELLOW=$'\x1b[33m'
_BLUE=$'\x1b[34m'
_PURPLE=$'\x1b[35m'
_CYAN=$'\x1b[36m'
_WHITE=$'\x1b[37m'

# Inverted, i.e. colored backgrounds
_IGREY=$'\x1b[40m'
_IRED=$'\x1b[41m'
_IGREEN=$'\x1b[42m'
_IYELLOW=$'\x1b[43m'
_IBLUE=$'\x1b[44m'
_IPURPLE=$'\x1b[45m'
_ICYAN=$'\x1b[46m'
_IWHITE=$'\x1b[47m'

############################# PARAMETERS ######################################
NAME_PROG		= minishell

NAME_BONUS		= minishell_bonus

SRCS_DIR		= ./srcs/

OBJS_DIR		= ./objs/

FILES_COMMON	= ft_minishell.c

FILES_PROG		= $(FILES_COMMON)

FILES_BONUS		= ft_minishell_bonus.c $(FILES_COMMON)

#testpull

SRCS			= $(addprefix $(SRCS_DIR),$(FILES_PROG))
OBJS			= $(addprefix $(OBJS_DIR),$(FILES_PROG:.c=.o))
SRCS_BONUS		= $(addprefix $(SRCS_DIR),$(FILES_BONUS))
OBJS_BONUS		= $(addprefix $(OBJS_DIR),$(FILES_BONUS:.c=.o))

ifdef BONUS_FLAG
	SRCS_COMP = $(SRCS_BONUS)
	NAME = $(NAME_BONUS)
	OBJS_COMP = $(OBJS_BONUS)
else
	SRCS_COMP = $(SRCS)
	NAME = $(NAME_PROG)
	OBJS_COMP = $(OBJS)
endif

INCLUDES_DIR	= ./includes/

CC				= gcc

CFLAGS			= -Wall -Werror -Wextra
// -g -fsanitize=address

############################## RULES #########################################
all		: $(NAME)

$(OBJS_DIR)%.o		:$(SRCS_DIR)%.c
	$(CC) $(CFLAGS) -I$(INCLUDES_DIR) -c $< -o $@

$(NAME)	: $(OBJS_COMP)
	$(CC) $(OBJS_COMP) $(CFLAGS) -o $(NAME) -I $(INCLUDES_DIR)
	clear
	@echo "$(_GREEN)Compilation is done !$(_WHITE)"

bonus	: 
	@make BONUS_FLAG=1 all 

norme	:
	cd srcs
	norminette -R CheckForbiddenSourceHeader | grep -v OK

debug	: fclean
	$(CC) -g $(SRCS) $(CFLAGS) -o $(NAME)_debug -I$(INCLUDES_DIR)
	lldb $(NAME)_debug

run		: fclean all
	@./pipex file1 cmd1 cmd2 file2

test	:
	clear
	@echo "########### pipex : test without argument ##########################"
	@./pipex
	@echo "########### same test with | (pipe) ################################"
	@echo "zsh: parse error near \`|'"

clean	:
	rm -f $(OBJS)
	rm -f $(OBJS_BONUS)
	@echo "$(_GREEN)Objects cleaned !$(_WHITE)"

fclean	: clean
	rm -f $(NAME_PROG)
	rm -f $(NAME_BONUS)
	clear
	@echo "$(_GREEN)All cleaned !$(_WHITE)"

re		: fclean all

.PHONY	: all bonus clean debug fclean norme run re test
