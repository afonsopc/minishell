/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:56:03 by afpachec          #+#    #+#             */
/*   Updated: 2025/04/03 14:08:13 by paude-so         ###   ########.fr       */
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

static char	*read_line_with_signals(void)
{
	char	*line;

	toggle_signal_echo(false);
	line = readline("> ");
	toggle_signal_echo(true);
	if (!line)
		ft_exit();
	return (line);
}

static char	*append_line_with_newline(char *lines, char *line)
{
	char	*tmp;

	tmp = lines;
	lines = ft_strjoin(lines, line);
	free(tmp);
	tmp = lines;
	lines = ft_strjoin(lines, "\n");
	free(tmp);
	return (lines);
}

char	*redirect_in_loop(char *terminator)
{
	char	*line;
	char	*lines;

	lines = NULL;
	mask_signals(2);
	while (1)
	{
		line = read_line_with_signals();
		if (ft_strcmp(line, terminator) == 0)
		{
			free(line);
			break ;
		}
		lines = append_line_with_newline(lines, line);
		free(line);
	}
	return (lines);
}
