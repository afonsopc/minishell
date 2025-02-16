/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 21:54:23 by afpachec          #+#    #+#             */
/*   Updated: 2025/02/16 21:55:03 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <execution.h>

static bool	match_wildcard(char *pattern, char *string)
{
	if (!*pattern)
		return (!*pattern && !*string);
	if (!*string)
	{
		while (*pattern == '*')
			pattern++;
		return (!*pattern);
	}
	if (*pattern == '*')
		return (match_wildcard(pattern + 1, string)
			|| match_wildcard(pattern, string + 1));
	if (*pattern == *string)
		return (match_wildcard(pattern + 1, string + 1));
	return (false);
}

static bool	match_every_file(t_array *arr, char *arg)
{
	DIR				*curr_dir;
	struct dirent	*entry;

	curr_dir = opendir(".");
	if (!curr_dir)
		return (false);
	entry = readdir(curr_dir);
	while (entry)
	{
		if (match_wildcard(arg, entry->d_name))
			array(arr)->add(str().copy(entry->d_name));
		entry = readdir(curr_dir);
	}
	closedir(curr_dir);
	return (true);
}

static char	**process_wildcard(char *arg)
{
	t_array			*arr;
	char			**expanded_arg;

	arr = new_array();
	if (!match_every_file(arr, arg))
		return (array(arr)->destroy(), NULL);
	if (array(arr)->size)
		expanded_arg = array(arr)->to_str();
	else
	{
		expanded_arg = ft_calloc(sizeof(char *) * 2);
		expanded_arg[0] = str().copy(arg);
	}
	return (array(arr)->destroy(), expanded_arg);
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
		tmp_args = new_args;
		new_args = str().join_list(new_args, expanded_arg);
		free_list(tmp_args);
		free_list(expanded_arg);
	}
	if (i == 1)
		return ;
	free_list(cmd->args);
	cmd->args = new_args;
}
