/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:36:36 by paude-so          #+#    #+#             */
/*   Updated: 2025/03/13 19:42:47 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static bool	check_flag(char *str)
{
	if (!str || *str != '-')
		return (false);
	str++;
	while (*str == 'n')
		str++;
	return ((*str == '\0'));
}

static void	expand_variable(char *content, size_t *j, int out)
{
	int		k;
	char	*value;
	char	var_name[256];

	(*j)++;
	ft_memset(var_name, 0, 256);
	k = 0;
	while (content[*j] && ((str().isalnum)(content[*j]) || content[*j] == '_'))
		var_name[k++] = content[(*j)++];
	value = hashmap(terminal()->env)->get_key(var_name);
	if (value)
		(str().fputstr)(out, value);
}

static void	process_double_quote(char *content, int out)
{
	size_t	j;
	char	c[2];

	j = 0;
	while (content[j])
	{
		if (content[j] == '$' && content[j + 1])
			expand_variable(content, &j, out);
		else
		{
			c[0] = content[j];
			c[1] = '\0';
			(str().fputstr)(out, c);
			j++;
		}
	}
}

static void	process_argument(char *arg, int out)
{
	char	*value;

	if (str().starts_with(arg, "sq:"))
		(str().fputstr)(out, arg + 3);
	else if (str().starts_with(arg, "dq:"))
		process_double_quote(arg + 3, out);
	else if (arg[0] == '$' && arg[1])
	{
		value = hashmap(terminal()->env)->get_key(arg + 1);
		if (value)
			(str().fputstr)(out, value);
	}
	else
		(str().fputstr)(out, arg);
}

pid_t	execute_echo(t_cmd *cmd, int in, int out)
{
	bool	flag;
	size_t	i;

	if (str().equals(cmd->args[1], "$?"))
	{
		(str().fputnbr)(out, terminal()->status);
		(str().fputstr)(out, "\n");
		ft_close(out);
		ft_close(in);
		return (0);
	}
	flag = check_flag(cmd->args[1]);
	i = flag;
	while (cmd->args[++i])
	{
		process_argument(cmd->args[i], out);
		if (cmd->args[i + 1])
			(str().fputstr)(out, " ");
	}
	if (!flag)
		(str().fputstr)(out, "\n");
	ft_close(out);
	ft_close(in);
	return (0);
}
