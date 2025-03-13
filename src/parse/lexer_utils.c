/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:31:00 by paude-so          #+#    #+#             */
/*   Updated: 2025/03/13 14:31:08 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_lexer	*init_lexer(char *input)
{
	t_lexer	*lexer;

	lexer = ft_calloc(sizeof(t_lexer));
	if (!lexer)
		return (NULL);
	lexer->input = input;
	lexer->pos = 0;
	lexer->len = str().size(input);
	lexer->curr_char = input[0];
	return (lexer);
}

void	advance_lexer(t_lexer *lexer)
{
	if (lexer->pos < lexer->len)
	{
		lexer->pos++;
		lexer->curr_char = lexer->input[lexer->pos];
	}
	else
		lexer->curr_char = '\0';
}

void	skip_whitespace(t_lexer *lexer)
{
	while (lexer->curr_char && str().is_space(lexer->curr_char))
		advance_lexer(lexer);
}

char	*read_parenthesis(t_lexer *lexer)
{
	char	*token;

	token = ft_calloc(2);
	token[0] = lexer->curr_char;
	advance_lexer(lexer);
	return (token);
}
