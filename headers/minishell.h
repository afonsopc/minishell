/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:38:14 by edos-san          #+#    #+#             */
/*   Updated: 2024/12/23 14:22:50 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "ft_util.h"
# include "ft_string.h"
# include <stdbool.h>
# include <errno.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <termios.h>

typedef long long		t_size_ll;
typedef struct s_token	t_token;

typedef enum e_cmd_type
{
	CMD,
	PIPE,
	OR,
	AND
}	t_cmd_type;

typedef enum	e_redirect_type
{
	IN,
	OUT
} t_redirect_type;

typedef struct s_terminal
{
	void	*env;
	t_token	*token;
	int		status;
}	t_terminal;

typedef struct s_redirect
{
	t_redirect_type		type;
	char				**args;
	struct s_redirect	*next;
}	t_redirect;

typedef struct s_cmd
{
	char		**args;
	t_redirect	*redirect;
}	t_cmd;

struct s_token
{
	t_cmd_type		type;
	t_cmd			*cmd;
	int				balancing;
	struct s_token	*left;
	struct s_token	*right;
	pid_t	pid;
};

//parse
t_token		*parse(char *line);
bool		free_token(t_token *token);
void		free_redirect(t_redirect *r);
// env
void		init_env(char **env);
// terminal
t_terminal	*terminal(void);
void		ft_exit(void);
// execution
char		*get_command_path(char *cmd);
void		process_token(t_token	*token);
// cmd
void		free_cmd(t_cmd *cmd);
t_cmd		*new_cmd(char **args);
//utils
void		print_list(char **args);

#endif
