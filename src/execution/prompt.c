/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:56:03 by afpachec          #+#    #+#             */
/*   Updated: 2025/04/01 16:43:42 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <execution.h>

void	loop(void)
{
	char	*line;

	while (1)
	{
		mask_signals(0);
		toggle_signal_echo(false);
		line = readline("minishell$ ");
		toggle_signal_echo(true);
		if (!line)
			ft_exit();
		if (ft_strlen(line))
			add_history(line);
		terminal()->token = parse(line);
		mask_signals(1);
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
	mask_signals(2);
	while (1)
	{
		toggle_signal_echo(false);
		line = readline("> ");
		toggle_signal_echo(true);
		if (!line)
			ft_exit();
		if (ft_strcmp(line, terminator) == 0)
		{
			free(line);
			break ;
		}
		tmp = lines;
		lines = ft_strjoin(lines, line);
		free(tmp);
		tmp = lines;
		lines = ft_strjoin(lines, "\n");
		free(tmp);
		free(line);
	}
	return (lines);
}

void	handle_signal(int sig)
{
	kill_token(terminal()->token);
	rl_replace_line("", 0);
	if (sig == SIGINT)
	{
		ft_fputstr(1, "\n");
		terminal()->status = 130;
	}
	else
		terminal()->status = 131;
	rl_on_new_line();
	rl_redisplay();
}

void	mask_signals(int type)
{
	unmask_signals();
	if (type == 1)
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
	}
	else if (type == 2)
		signal(SIGQUIT, handle_signal);
	else
	{
		signal(SIGINT, handle_signal);
		signal(SIGQUIT, handle_signal);
	}
}

void	unmask_signals(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}
