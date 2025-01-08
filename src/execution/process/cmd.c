/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 21:24:04 by afpachec          #+#    #+#             */
/*   Updated: 2024/12/24 14:44:00 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"

void	process_cmd(t_token	*token, int in, int out)
{
	if (token->cmd->execute)
		token->pid = token->cmd->execute(token->cmd, in, out);
}
