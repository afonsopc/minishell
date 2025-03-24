/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonsocoutinho <afonsocoutinho@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:31:00 by paude-so          #+#    #+#             */
/*   Updated: 2025/03/24 00:49:12 by afonsocouti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_lexer	*init_lexer(char *input)
{
	t_lexer	*lexer;

	lexer = ft_calloc(1, sizeof(t_lexer));
	if (!lexer)
		return (NULL);
	lexer->input = input;
	lexer->pos = 0;
	lexer->len = ft_strlen(input);
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
	while (lexer->curr_char && ft_isspace(lexer->curr_char))
		advance_lexer(lexer);
}
