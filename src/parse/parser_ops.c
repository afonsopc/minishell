/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:40:27 by paude-so          #+#    #+#             */
/*   Updated: 2025/04/03 17:50:08 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	seg_fault_handler(t_token **token)
{
	ft_fputstr(2, "minishell: syntax error\n");
	free_token(*token);
	terminal()->status = 258;
}

t_token	*parse_pipe(char **tokens, size_t *pos)
{
	t_token	*left;
	t_token	*right;
	t_token	*result;

	left = parse_simple_command(tokens, pos);
	if (!left)
		return (NULL);
	while (tokens[*pos] && ft_strcmp(tokens[*pos], "|") == 0)
	{
		(*pos)++;
		if (!tokens[*pos])
			return (seg_fault_handler(&left), NULL);
		right = parse_pipe(tokens, pos);
		if (!right)
			return (free_token(left), NULL);
		result = new_token("|", NULL);
		if (!result)
			return (free_token(left), free_token(right), NULL);
		result->left = left;
		result->right = right;
		left = result;
	}
	return (left);
}

static bool	is_and_or(char *token)
{
	return (ft_strequal(token, "&&") || ft_strequal(token, "||"));
}

t_token	*parse_and_or(char **tokens, size_t *pos)
{
	t_token	*left;
	t_token	*right;
	t_token	*result;
	char	*op_type;

	left = parse_pipe(tokens, pos);
	if (!left)
		return (NULL);
	while (tokens[*pos] && is_and_or(tokens[*pos]))
	{
		if (!tokens[*pos])
			return (seg_fault_handler(&left), NULL);
		op_type = tokens[*pos];
		(*pos)++;
		right = parse_pipe(tokens, pos);
		if (!right)
			return (free_token(left), NULL);
		result = new_token(op_type, NULL);
		if (!result)
			return (free_token(left), free_token(right), NULL);
		result->left = left;
		result->right = right;
		left = result;
	}
	return (left);
}

void	add_redirection(t_cmd *cmd, t_redirect *new_redirect)
{
	t_redirect	*redirect;

	if (!cmd || !new_redirect)
		return ;
	if (!cmd->redirect)
	{
		cmd->redirect = new_redirect;
		return ;
	}
	redirect = cmd->redirect;
	while (redirect->next)
		redirect = redirect->next;
	redirect->next = new_redirect;
}
