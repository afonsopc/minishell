/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:36:47 by paude-so          #+#    #+#             */
/*   Updated: 2025/03/26 16:21:26 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <execution.h>

void		execute(t_cmd *cmd);
void		execute_cd(t_cmd *cmd);
void		execute_pwd(t_cmd *cmd);
void		execute_exit(t_cmd *cmd);
void		execute_echo(t_cmd *cmd);
void		execute_export(t_cmd *cmd);
void		execute_env(t_cmd *cmd);
void		execute_unset(t_cmd *cmd);

static t_redirect	*new_redirect(char	**args)
{
	t_redirect	*r;

	if (!args)
		return (NULL);
	r = ft_calloc(1, sizeof(t_redirect));
	if (!r)
		return (ft_strvfree(args), NULL);
	r->args = args;
	if (ft_strcmp(args[0], ">") == 0 || ft_strcmp(args[0], ">>") == 0)
		r->type = OUT;
	return (r);
}

static int	organizar(char	**args, size_t i)
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

static void	init_redirect(t_cmd	*cmd)
{
	size_t		i;
	t_redirect	*end;
	t_redirect	*new;

	i = 0;
	end = NULL;
	while (cmd->args[i])
	{
		if (ft_strcmp(cmd->args[i], ">") == 0 || ft_strcmp(cmd->args[i], "<") == 0 \
		|| ft_strcmp(cmd->args[i], ">>") == 0 || ft_strcmp(cmd->args[i], "<<") == 0)
		{
			new = new_redirect(ft_strvndup(cmd->args + i, 2));
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
	if (ft_strcmp(*cmd->args, "echo") == 0)
		cmd->execute = execute_echo;
	else if (ft_strcmp(*cmd->args, "export") == 0)
		cmd->execute = execute_export;
	else if (ft_strcmp(*cmd->args, "env") == 0)
		cmd->execute = execute_env;
	else if (ft_strcmp(*cmd->args, "unset") == 0)
		cmd->execute = execute_unset;
	else if (ft_strcmp(*cmd->args, "cd") == 0)
		cmd->execute = execute_cd;
	else if (ft_strcmp(*cmd->args, "pwd") == 0)
		cmd->execute = execute_pwd;
	else if (ft_strcmp(*cmd->args, "exit") == 0)
		cmd->execute = execute_exit;
	else
		cmd->execute = execute;
}

t_cmd	*new_cmd(char **args)
{
	t_cmd	*cmd;

	cmd = ft_calloc(1, sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	process_env_assignments(args);
	cmd->args = args;
	init_redirect(cmd);
	init_fun(cmd);
	arg_clean(cmd);
	if (cmd->args && *cmd->args)
		cmd->args[0] = get_command_path(cmd->args [0]);
	cmd->in = -2;
	cmd->out = -2;
	return (cmd);
}
