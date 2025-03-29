/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:25:41 by paude-so          #+#    #+#             */
/*   Updated: 2025/03/29 15:13:20 by paude-so         ###   ########.fr       */
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
	else
		token = read_word(lexer);
	return (token);
}

void	add_token_to_array(t_list **tokens, char *token)
{
	if (token && *token)
		ft_list_add(tokens, ft_strdup(token), free);
	else
		free(token);
}

static char	**lexer_tokenize(char *input)
{
	t_lexer	*lexer;
	t_list	*tokens;
	char	*token;
	char	**result;

	lexer = init_lexer(input);
	tokens = NULL;
	if (!lexer)
		return (NULL);
	while (lexer->curr_char)
	{
		skip_whitespace(lexer);
		if (!lexer->curr_char)
			break ;
		token = handle_special_char(lexer);
		add_token_to_array(&tokens, token);
	}
	free(lexer);
	result = ft_list_to_strv(tokens);
	ft_list_destroy(&tokens);
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
	char	quote;

	quote = 0;
	if (lexer->curr_char == '\'' || lexer->curr_char == '"')
		quote = lexer->curr_char;
	start = lexer->pos;
	if (quote)
	{
		advance_lexer(lexer);
		while (lexer->curr_char && !(lexer->curr_char == quote && (!lexer->input[lexer->pos + 1] || ft_isspace(lexer->input[lexer->pos + 1]))))
			advance_lexer(lexer);
		advance_lexer(lexer);
	}
	else
	{
		while (lexer->curr_char && !ft_isspace(lexer->curr_char)
			&& lexer->curr_char != '|' && lexer->curr_char != '&'
			&& lexer->curr_char != '<' && lexer->curr_char != '>'
			&& lexer->curr_char != '\'' && lexer->curr_char != '"')
			advance_lexer(lexer);
	}
	return (ft_strndup(lexer->input + start, lexer->pos - start));
}
