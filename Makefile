NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror -g # -fsanitize=address
INCLUDES = -I headers -I /opt/homebrew/opt/readline/include -I .brew/opt/readline/include
SRCS =   $(shell find . -type f -name "*.c")
OBJ_DIR = obj/
OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
READLINE_FLAGS = -L /opt/homebrew/opt/readline/lib -lreadline -lncurses -L .brew/opt/readline/lib

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) -o $(NAME) $(OBJS) $(CFLAGS) $(READLINE_FLAGS) $(INCLUDES)

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR) valgrind_log.txt readline.supp

fclean: clean
	@rm -rf $(NAME)

re: fclean all

r: re
	@ clear && ./minishell

v: re readline.supp
	@valgrind --show-leak-kinds=all --leak-check=full --track-fds=all --suppressions=readline.supp ./minishell
vv: $(NAME) readline.supp
	@valgrind --show-leak-kinds=all --leak-check=full --track-fds=all --suppressions=readline.supp ./minishell

test: re
	@git clone https://github.com/LucasKuhn/minishell_tester
	@cd minishell_tester && ./tester && cd ..
	@rm -rf minishell_tester

readline.supp:
	@wget https://raw.githubusercontent.com/benjaminbrassart/minishell/master/readline.supp 2> /dev/null 1> /dev/null

.PHONY: all re clean fclean r v vv readline.supp