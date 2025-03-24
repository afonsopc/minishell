/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonsocoutinho <afonsocoutinho@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:25:48 by paude-so          #+#    #+#             */
/*   Updated: 2025/03/24 01:03:58 by afonsocouti      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	is_redirection(char *token)
{
	return (ft_strcmp(token, "<") || ft_strcmp(token, ">")
		|| ft_strcmp(token, "<<") || ft_strcmp(token, ">>"));
}

t_redirect	*create_redirection(char **tokens, size_t *pos)
{
	t_redirect	*redirect;
	char		**args;

	if (!tokens[*pos] || !tokens[*pos + 1])
		return (NULL);
	redirect = ft_calloc(1, sizeof(t_redirect));
	if (!redirect)
		return (NULL);
	args = ft_calloc(3, sizeof(char *));
	if (!args)
		return (free(redirect), NULL);
	args[0] = ft_strdup(tokens[*pos]);
	args[1] = ft_strdup(tokens[*pos + 1]);
	redirect->args = args;
	if (ft_strcmp(args[0], "<") || ft_strcmp(args[0], "<<"))
		redirect->type = IN;
	else
		redirect->type = OUT;
	*pos += 2;
	return (redirect);
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

t_token	*parse(char *line)
{
	char	**tokens;
	size_t	pos;
	t_token	*result;

	if (!line || !*line)
		return (NULL);
	free_token(terminal()->token);
	tokens = tokenize(line);
	if (!tokens)
		return (NULL);
	pos = 0;
	result = parse_and_or(tokens, &pos);
	ft_strvfree(tokens);
	terminal()->token = result;
	return (result);
}
