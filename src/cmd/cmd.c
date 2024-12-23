/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:32:09 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/18 16:35:47 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

pid_t		execute(t_cmd *cmd, int in, int out);
pid_t		execute_echo(t_cmd *cmd, int in, int out);
pid_t		execute_export(t_cmd *cmd, int in, int out);
pid_t		execute_env(t_cmd *cmd, int in, int out);
pid_t		execute_unset(t_cmd *cmd, int in, int out);

static t_redirect	*new_redirect(char	**args)
{
	t_redirect	*r;

	if (!args)
		return (NULL);
	r = ft_calloc(sizeof(t_redirect));
	if (!r)
		return (free_list(args), NULL);
	r->args = args;
	if (str().equals(args[0], ">") || str().equals(args[0], ">>"))
		r->type = OUT;
	return (r);
}

static int organizar(char	**args, size_t i)
{
	size_t	start;

	start = i + (args[i + 1] != NULL);
	free(args[i]);
	free(args[i + 1]);
	while (args[++start])
		args[i++] = args[start];
	args[i] = NULL;
	return (0);
}

static void init_redirect(t_cmd	*cmd)
{
	size_t		i;
	t_redirect	*end;
	t_redirect	*new;

	i = 0;
	end = NULL;
	while (cmd->args[i])
	{
		if (str().equals(cmd->args[i], ">") || str().equals(cmd->args[i], "<") \
		|| str().equals(cmd->args[i], ">>") || str().equals(cmd->args[i], "<<"))
		{
			new = new_redirect(str().copy_array_n(cmd->args + i, 2));
			if (cmd->redirect == NULL)
				cmd->redirect = new;
			else
				end->next = new;
			end = new;
			i = organizar(cmd->args, i);
		}
		else
			i++;
	}
}

static	void	init_fun(t_cmd	*cmd)
{
	if (str().equals(*cmd->args, "echo"))
		cmd->execute = execute_echo;
	else if (str().equals(*cmd->args, "export"))
		cmd->execute = execute_export;
	else if (str().equals(*cmd->args, "env"))
		cmd->execute = execute_env;
	else if (str().equals(*cmd->args, "unset"))
		cmd->execute = execute_unset;
	else
		cmd->execute = execute;
}

t_cmd	*new_cmd(char **args)
{
	t_cmd	*cmd;

	cmd = ft_calloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->args = args;
	init_redirect(cmd);
	init_fun(cmd);
	if (cmd->args && *cmd->args);
		cmd->args[0] = get_command_path(cmd->args [0]);
	return (cmd);
}
