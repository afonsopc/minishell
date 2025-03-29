/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:34:07 by paude-so          #+#    #+#             */
/*   Updated: 2025/03/29 14:53:11 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_terminal	*terminal(void)
{
	static t_terminal	t;

	return (&t);
}

void	ft_exit(void)
{
	printf("exit\n");
	ft_exit_free();
}

void	ft_exit_free(void)
{
	(close(0), close(1), close(2));
	ft_hashmap_destroy(terminal()->env);
	free_token(terminal()->token);
	exit(terminal()->status);
}
