/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 21:24:25 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/23 16:29:15 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"

void	process_pipe(t_token *token, int in, int out)
{
	int	pipe_fds[2];

	pipe(pipe_fds);
	process(token->left, in, pipe_fds[1]);
	ft_close(pipe_fds[1]);
	process(token->right, pipe_fds[0], out);
	ft_close(pipe_fds[0]);
	wait_token(token);
}
