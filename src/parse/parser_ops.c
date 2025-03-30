/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:40:27 by paude-so          #+#    #+#             */
/*   Updated: 2025/03/26 16:08:19 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

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

t_token	*parse_and_or(char **tokens, size_t *pos)
{
	t_token	*left;
	t_token	*right;
	t_token	*result;
	char	*op_type;

	left = parse_pipe(tokens, pos);
	if (!left)
		return (NULL);
	while (tokens[*pos] && (ft_strcmp(tokens[*pos], "&&") == 0
			|| ft_strcmp(tokens[*pos], "||") == 0))
	{
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
