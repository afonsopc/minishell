/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:40:00 by paude-so          #+#    #+#             */
/*   Updated: 2025/03/13 14:45:14 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	process_redirections(t_cmd *cmd, char **tokens, size_t *pos)
{
	t_redirect	*redirect;

	if (is_redirection(tokens[*pos]) && tokens[*pos + 1])
	{
		redirect = create_redirection(tokens, pos);
		add_redirection(cmd, redirect);
	}
	else
		(*pos)++;
}

static int	should_add_arg(char **tokens, size_t i, size_t start)
{
	return (!is_redirection(tokens[i]) && (i == start
			|| !is_redirection(tokens[i - 1])));
}

static char	**collect_cmd_args(char **tokens, size_t start, size_t end)
{
	t_array	*cmd_args;
	char	**args;
	size_t	i;

	cmd_args = new_array();
	if (!cmd_args)
		return (NULL);
	i = start;
	while (i < end)
	{
		if (should_add_arg(tokens, i, start))
			array(cmd_args)->add(str().copy(tokens[i]));
		i++;
	}
	args = array(cmd_args)->to_str();
	array(cmd_args)->destroy();
	return (args);
}

t_token	*parse_simple_command(char **tokens, size_t *pos)
{
	t_cmd	*cmd;
	size_t	start;
	char	**args;

	start = *pos;
	cmd = ft_calloc(sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->in = -2;
	cmd->out = -2;
	while (tokens[*pos] && !str().equals(tokens[*pos], "|")
		&& !str().equals(tokens[*pos], "||") && !str().equals(tokens[*pos],
			"&&"))
		process_redirections(cmd, tokens, pos);
	if (*pos <= start)
		return (free_cmd(cmd), NULL);
	args = collect_cmd_args(tokens, start, *pos);
	if (!args || !args[0])
		return (free_cmd(cmd), NULL);
	free_cmd(cmd);
	return (new_token("CMD", new_cmd(args)));
}
