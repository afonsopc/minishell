/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:32:12 by paude-so          #+#    #+#             */
/*   Updated: 2025/03/26 16:13:47 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	set_token_type(t_token *t, char *type)
{
	if (ft_strcmp("|", type) == 0)
		t->type = PIPE;
	else if (ft_strcmp("||", type) == 0)
		t->type = OR;
	else if (ft_strcmp("&&", type) == 0)
		t->type = AND;
	else
		t->type = CMD;
}

t_token	*new_token(char *type, t_cmd *cmd)
{
	t_token	*t;

	if (!type)
		return (NULL);
	t = ft_calloc(1, sizeof(t_token));
	if (!t)
		return (NULL);
	t->cmd = cmd;
	set_token_type(t, type);
	t->pid = 0;
	return (t);
}

bool	free_token(t_token *token)
{
	if (!token)
		return (false);
	free_cmd(token->cmd);
	free_token(token->left);
	free_token(token->right);
	free(token);
	return (true);
}
