/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:25:48 by paude-so          #+#    #+#             */
/*   Updated: 2025/04/03 15:05:33 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	is_redirection(char *token)
{
	return (ft_strcmp(token, "<") == 0 || ft_strcmp(token, ">") == 0
		|| ft_strcmp(token, "<<") == 0 || ft_strcmp(token, ">>") == 0);
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

static bool	check_syntax_errors(char *line)
{
	int		i;
	char	quote;

	i = 0;
	quote = 0;
	while (line[i])
	{
		if (!quote && (line[i] == '\'' || line[i] == '"'))
			quote = line[i];
		else if (quote && line[i] == quote)
			quote = 0;
		else if (!quote && line[i] == ';')
			return (true);
		i++;
	}
	if (quote != 0)
		return (true);
	return (false);
}

t_token	*parse(char *line)
{
	char	**tokens;
	size_t	pos;
	t_token	*result;

	if (!line || !*line)
		return (NULL);
	free_token(terminal()->token);
	if (check_syntax_errors(line))
	{
		ft_fputstr(2, "minishell: syntax error\n");
		terminal()->status = 258;
		return (NULL);
	}
	tokens = tokenize(line);
	if (!tokens)
		return (NULL);
	pos = 0;
	result = parse_and_or(tokens, &pos);
	ft_strvfree(tokens);
	return (result);
}
