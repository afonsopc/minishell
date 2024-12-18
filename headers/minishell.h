/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:38:14 by edos-san          #+#    #+#             */
/*   Updated: 2024/12/18 15:18:26 by edos-san         ###   ########.fr       */
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

#endif
