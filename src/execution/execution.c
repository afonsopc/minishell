/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:51:47 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/19 21:57:06 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

pid_t	execute(t_cmd *cmd, int fds[2])
{
	pid_t	pid;

	pid = fork();
	if (!pid)
	{
		dup2(fds[0], 0);
		dup2(fds[1], 1);
		execve(cmd->args[0], cmd->args, NULL);
		exit(127);
	}
	return (pid);
}
