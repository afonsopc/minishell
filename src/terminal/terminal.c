/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:34:07 by paude-so          #+#    #+#             */
/*   Updated: 2025/03/23 11:28:53 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_exit(void)
{
	printf("exit\n");
	ft_exit_free();
}

void	ft_exit_free(void)
{
	hashmap(terminal()->env)->destroy();
	free_token(terminal()->token);
	exit(terminal()->status);
}
