/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 14:51:47 by afpachec          #+#    #+#             */
/*   Updated: 2025/04/04 17:28:43 by paude-so         ###   ########.fr       */
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
		return (ft_strdup(": Is a directory\n"));
	else if (stat(path, &stat_struct) == -1)
	{
		terminal()->status = 127;
		return (ft_strdup(": No such file or directory\n"));
	}
	else if (access(path, X_OK) == -1)
		return (ft_strdup(": Permission denied\n"));
	terminal()->status = 0;
	return (NULL);
}

char	*handle_doesnt_contain_slash(struct stat stat_struct, char *path)
{
	terminal()->status = 127;
	if (!(is_directory(path) || access(path, X_OK) == -1) && stat(path,
			&stat_struct) == -1)
		return (ft_strdup(": No such file or directory\n"));
	return (ft_strdup(": command not found\n"));
}

bool	assert_cmd(t_cmd *cmd)
{
	char				*error_prompt;
	char				*error_message;
	static struct stat	stat_struct;

	if (!cmd || !cmd->args || !cmd->args[0])
		return (false);
	error_message = NULL;
	if (ft_strstr(cmd->args[0], "/"))
		error_message = handle_contains_slash(stat_struct, cmd->args[0]);
	else
		error_message = handle_doesnt_contain_slash(stat_struct, cmd->args[0]);
	if (error_message)
	{
		error_prompt = ft_strjoin("minishell: ", cmd->args[0]);
		ft_fputstr(2, error_prompt);
		ft_fputstr(2, error_message);
		free(error_prompt);
		free(error_message);
		return (false);
	}
	return (true);
}

pid_t	execute(t_cmd *cmd)
{
	pid_t	pid;
	char	**env;

	pid = fork();
	if (pid)
		return (ft_close(cmd->in), ft_close(cmd->out), pid);
	if (cmd->in != -2)
		dup2(cmd->in, STDIN_FILENO);
	if (cmd->out != -2)
		dup2(cmd->out, STDOUT_FILENO);
	if (!assert_cmd(cmd))
		ft_exit_free();
	close_all_non_standart_fds();
	mask_signals(CLEAR);
	env = ft_hashmap_to_strv(terminal()->env);
	execve(cmd->args[0], cmd->args, env);
	ft_strvfree(env);
	terminal()->status = 127;
	ft_exit_free();
	return (0);
}
