/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_clean.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 13:30:29 by paude-so          #+#    #+#             */
/*   Updated: 2025/03/22 13:45:03 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <execution.h>

void	arg_clean(t_cmd *cmd)
{
	if (!cmd->args || !cmd->args[0] || cmd->args[0][0])
		return ;
	printf("args[0] = %s\n", cmd->args[0]);
	free(cmd->args[0]);
	++cmd->args;
	arg_clean(cmd);
}
