/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:03:21 by afpachec          #+#    #+#             */
/*   Updated: 2025/03/29 15:20:15 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

pid_t	execute_pwd(t_cmd *cmd)
{
	(void)cmd;
	ft_fputstr(cmd->out, (char *)ft_hashmap_get_value(terminal()->env, "PWD"));
	ft_fputstr(cmd->out, "\n");
	terminal()->status = 0;
	ft_close2(cmd->in, cmd->out);
	return (0);
}
