/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_redirections.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 18:09:39 by paude-so          #+#    #+#             */
/*   Updated: 2025/03/29 18:15:59 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <execution.h>

static t_redirect	*new_redirect(char **args)
{
	t_redirect	*r;

	if (!args)
		return (NULL);
	r = ft_calloc(1, sizeof(t_redirect));
	if (!r)
		return (ft_strvfree(args), NULL);
	r->args = args;
	if (ft_strcmp(args[0], ">") == 0 || ft_strcmp(args[0], ">>") == 0)
		r->type = OUT;
	return (r);
}

static int	organize(char **args, size_t i)
{
	size_t	start;

	start = i + (args[i + 1] != NULL);
	free(args[i]);
	free(args[i + 1]);
	while (args[++start])
		args[i++] = args[start];
	args[i] = NULL;
	return (0);
}

static void	parse_cmd_redirections(t_cmd *cmd)
{
	size_t		i;
	t_redirect	*end;
	t_redirect	*new;

	i = 0;
	end = NULL;
	while (cmd->args[i])
	{
		if (ft_strcmp(cmd->args[i], ">") == 0 || ft_strcmp(cmd->args[i],
				"<") == 0 || ft_strcmp(cmd->args[i], ">>") == 0
			|| ft_strcmp(cmd->args[i], "<<") == 0)
		{
			new = new_redirect(ft_strvndup(cmd->args + i, 2));
			if (cmd->redirect == NULL)
				cmd->redirect = new;
			else
				end->next = new;
			end = new;
			i = organize(cmd->args, i);
		}
		else
			i++;
	}
}

void	parse_token_redirections(t_token *token)
{
	if (!token)
		return ;
	if (token->type != CMD)
	{
		parse_token_redirections(token->left);
		parse_token_redirections(token->right);
		return ;
	}
	parse_cmd_redirections(token->cmd);
}
