/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonsocoutinho <afonsocoutinho@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:36:26 by paude-so          #+#    #+#             */
/*   Updated: 2025/03/24 00:58:45 by afonsocouti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	__isalnum(char c);

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

static void	export_str(char *value)
{
	char	**args;
	size_t	len;

	args = ft_split(value, "=");
	if (!check_key(args[0]))
	{
		ft_fputstr(2, "export: ");
		ft_fputstr(2, "not a valid identifier\n");
		ft_strvfree(args);
		terminal()->status = 1;
		return ;
	}
	if (ft_strstr(value, "=") && !args[1])
		args[1] = ft_strdup("");
	len = 0;
	while (args[1] && args[1][len] && ft_isalnum(args[1][len]))
		len++;
	if (args[1])
		args[1][len] = 0;
	(hashmap(terminal()->env)->put)(ft_strdup(args[0]), ft_strdup(args[1]));
	ft_strvfree(args);
}

static void	print_export(int out)
{
	t_element	*tmp;

	tmp = hashmap(terminal()->env)->get_element_index(0);
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

void	execute_export(t_cmd *cmd)
{
	size_t	i;

	i = 1;
	if (ft_strvlen(cmd->args) == 1)
		print_export(0);
	else
	{
		while (cmd->args[i])
			export_str(cmd->args[i++]);
	}
	terminal()->status = 0;
	ft_exit_free();
}
