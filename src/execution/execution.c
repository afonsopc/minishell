/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:51:47 by afpachec          #+#    #+#             */
/*   Updated: 2025/01/27 22:31:31 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <execution.h>

bool	is_directory(char *path)
{
	DIR	*dir;

	dir = opendir(path);
	if (dir)
	{
		closedir(dir);
		return (true);
	}
	return (false);
}

char	*handle_contains_slash(struct stat stat_struct, char *path)
{
	terminal()->status = 126;
	if (is_directory(path))
		return (str().copy(": Is a directory\n"));
	else if (stat(path, &stat_struct) == -1)
	{
		terminal()->status = 127;
		return (str().copy(": No such file or directory\n"));
	}
	else if (access(path, X_OK) == -1)
		return (str().copy(": Permission denied\n"));
	terminal()->status = 0;
	return (NULL);
}

char	*handle_doesnt_contain_slash(struct stat stat_struct, char *path)
{
	terminal()->status = 127;
	if (is_directory(path) || access(path, X_OK) == -1)
		return (str().copy(": command not found\n"));
	else if (stat(path, &stat_struct) == -1)
		return (str().copy(": No such file or directory\n"));
	terminal()->status = 0;
	return (NULL);
}

bool	assert_cmd(t_cmd *cmd)
{
	char				*error_prompt;
	char				*error_message;
	static struct stat	stat_struct;

	if (!cmd || !cmd->args || !cmd->args[0])
		return (false);
	error_message = NULL;
	if (str().contains(cmd->args[0], "/"))
		error_message = handle_contains_slash(stat_struct, cmd->args[0]);
	else
		error_message = handle_doesnt_contain_slash(stat_struct, cmd->args[0]);
	if (error_message)
	{
		error_prompt = str().join("minishell: ", cmd->args[0]);
		(str().fputstr)(2, error_prompt);
		(str().fputstr)(2, error_message);
		free(error_prompt);
		free(error_message);
		return (false);
	}
	return (true);
}

pid_t	execute(t_cmd *cmd, int in, int out)
{
	pid_t	pid;

	if (!assert_cmd(cmd))
		return (0);
	pid = fork();
	if (!pid)
		(dup2(in, 0), dup2(out, 1));
	ft_close(in);
	ft_close(out);
	if (pid)
		return (pid);
	close_all_non_standart_fds();
	unmask_signals();
	execve(cmd->args[0], cmd->args, hashmap(terminal()->env)->to_array());
	exit(127);
}
