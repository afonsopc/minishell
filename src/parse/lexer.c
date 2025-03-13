/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:25:41 by paude-so          #+#    #+#             */
/*   Updated: 2025/03/13 18:10:42 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*handle_special_char(t_lexer *lexer)
{
	char	*token;

	if (lexer->curr_char == '|' || lexer->curr_char == '&')
		token = read_operator(lexer);
	else if (lexer->curr_char == '<' || lexer->curr_char == '>')
		token = read_redirection(lexer);
	else if (lexer->curr_char == '\'')
		token = read_single_quote(lexer);
	else if (lexer->curr_char == '\"')
		token = read_double_quote(lexer);
	else if (lexer->curr_char == '(' || lexer->curr_char == ')')
		token = read_parenthesis(lexer);
	else
		token = read_word(lexer);
	return (token);
}

void	add_token_to_array(t_array *tokens, char *token)
{
	if (token && *token)
		array(tokens)->add(token);
	else
		free(token);
}

static char	**lexer_tokenize(char *input)
{
	t_lexer	*lexer;
	t_array	*tokens;
	char	*token;
	char	**result;

	lexer = init_lexer(input);
	tokens = new_array();
	if (!lexer || !tokens)
		return (NULL);
	while (lexer->curr_char)
	{
		skip_whitespace(lexer);
		if (!lexer->curr_char)
			break ;
		token = handle_special_char(lexer);
		add_token_to_array(tokens, token);
	}
	free(lexer);
	result = array(tokens)->to_str();
	array(tokens)->destroy();
	return (result);
}

char	**tokenize(char *input)
{
	if (!input || !*input)
		return (NULL);
	return (lexer_tokenize(input));
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
