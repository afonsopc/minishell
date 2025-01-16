/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:45:58 by afpachec          #+#    #+#             */
/*   Updated: 2025/01/09 18:38:49 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <execution.h>

static int	get_redirect_fd(t_redirect *redirect)
{
	if (redirect->type == IN)
		return (open(redirect->args[1], O_RDONLY));
	if (str().size(redirect->args[0]) == 2)
		return (open(redirect->args[1], O_WRONLY | O_CREAT | O_APPEND, 0644));
	return (open(redirect->args[1], O_WRONLY | O_CREAT, 0644));
}

static void	process_redirection(t_cmd *cmd, t_redirect *redirect)
{
	int	*fd;

	if (!cmd || !redirect)
		return ;
	if (redirect->type == IN)
		fd = &cmd->in;
	else
		fd = &cmd->out;
	ft_close(*fd);
	*fd = get_redirect_fd(redirect);
	if (*fd == -1 && cmd->args[0])
	{
		(str().fputstr)(2, redirect->args[1]);
		(str().fputstr)(2, ": ");
		(str().fputstr)(2, strerror(errno));
		(str().fputstr)(2, "\n");
		terminal()->status = 1;
	}
	process_redirection(cmd, redirect->next);
}

// TODO: o doc cenas é quando o redirect é 2 pra esquerda e o argumento é o terminator do doc

void	process_redirections(t_token *token)
{
	if (!token)
		return ;
	process_redirections(token->left);
	process_redirections(token->right);
	if (token->type != CMD)
		return ;
	process_redirection(token->cmd, token->cmd->redirect);
}
