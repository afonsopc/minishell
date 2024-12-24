/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:56:03 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/24 14:39:10 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

static char	*prompt(void)
{
	char	*s1;
	char	*s2;
	char	*s3;
	char	*line;

	if (terminal()->status == 0)
		return (readline("[mini@shell]: "));
	s1 = str().itoa(terminal()->status);
	if (!s1)
		return (NULL);
	s2 = str().join("[mini@shell [", s1);
	if (!s2)
		return (free(s1), NULL);
	s3 = str().join(s2, "]]: ");
	if (!s3)
		return (free(s1), free(s2), NULL);
	line = readline(s3);
	(free(s1), free(s2), free(s3));
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
