/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 21:24:29 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/19 23:22:17 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"

void	process(t_token	*token, bool wait, int fds[2])
{
	if (!token)
		return ;
	if (token->type == CMD)
		process_cmd(token, fds);
	else if (token->type == AND)
		process_and(token, fds);
	else if (token->type == PIPE)
		process_pipe(token, fds);
	if (token->type == CMD && wait)
		wait_fork();
}
