/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:51:47 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/23 14:01:18 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

pid_t	execute(t_cmd *cmd, int in, int out)
{
	pid_t	pid;

	pid = fork();
	if (!pid)
	{
		dup2(in, 0);
		dup2(out, 1);
		execve(cmd->args[0], cmd->args, hashmap(terminal()->env)->to_array());
		exit(127);
	}
	return (pid);
}
