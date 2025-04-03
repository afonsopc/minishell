/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hide_signals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:33:05 by paude-so          #+#    #+#             */
/*   Updated: 2025/04/03 18:55:31 by paude-so         ###   ########.fr       */
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
	kill_token(terminal()->token);
	if (sig == SIGINT)
	{
		rl_replace_line("", 0);
		ft_fputstr(1, "\n");
		terminal()->status = 130;
		rl_on_new_line();
	}
	else
		terminal()->status = 131;
	rl_redisplay();
}

static void	handle_signal_heredoc(int sig)
{
	(void)sig;
	ft_fputstr(1, "\n");
	signal(SIGINT, SIG_DFL);
	kill(0, SIGINT);
}

void	mask_signals(int type)
{
	unmask_signals();
	if (type == 0)
	{
		signal(SIGINT, handle_signal);
		signal(SIGQUIT, handle_signal);
	}
	else if (type == 1)
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
	}
	else if (type == 2)
	{
		signal(SIGINT, handle_signal_heredoc);
		signal(SIGQUIT, handle_signal);
	}
}

void	unmask_signals(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}
