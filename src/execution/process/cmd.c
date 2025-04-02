/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 21:24:04 by afpachec          #+#    #+#             */
/*   Updated: 2025/04/01 15:01:41 by paude-so         ###   ########.fr       */
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
	if (token->cmd->loser)
	{
		terminal()->status = token->cmd->loser_status;
		return (ft_close2(in, out), ft_close2(token->cmd->in, token->cmd->out));
	}
	update_fd(&in, token->cmd->in);
	update_fd(&out, token->cmd->out);
	token->cmd->in = in;
	token->cmd->out = out;
	arg_clean(token->cmd);
	if (token->cmd->args && *token->cmd->args)
		token->cmd->args[0] = get_command_path(token->cmd->args [0]);
	if (!token->cmd->execute || !token->cmd->args[0])
		return ;
	token->pid = token->cmd->execute(token->cmd);
}
