/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:34:07 by paude-so          #+#    #+#             */
/*   Updated: 2025/04/04 19:32:37 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <execution.h>

t_terminal	*terminal(void)
{
	static t_terminal	t;

	return (&t);
}

void	ft_exit(void)
{
	ft_fputstr(1, "exit\n");
	ft_exit_free();
}

void	ft_free_minishell(void)
{
	(close(0), close(1), close(2));
	ft_hashmap_destroy(terminal()->env);
	free_token(terminal()->token);
	close_all_non_standart_fds();
	free(terminal()->pagman);
}

void	ft_exit_free(void)
{
	ft_free_minishell();
	exit(terminal()->status);
}
