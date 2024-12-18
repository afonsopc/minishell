/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:38:14 by edos-san          #+#    #+#             */
/*   Updated: 2024/12/17 23:27:08 by afpachec         ###   ########.fr       */
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

typedef struct s_terminal
{
	void	*env;
}	t_terminal;

typedef struct s_command
{
	char	*path;
	char	**args;
}	t_command;

//parse
void		parse(char *line);
// env
void		init_env(char **env);
// terminal
t_terminal	*terminal(void);
void		ft_exit();
// execution
int			execute(t_command *command);
char		*get_command_path(char *command);

#endif
