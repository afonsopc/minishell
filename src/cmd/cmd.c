/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:36:47 by paude-so          #+#    #+#             */
/*   Updated: 2025/03/29 18:09:23 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <execution.h>

static	void	init_fun(t_cmd	*cmd)
{
	if (ft_strcmp(*cmd->args, "echo") == 0)
		cmd->execute = execute_echo;
	else if (ft_strcmp(*cmd->args, "export") == 0)
		cmd->execute = execute_export;
	else if (ft_strcmp(*cmd->args, "env") == 0)
		cmd->execute = execute_env;
	else if (ft_strcmp(*cmd->args, "unset") == 0)
		cmd->execute = execute_unset;
	else if (ft_strcmp(*cmd->args, "cd") == 0)
		cmd->execute = execute_cd;
	else if (ft_strcmp(*cmd->args, "pwd") == 0)
		cmd->execute = execute_pwd;
	else if (ft_strcmp(*cmd->args, "exit") == 0)
		cmd->execute = execute_exit;
	else
		cmd->execute = execute;
}

t_cmd	*new_cmd(char **args)
{
	t_cmd	*cmd;

	cmd = ft_calloc(1, sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	process_env_assignments(args);
	cmd->args = args;
	init_fun(cmd);
	cmd->in = -2;
	cmd->out = -2;
	return (cmd);
}
