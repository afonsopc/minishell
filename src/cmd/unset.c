/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:32:38 by paude-so          #+#    #+#             */
/*   Updated: 2025/03/29 12:49:16 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

pid_t	execute_unset(t_cmd *cmd)
{
	size_t	i;

	(ft_close(cmd->in), ft_close(cmd->out));
	i = 1;
	while (cmd->args[i])
		hashmap(terminal()->env)->remove_key(cmd->args[i++]);
	terminal()->status = 0;
	return (0);
}
