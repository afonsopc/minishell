/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_clean.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 13:30:29 by paude-so          #+#    #+#             */
/*   Updated: 2025/03/22 15:07:47 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <execution.h>

void	arg_clean(t_cmd *cmd)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!cmd->args)
		return ;
	while (cmd->args[i])
	{
		if (cmd->args[i][0])
			cmd->args[j++] = cmd->args[i];
		else
			free(cmd->args[i]);
		i++;
	}
	cmd->args[j] = NULL;
}
