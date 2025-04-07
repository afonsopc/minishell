NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I headers -I /opt/homebrew/opt/readline/include
SRCS = src/cmd/cd.c \
	   src/cmd/cmd.c \
	   src/cmd/echo.c \
	   src/cmd/env.c \
	   src/cmd/exit.c \
	   src/cmd/pwd.c \
	   src/cmd/unset.c \
	   src/cmd/export.c \
	   src/execution/process/and.c \
	   src/execution/process/or.c \
	   src/execution/process/cmd.c \
	   src/execution/process/pipe.c \
	   src/execution/process/process.c \
	   src/execution/cool_prompt.c \
	   src/execution/arg_clean.c \
	   src/execution/hide_signals.c \
	   src/execution/arg_expansion.c \
	   src/execution/arg_expansion_helper.c \
	   src/execution/execution.c \
	   src/execution/process_redirections.c \
	   src/execution/prompt.c \
	   src/execution/redirection.c \
	   src/execution/utils.c \
	   src/execution/utils2.c \
	   src/parse/env_var_creat.c \
	   src/parse/lexer.c \
	   src/parse/lexer_read.c \
	   src/parse/lexer_utils.c \
	   src/parse/parser.c \
	   src/parse/parser_cmd.c \
	   src/parse/parser_ops.c \
	   src/parse/token.c \
	   src/terminal/terminal.c \
	   src/env/env_create.c \
	   src/main.c \
	   src/utils/utils1.c \
	   src/utils/utils10.c \
	   src/utils/utils11.c \
	   src/utils/utils2.c \
	   src/utils/utils3.c \
	   src/utils/utils4.c \
	   src/utils/utils5.c \
	   src/utils/utils6.c \
	   src/utils/utils7.c \
	   src/utils/utils8.c \
	   src/utils/utils9.c
OBJ_DIR = obj/
OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))
READLINE_FLAGS = -L /opt/homebrew/opt/readline/lib -lreadline -lncurses

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) -o $(NAME) $(OBJS) $(CFLAGS) $(READLINE_FLAGS) $(INCLUDES)

$(OBJ_DIR)%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

r: re
	@ clear && ./minishell

v: re
	@valgrind --show-leak-kinds=all --leak-check=full --track-fds=all --suppressions=$(PWD)/readline.supp ./minishell

test: re
	@git clone https://github.com/LucasKuhn/minishell_tester
	@cd minishell_tester && (./tester || true) && cd ..
	@rm -rf minishell_tester

.PHONY: all re clean fclean r v readline.supp
