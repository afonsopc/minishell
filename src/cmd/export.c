/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:36:26 by paude-so          #+#    #+#             */
/*   Updated: 2025/04/01 14:39:15 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static bool	check_key(char *value)
{
	size_t	alpha_count;

	if (!value)
		return (false);
	if (!(ft_isalpha(*value) || *value == '_'))
		return (false);
	alpha_count = ft_isalpha(*value);
	value++;
	while (*value && (ft_isalnum(*value) || *value == '_'))
	{
		alpha_count += ft_isalpha(*value);
		value++;
	}
	return (!*value && alpha_count);
}

static void	export_str(t_cmd *cmd, char *arg)
{
	char	*var_name;
	char	*var_value;
	char	*equals;

	equals = ft_strstr(arg, "=");
	if (!arg || !equals)
		return ;
	var_name = ft_strndup(arg, equals - arg);
	if (!check_key(var_name))
	{
		ft_fputstr(2, "export: ");
		ft_fputstr(2, "not a valid identifier\n");
		terminal()->status = 1;
		return (free(var_name));
	}
	var_value = ft_strdup(equals + 1);
	if (cmd->in == 0 && cmd->out == 1)
		ft_hashmap_set(terminal()->env, var_name, ft_strdup(var_value),
			free);
	free(var_name);
}

static void	print_export(int out)
{
	t_element	*tmp;

	tmp = terminal()->env->table[0];
	while (tmp)
	{
		ft_fputstr(out, "declare -x ");
		ft_fputstr(out, tmp->key);
		if (tmp->value)
		{
			ft_fputstr(out, "=");
			ft_fputstr(out, tmp->value);
		}
		ft_fputstr(out, "\n");
		tmp = tmp->next;
	}
}

pid_t	execute_export(t_cmd *cmd)
{
	size_t	i;

	terminal()->status = 0;
	i = 1;
	if (ft_strvlen(cmd->args) == 1)
		print_export(cmd->out);
	else
	{
		while (cmd->args[i])
			export_str(cmd, cmd->args[i++]);
	}
	ft_close2(cmd->in, cmd->out);
	return (0);
}
