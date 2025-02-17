/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 21:29:50 by afpachec          #+#    #+#             */
/*   Updated: 2025/02/16 23:50:01 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <execution.h>

char	*path_join(char *str1, char *str2)
{
	char	*tmp;
	char	*final;

	tmp = str().join(str1, "/");
	if (!tmp)
		return (NULL);
	final = str().join(tmp, str2);
	free(tmp);
	return (final);
}

char	*get_command_path(char *cmd)
{
	char	**path;
	char	*curr;
	size_t	i;

	if (access(cmd, X_OK) != -1)
		return (cmd);
	i = -1;
	if (!hashmap(terminal()->env)->get_key("PATH"))
		return (cmd);
	path = str().split(hashmap(terminal()->env)->get_key("PATH"), ":");
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
	free_list(path);
	if (curr == NULL)
		return (cmd);
	return (free(cmd), curr);
}

void	wait_token(t_token *token)
{
	int		ret;

	if (token->type != CMD)
		(wait_token(token->left), wait_token(token->right));
	if (!token->pid)
		return ;
	waitpid(token->pid, &ret, 0);
	terminal()->status = WEXITSTATUS(ret);
	if (!WIFEXITED(ret))
		terminal()->status = 130;
	token->pid = 0;
}

void	free_cmd(t_cmd *cmd)
{
	if (!cmd)
		return ;
	free_list(cmd->args);
	free_redirect(cmd->redirect);
	free(cmd);
}

char	*get_cwd(void)
{
	char	buff[70000];

	return (str().copy(getcwd(buff, 70000)));
}
