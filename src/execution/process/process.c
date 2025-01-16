/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 21:24:29 by afpachec          #+#    #+#             */
/*   Updated: 2025/01/09 18:33:50 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <execution.h>

void	process(t_token	*token, int in, int out)
{
	if (!token)
		return ;
	if (token->type == CMD)
		process_cmd(token, in, out);
	else if (token->type == AND)
		process_and(token, in, out);
	else if (token->type == PIPE)
		process_pipe(token, in, out);
	else if (token->type == OR)
		process_or(token, in, out);
}

void	process_token(t_token	*token)
{
	if (!token)
		return ;
	process_redirections(token);
	process(token, 0, 1);
	wait_token(token);
}
