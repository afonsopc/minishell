/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 21:24:25 by afpachec          #+#    #+#             */
/*   Updated: 2025/01/09 18:33:50 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <execution.h>

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
