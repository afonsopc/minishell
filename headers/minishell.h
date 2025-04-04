/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 20:38:14 by paude-so          #+#    #+#             */
/*   Updated: 2025/04/04 19:04:52 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <dirent.h>
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <ft_utils.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <termios.h>
# include <unistd.h>

typedef enum e_cmd_type
{
	CMD,
	PIPE,
	OR,
	AND
}						t_cmd_type;

typedef enum e_redirect_type
{
	IN,
	OUT
}						t_redirect_type;

typedef struct s_redirect
{
	t_redirect_type		type;
	char				**args;
	struct s_redirect	*next;
}						t_redirect;

typedef struct s_cmd
{
	char				**args;
	pid_t				(*execute)(struct s_cmd * cmd);
	int					in;
	int					out;
	bool				loser;
	int					loser_status;
	t_redirect			*redirect;
}						t_cmd;

typedef struct s_token
{
	t_cmd_type			type;
	t_cmd				*cmd;
	struct s_token		*left;
	struct s_token		*right;
	pid_t				pid;
}						t_token;

typedef struct s_terminal
{
	char				*pagman;
	t_hashmap			*env;
	void				*new_env;
	t_token				*token;
	int					status;
	struct sigaction	sa;
}						t_terminal;

typedef struct s_lexer
{
	char				*input;
	size_t				pos;
	size_t				len;
	char				curr_char;
}						t_lexer;

// lexer
t_lexer					*init_lexer(char *input);
void					advance_lexer(t_lexer *lexer);
void					skip_whitespace(t_lexer *lexer);
char					*read_operator(t_lexer *lexer);
char					*read_redirection(t_lexer *lexer);
char					*read_single_quote(t_lexer *lexer);
char					*read_double_quote(t_lexer *lexer);
bool					can_move(char *quote, char curr);

// parse
int						is_redirection(char *token);
t_redirect				*create_redirection(char **tokens, size_t *pos);
void					add_redirection(t_cmd *cmd, t_redirect *new_redirect);
t_token					*parse_simple_command(char **tokens, size_t *pos);
t_token					*parse_pipe(char **tokens, size_t *pos);
t_token					*parse_and_or(char **tokens, size_t *pos);
t_token					*parse(char *line);

// token
char					**tokenize(char *input);
bool					free_token(t_token *token);
void					free_redirect(t_redirect *r);
t_token					*new_token(char *type, t_cmd *cmd);

// env
void					init_env(char **env);
void					process_env_assignments(char **args);
char					*process_arg_expansions(char *arg, int *exit_status);
char					*expand_variables_in_string(char *str, int *ext_sts);

// terminal
t_terminal				*terminal(void);
void					ft_exit(void);
void					ft_free_minishell(void);
void					ft_exit_free(void);

// execution
char					*get_command_path(char *cmd);
void					process_token(t_token *token);
void					loop(void);

// cmd
void					free_cmd(t_cmd *cmd);
t_cmd					*new_cmd(char **args);

#endif
