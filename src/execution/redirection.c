/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 16:45:58 by afpachec          #+#    #+#             */
/*   Updated: 2025/03/30 12:05:53 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <execution.h>

static int	get_heredoc(char *terminator)
{
	char	*redirect_in_content;
	int		pipe_fds[2];
	pid_t	pid;

	pipe(pipe_fds);
	pid = fork();
	if (!pid)
	{
		redirect_in_content = redirect_in_loop(terminator);
		ft_fputstr(pipe_fds[1], redirect_in_content);
		free(redirect_in_content);
		ft_close(pipe_fds[1]);
		exit(0);
	}
	ft_close(pipe_fds[1]);
	return (pipe_fds[0]);
}

static int	get_redirect_fd(t_redirect *redirect)
{
	if (ft_strlen(redirect->args[0]) == 2)
	{
		if (redirect->type == IN)
			return (get_heredoc(redirect->args[1]));
		else
			return (open(redirect->args[1],
					O_WRONLY | O_CREAT | O_APPEND, 0644));
	}
	else if (redirect->type == IN)
		return (open(redirect->args[1], O_RDONLY));
	else
		return (open(redirect->args[1], O_WRONLY | O_CREAT | O_TRUNC, 0644));
}

static bool	process_redirection(t_cmd *cmd, t_redirect *redirect)
{
	int		*fd;
	char	*error_prompt;

	if (!cmd || !redirect)
		return (true);
	if (redirect->type == IN)
		fd = &cmd->in;
	else
		fd = &cmd->out;
	ft_close(*fd);
	*fd = get_redirect_fd(redirect);
	if (*fd == -1 && cmd->args[0])
	{
		error_prompt = ft_strjoin("minishell: ", cmd->args[0]);
		perror(error_prompt);
		terminal()->status = 1;
		cmd->loser = true;
		cmd->loser_status = 1;
		return (false);
	}
	return (true && process_redirection(cmd, redirect->next));
}

bool	process_redirections(t_token *token)
{
	bool	bool1;
	bool	bool2;

	if (!token)
		return (true);
	if (token->type != CMD)
	{
		bool1 = process_redirections(token->left);
		bool2 = process_redirections(token->right);
		return (bool1 && bool2);
	}
	return (process_redirection(token->cmd, token->cmd->redirect));
}
