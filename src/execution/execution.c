/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:51:47 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/18 15:33:10 by afpachec         ###   ########.fr       */
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

char	*get_command_path(char *command)
{
	char	**path;
	char	*curr;
	size_t	i;

	if (access(command, X_OK) != -1)
		return (command);
	i = -1;
	path = str().split(hashmap(terminal()->env)->get_key("PATH"), ":");
	if (!path)
		return (NULL);
	while (path[++i])
	{
		curr = path_join(path[i], command);
		if (access(curr, X_OK) != -1)
			break ;
		free(curr);
		curr = NULL;
	}
	free_list(path);
	free(command);
	return (curr);
}

int	execute(t_command *cmd)
{
	pid_t	pid;
	int		ret;

	pid = fork();
	if (!pid)
		(execve(cmd->args[0], cmd->args, NULL), exit(127));
	else
		kill(pid, SIGTERM);
	waitpid(pid, &ret, 0);
	printf("status %d %d\n", ret, WEXITSTATUS(ret));
	// if (WIFEXITED(ret))
	// 	printf("status %d\n", WEXITSTATUS(ret));
	// else
	// 	printf("no exit\n");
	return (0);
}
