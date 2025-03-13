/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:31:20 by paude-so          #+#    #+#             */
/*   Updated: 2025/03/13 14:31:29 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*read_operator(t_lexer *lexer)
{
	char	*result;
	char	first_char;

	first_char = lexer->curr_char;
	advance_lexer(lexer);
	if ((first_char == '|' && lexer->curr_char == '|') || (first_char == '&'
			&& lexer->curr_char == '&'))
	{
		result = ft_calloc(3);
		result[0] = first_char;
		result[1] = lexer->curr_char;
		advance_lexer(lexer);
		return (result);
	}
	result = ft_calloc(2);
	result[0] = first_char;
	return (result);
}

char	*read_redirection(t_lexer *lexer)
{
	char	*result;
	char	first_char;

	first_char = lexer->curr_char;
	advance_lexer(lexer);
	if ((first_char == '>' && lexer->curr_char == '>') || (first_char == '<'
			&& lexer->curr_char == '<'))
	{
		result = ft_calloc(3);
		result[0] = first_char;
		result[1] = lexer->curr_char;
		advance_lexer(lexer);
		return (result);
	}
	result = ft_calloc(2);
	result[0] = first_char;
	return (result);
}

char	*read_string(t_lexer *lexer, char quote)
{
	size_t	start;
	char	*result;

	advance_lexer(lexer);
	start = lexer->pos;
	while (lexer->curr_char && lexer->curr_char != quote)
		advance_lexer(lexer);
	result = str().copy_n(lexer->input + start, lexer->pos - start);
	if (lexer->curr_char == quote)
		advance_lexer(lexer);
	return (result);
}

char	*read_word(t_lexer *lexer)
{
	size_t	start;

	start = lexer->pos;
	while (lexer->curr_char && !str().is_space(lexer->curr_char)
		&& lexer->curr_char != '|' && lexer->curr_char != '&'
		&& lexer->curr_char != '<' && lexer->curr_char != '>'
		&& lexer->curr_char != '\'' && lexer->curr_char != '\"'
		&& lexer->curr_char != '(' && lexer->curr_char != ')')
		advance_lexer(lexer);
	return (str().copy_n(lexer->input + start, lexer->pos - start));
}
