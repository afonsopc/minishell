/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:32:38 by paude-so          #+#    #+#             */
/*   Updated: 2025/03/29 15:20:15 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

pid_t	execute_unset(t_cmd *cmd)
{
	size_t	i;

	ft_close2(cmd->in, cmd->out);
	i = 1;
	while (cmd->args[i])
		ft_hashmap_del(terminal()->env, cmd->args[i++]);
	terminal()->status = 0;
	return (0);
}
