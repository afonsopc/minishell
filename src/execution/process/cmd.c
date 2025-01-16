/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 21:24:04 by afpachec          #+#    #+#             */
/*   Updated: 2025/01/09 18:33:50 by afpachec         ###   ########.fr       */
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
	if (token->cmd->execute)
		token->pid = token->cmd->execute(token->cmd, in, out);
}
