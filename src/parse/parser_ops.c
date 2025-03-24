/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonsocoutinho <afonsocoutinho@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:40:27 by paude-so          #+#    #+#             */
/*   Updated: 2025/03/24 01:08:24 by afonsocouti      ###   ########.fr       */
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
	while (tokens[*pos] && ft_strcmp(tokens[*pos], "|"))
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
	while (tokens[*pos] && (ft_strcmp(tokens[*pos], "&&")
			|| ft_strcmp(tokens[*pos], "||")))
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
