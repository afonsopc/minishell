/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:56:03 by afpachec          #+#    #+#             */
/*   Updated: 2025/01/09 02:57:17 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <execution.h>

char	*get_prompt(void);

static char	*prompt(void)
{
	char	*prompt_str;
	char	*line;

	prompt_str = get_prompt();
	line = readline(prompt_str);
	(free(prompt_str));
	return (line);
}

void	loop(void)
{
	char	*line;

	mask_signals();
	while (1)
	{
		line = prompt();
		if (!line)
			break ;
		if (str().size(line))
			add_history(line);
		process_token(parse(line));
		free(line);
	}
}

void	handle_signal(int sig)
{
	if (sig == SIGINT)
	{
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

// TODO: A biblioteca da str() pode ter uma lista global com
// todas as strings que foram alocadas para que caso algum malloc
// falhe sejam todas libertadas antes de fechar.