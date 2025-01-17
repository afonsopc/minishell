/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:51:47 by afpachec          #+#    #+#             */
/*   Updated: 2025/01/17 18:06:38 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <execution.h>

pid_t	execute(t_cmd *cmd, int in, int out)
{
	pid_t	pid;

	pid = fork();
	if (!pid)
		(dup2(in, 0), dup2(out, 1));
	ft_close(in);
	ft_close(out);
	if (pid)
		return (pid);
	unmask_signals();
	execve(cmd->args[0], cmd->args, hashmap(terminal()->env)->to_array());
	exit(127);
}
