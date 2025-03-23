/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:51:47 by afpachec          #+#    #+#             */
/*   Updated: 2025/03/23 11:11:00 by paude-so         ###   ########.fr       */
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

void	execute(t_cmd *cmd)
{
	if (!assert_cmd(cmd))
	{
		terminal()->status = 127;
		ft_exit_free();
	}
	close_all_non_standart_fds();
	unmask_signals();
	execve(cmd->args[0], cmd->args, hashmap(terminal()->env)->to_array());
	terminal()->status = 127;
	ft_exit_free();
}
