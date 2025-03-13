/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:36:26 by paude-so          #+#    #+#             */
/*   Updated: 2025/03/13 12:36:28 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	__isalnum(char c);

static bool	check_key(char *value)
{
	size_t	alpha_count;

	if (!value)
		return (false);
	alpha_count = 0;
	while ((str().isalnum)(*value))
	{
		alpha_count += (str().isalpha)(*value);
		value++;
	}
	return (!*value && alpha_count);
}

static void	export_str(char *value)
{
	char	**args;
	size_t	len;

	args = str().split(value, "=");
	if (!check_key(args[0]))
	{
		(str().fputstr)(2, "export: `");
		(str().fputstr)(2, args[0]);
		(str().fputstr)(2, "': not a valid identifier\n");
		free_list(args);
		terminal()->status = 1;
		return ;
	}
	if (str().contains(value, "=") && !args[1])
		args[1] = str().copy("");
	len = 0;
	while (args[1] && args[1][len] && __isalnum(args[1][len]))
		len++;
	if (args[1])
		args[1][len] = 0;
	(hashmap(terminal()->env)->put)(str().copy(args[0]), str().copy(args[1]));
	free_list(args);
}

static void	print_export(int out)
{
	t_element	*tmp;

	tmp = hashmap(terminal()->env)->get_element_index(0);
	while (tmp)
	{
		(str().fputstr)(out, "declare -x ");
		(str().fputstr)(out, tmp->key);
		if (tmp->value)
		{
			(str().fputstr)(out, "=");
			(str().fputstr)(out, tmp->value);
		}
		(str().fputstr)(out, "\n");
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
