/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 21:23:46 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/19 23:21:36 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"

void	process_and(t_token *token, int fds[2])
{
	process(token->left, true, fds);
	if (terminal()->status != 0)
		return ;
	process(token->right, true, fds);
}
