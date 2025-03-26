/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 21:24:04 by afpachec          #+#    #+#             */
/*   Updated: 2025/03/26 15:52:33 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <execution.h>

void	update_fd(int *fd, int new_fd)
{
	if (new_fd == -2)
		return ;
	ft_close(*fd);
	*fd = new_fd;
}

void	process_cmd(t_token	*token, int in, int out)
{
	update_fd(&in, token->cmd->in);
	update_fd(&out, token->cmd->out);
	process_args_expansions(token->cmd);
	process_wildcards(token->cmd);
	if (!token->cmd->execute || !token->cmd->args[0])
		return ;
	token->pid = fork();
	if (!token->pid)
	{
        if (out != -2)
            dup2(out, STDOUT_FILENO);
        if (in != -2)
            dup2(in, STDIN_FILENO);
	}
	ft_close(in);
	ft_close(out);
	if (!token->pid)
		token->cmd->execute(token->cmd);
}
