/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:38:14 by edos-san          #+#    #+#             */
/*   Updated: 2024/12/18 16:47:53 by afpachec         ###   ########.fr       */
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

typedef long long	t_size_ll;

typedef struct s_terminal
{
	void	*env;
}	t_terminal;

typedef struct s_cmd
{
	char	**args;
}	t_cmd;

typedef struct s_token
{
	char			*type;
	char			**args;
	int				balancing;
	struct s_token	*left;
	struct s_token	*right;
}	t_token;

//parse
void		parse(char *line);
// env
void		init_env(char **env);
// terminal
t_terminal	*terminal(void);
void		ft_exit(void);
// execution
int			execute(t_cmd *cmd);
char		*get_command_path(char *cmd);
// cmd
void		free_cmd(t_cmd *cmd);
t_cmd		*new_cmd(char **args);

#endif
