/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:51:47 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/18 17:11:50 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

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

int	execute(t_cmd *cmd)
{
	pid_t	pid;
	int		ret;

	pid = fork();
	if (!pid)
		(execve(cmd->args[0], cmd->args, NULL), exit(127));
	waitpid(pid, &ret, 0);
	if (WIFEXITED(ret))
		printf("status %d\n", WEXITSTATUS(ret));
	else
		printf("no exit\n");
	return (0);
}
