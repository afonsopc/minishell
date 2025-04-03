/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hide_signals.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:33:05 by paude-so          #+#    #+#             */
/*   Updated: 2025/04/03 14:07:53 by paude-so         ###   ########.fr       */
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
