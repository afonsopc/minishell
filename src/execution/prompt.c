/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:56:03 by afpachec          #+#    #+#             */
/*   Updated: 2025/01/28 00:14:49 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <execution.h>

void	loop(void)
{
	char	*line;

	while (1)
	{
		mask_signals();
		line = readline("minishell$ ");
		if (!line)
			ft_exit();
		if (str().size(line))
			add_history(line);
		terminal()->token = parse(line);
		process_token(terminal()->token);
		free(line);
	}
}

char	*redirect_in_loop(char *terminator)
{
	char	*line;
	char	*lines;
	char	*tmp;

	lines = NULL;
	unmask_signals();
	while (1)
	{
		line = readline("> ");
		if (!line)
			ft_exit();
		if (str().equals(line, terminator))
		{
			free(line);
			break ;
		}
		tmp = lines;
		lines = str().join(lines, line);
		free(tmp);
		tmp = lines;
		lines = str().join(lines, "\n");
		free(tmp);
		free(line);
	}
	return (lines);
}

void	handle_signal(int sig)
{
	if (sig == SIGINT)
	{
		kill_token(terminal()->token);
		rl_replace_line("", 0);
		printf("\n");
		rl_on_new_line();
	}
	rl_redisplay();
}

void	mask_signals(void)
{
	signal(SIGINT, handle_signal);
	signal(SIGQUIT, handle_signal);
}

void	unmask_signals(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}
