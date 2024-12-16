NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address,undefined
INCLUDES = -I headers
SRCS =   $(shell find . -type f -name "*.c")
OBJS = 	$(SRCS:.c=.o)
READLINE_FLAGS = -lreadline -lncurses -L .brew/opt/readline/lib -I .brew/opt/readline/include

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) -o $(NAME) $(OBJS) $(CFLAGS) $(READLINE_FLAGS)  $(INCLUDES)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@

$(LIBFT):
	@make -s -C $(LIBFT_DIR)

clean:
	@rm -rf $(OBJ_DIR) valgrind_log.txt readline.supp $(NAME).dSYM .vscode

fclean: clean
	@rm -rf $(NAME)

re: fclean all

r: re
	@ ./minishell

v: re readline.supp
	@valgrind --show-leak-kinds=all --leak-check=full --track-fds=all --suppressions=readline.supp ./minishell
vv: $(NAME) readline.supp
	@valgrind --show-leak-kinds=all --leak-check=full --track-fds=all --suppressions=readline.supp ./minishell

readline.supp:
	@wget https://raw.githubusercontent.com/benjaminbrassart/minishell/master/readline.supp 2> /dev/null 1> /dev/null

.PHONY: all re clean fclean r v vv readline.supp