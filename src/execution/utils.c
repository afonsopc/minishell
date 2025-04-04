/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 21:29:50 by afpachec          #+#    #+#             */
/*   Updated: 2025/04/04 19:13:41 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <execution.h>

char	*path_join(char *str1, char *str2)
{
	char	*tmp;
	char	*final;

	tmp = ft_strjoin(str1, "/");
	if (!tmp)
		return (NULL);
	final = ft_strjoin(tmp, str2);
	free(tmp);
	return (final);
}

char	*get_command_path(char *cmd)
{
	char	**path;
	char	*curr;
	size_t	i;

	if (!cmd[0] || access(cmd, X_OK) != -1)
		return (cmd);
	i = -1;
	if (!ft_hashmap_get_value(terminal()->env, "PATH"))
		return (cmd);
	path = ft_split(ft_hashmap_get_value(terminal()->env, "PATH"), ":");
	if (!path)
		return (cmd);
	while (path[++i])
	{
		curr = path_join(path[i], cmd);
		if (access(curr, X_OK) != -1)
			break ;
		free(curr);
		curr = NULL;
	}
	ft_strvfree(path);
	if (curr == NULL)
		return (cmd);
	return (free(cmd), curr);
}

void	wait_token(t_token *token)
{
	pid_t		ret;

	if (token->type != CMD)
		(wait_token(token->left), wait_token(token->right));
	if (!token->pid)
		return ;
	waitpid(token->pid, &ret, 0);
	terminal()->status = WEXITSTATUS(ret);
	if (WTERMSIG(ret) == SIGINT)
		terminal()->status = 130;
	if (WTERMSIG(ret) == SIGQUIT)
		terminal()->status = 131;
	token->pid = 0;
}

void	free_cmd(t_cmd *cmd)
{
	if (!cmd)
		return ;
	ft_strvfree(cmd->args);
	free_redirect(cmd->redirect);
	free(cmd);
}

char	*get_cwd(void)
{
	char	buff[70000];

	return (ft_strdup(getcwd(buff, 70000)));
}
