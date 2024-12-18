/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:32:09 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/18 16:35:47 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_cmd	*new_cmd(char **args)
{
	t_cmd	*cmd;

	cmd = ft_calloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->args = args;
	cmd->args[0] = get_command_path(str().copy(args[0]));
	return (cmd);
}

void	free_cmd(t_cmd *cmd)
{
	if (!cmd)
		return ;
	free_list(cmd->args);
	free(cmd);
}
