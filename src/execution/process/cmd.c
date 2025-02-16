/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 21:24:04 by afpachec          #+#    #+#             */
/*   Updated: 2025/01/27 14:38:30 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <execution.h>

void	update_fd(int *fd, int new_fd)
{
	if (new_fd == -2)
		return ;
	ft_close(*fd);
	*fd = new_fd;
}

bool match_wildcard(char *pattern, char *string) {
    if (*pattern == '\0' && *string == '\0')
        return true;
    if (*pattern == '\0')
        return false;
    if (!*string) {
        while (*pattern == '*')
            pattern++;
        return (!*pattern);
    }
    if (*pattern == '*')
        return match_wildcard(pattern + 1, string) || match_wildcard(pattern, string + 1);
    if (*pattern == *string)
        return match_wildcard(pattern + 1, string + 1);
    return false;
}

char	**process_wildcard(char *arg)
{
	t_array			*arr;
	DIR				*curr_dir;
	struct dirent	*entry;
	char			**expanded_arg;


	arr = new_array();
	curr_dir = opendir(".");
	if (!curr_dir)
		return (array(arr)->destroy(), NULL);
	entry = readdir(curr_dir);
	while (entry)
	{
		if (match_wildcard(arg, entry->d_name))
			array(arr)->add(str().copy(entry->d_name));
		entry = readdir(curr_dir);
	}
	closedir(curr_dir);
	expanded_arg = array(arr)->to_str();
	array(arr)->destroy();
	return (expanded_arg);
}

void	process_wildcards(t_cmd *cmd)
{
	size_t	i;
	char	**new_args;
	char	**tmp_args;
	char	**expanded_arg;

	i = 0;
	new_args = ft_calloc(sizeof(char *) * 2);
	new_args[0] = str().copy(cmd->args[0]);
	while (cmd->args[++i])
	{
		expanded_arg = process_wildcard(cmd->args[i]);
		printf("Expanded arg:\n");
		print_list(expanded_arg);
		printf("New args:\n");
		print_list(new_args);
		tmp_args = new_args;
		new_args = str().join_list(new_args, expanded_arg);
		free_list(tmp_args);
		free_list(expanded_arg);
	}
	printf("CMD args:\n");
	print_list(cmd->args);
	printf("New args:\n");
	print_list(new_args);
	if (i == 1)
		return ;
	printf("Freeing old and setting new args\n");
	free_list(cmd->args);
	cmd->args = new_args;
}

void	process_cmd(t_token	*token, int in, int out)
{
	update_fd(&in, token->cmd->in);
	update_fd(&out, token->cmd->out);
	process_wildcards(token->cmd);
	if (!token->cmd->execute)
		return ;
	token->pid = token->cmd->execute(token->cmd, in, out);
}
