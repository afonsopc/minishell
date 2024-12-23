/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 21:24:23 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/23 15:26:53 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"

void	process_or(t_token *token, int in, int out)
{
	process(token->left, in, out);
	wait_token(token->left);
	if (terminal()->status == 0)
		return ;
	process(token->right, in, out);
	wait_token(token->right);
}
