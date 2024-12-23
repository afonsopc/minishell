/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 16:55:27 by edos-san          #+#    #+#             */
/*   Updated: 2024/12/23 18:12:50 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	__isalnum(char c);

static bool check_key(char *value)
{
	if (!value)
		return (false);
	while (__isalnum(*value))
		value++;	
	return (*value == '\0');
}

static void export_str(char *value)
{
	char	**args;
	size_t	len;

	args = str().split(value, "=");
	if (!check_key(args[0]))
	{
		write(2, "export: `", 10);
		write(2, args[0], str().size(args[0]));
		write(2, "': not a valid identifier\n", 27); 
		free_list(args);
		return ;
	}
	if (str().contains(value, "=") && !args[1])
		args[1] = str().copy("");
	len = 0;
	while (args[1] && args[1][len] && __isalnum(args[1][len]))
		len++;
	if (args[1])
		args[1][len] = 0;
	hashmap(terminal()->env)->put(str().copy(args[0]), str().copy(args[1]));
	free_list(args);
}

static void print_export(int out)
{
	t_element	*tmp;

	tmp = hashmap(terminal()->env)->get_element_index(0);
	while (tmp)
	{
		write(out, "declare -x ", 12);
		write(out, tmp->key, str().size(tmp->key));
		if (tmp->value)
		{
			write(out, "=", 1);
			write(out, tmp->value, str().size(tmp->value));
		}
		write(out, "\n", 1);
		tmp = tmp->next;
	}
}

pid_t	execute_export(t_cmd *cmd, int in, int out)
{
	size_t	i;

	i = 1;
	if (str().size_list(cmd->args) == 1)
		print_export(out);
	else
	{
		while (cmd->args[i])
			export_str(cmd->args[i++]);
	}
	ft_close(out);
	ft_close(in);
	return (0);
}
