/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonsocoutinho <afonsocoutinho@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:31:20 by paude-so          #+#    #+#             */
/*   Updated: 2025/03/24 00:49:08 by afonsocouti      ###   ########.fr       */
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
		result = ft_calloc(3, sizeof(char));
		result[0] = first_char;
		result[1] = lexer->curr_char;
		advance_lexer(lexer);
		return (result);
	}
	result = ft_calloc(2, sizeof(char));
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
		result = ft_calloc(3, sizeof(char));
		result[0] = first_char;
		result[1] = lexer->curr_char;
		advance_lexer(lexer);
		return (result);
	}
	result = ft_calloc(2, sizeof(char));
	result[0] = first_char;
	return (result);
}

char	*read_double_quote(t_lexer *lexer)
{
	size_t	start;
	char	*result;
	char	*content;

	advance_lexer(lexer);
	start = lexer->pos;
	while (lexer->curr_char && lexer->curr_char != '"')
		advance_lexer(lexer);
	content = ft_strndup(lexer->input + start, lexer->pos - start);
	if (lexer->curr_char == '"')
		advance_lexer(lexer);
	result = ft_strjoin("\f\f", content);
	free(content);
	return (result);
}

char	*read_single_quote(t_lexer *lexer)
{
	size_t	start;
	char	*content;
	char	*result;

	advance_lexer(lexer);
	start = lexer->pos;
	while (lexer->curr_char && lexer->curr_char != '\'')
		advance_lexer(lexer);
	content = ft_strndup(lexer->input + start, lexer->pos - start);
	if (lexer->curr_char == '\'')
		advance_lexer(lexer);
	result = ft_strjoin("\f", content);
	free(content);
	return (result);
}
