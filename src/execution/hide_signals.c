/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hide_signals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:33:05 by paude-so          #+#    #+#             */
/*   Updated: 2025/04/04 19:19:19 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <execution.h>

void	toggle_signal_echo(bool hide)
{
	struct termios	terminos_p;

	tcgetattr(STDOUT_FILENO, &terminos_p);
	if (hide)
		terminos_p.c_lflag |= ECHOCTL;
	else
		terminos_p.c_lflag &= ~(ECHOCTL);
	tcsetattr(STDOUT_FILENO, TCSANOW, &terminos_p);
}

static void	handle_signal(int sig)
{
	(void)sig;
	kill_token(terminal()->token);
	rl_replace_line("", 0);
	ft_fputstr(1, "\n");
	terminal()->status = 130;
	rl_on_new_line();
	rl_redisplay();
}

static void	handle_signal_heredoc(int sig)
{
	(void)sig;
	ft_fputstr(1, "\n");
	signal(SIGINT, SIG_DFL);
	close_all_non_standart_fds();
	ft_free_minishell();
	exit(130);
}

void	mask_signals(int type)
{
	if (type != CLEAR)
		mask_signals(CLEAR);
	if (type == PROMPT)
	{
		signal(SIGINT, handle_signal);
		signal(SIGQUIT, SIG_IGN);
	}
	else if (type == PROCESS)
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
	}
	else if (type == HEREDOC)
	{
		signal(SIGINT, handle_signal_heredoc);
		signal(SIGQUIT, SIG_IGN);
	}
	else if (type == CLEAR)
	{
		signal(SIGINT, SIG_DFL);
		signal(SIGQUIT, SIG_DFL);
	}
}
