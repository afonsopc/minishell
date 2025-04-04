/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 21:29:50 by afpachec          #+#    #+#             */
/*   Updated: 2025/04/04 20:01:09 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <execution.h>

char	*get_curr_dir(void)
{
	char	*cwd;
	char	**dirs;
	char	*curr_dir;

	cwd = get_cwd();
	dirs = ft_split(cwd, "/");
	curr_dir = ft_strdup(dirs[ft_strvlen(dirs) - 1]);
	(free(cwd), ft_strvfree(dirs));
	return (curr_dir);
}

void	kill_token(t_token *token)
{
	int		ret;

	if (!token)
		return ;
	if (token->type != CMD)
		(kill_token(token->left), kill_token(token->right));
	if (!token->pid)
		return ;
	ret = kill(token->pid, SIGINT);
	terminal()->status = WEXITSTATUS(ret);
	if (!WIFEXITED(ret))
		terminal()->status = 130;
	token->pid = 0;
}

void	close_all_non_standart_fds(void)
{
	int	fd;

	fd = 2;
	while (++fd <= FOPEN_MAX)
		ft_close(fd);
}

void	free_redirect(t_redirect *r)
{
	if (!r)
		return ;
	free_redirect(r->next);
	ft_strvfree(r->args);
	free(r);
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
