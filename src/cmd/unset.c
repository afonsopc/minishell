/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:32:38 by paude-so          #+#    #+#             */
/*   Updated: 2025/03/13 12:32:46 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

pid_t	execute_unset(t_cmd *cmd, int in, int out)
{
	size_t	i;

	i = 1;
	while (cmd->args[i])
		hashmap(terminal()->env)->remove_key(cmd->args[i++]);
	ft_close(out);
	ft_close(in);
	return (0);
}
