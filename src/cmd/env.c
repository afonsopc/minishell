/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 16:55:27 by paude-so          #+#    #+#             */
/*   Updated: 2025/03/29 15:20:15 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

pid_t	execute_env(t_cmd *cmd)
{
	size_t	i;
	char	**args;

	(void)cmd;
	i = -1;
	args = ft_hashmap_to_strv(terminal()->env);
	while (args[++i])
	{
		ft_fputstr(cmd->out, args[i]);
		ft_fputstr(cmd->out, "\n");
	}
	terminal()->status = 0;
	ft_close2(cmd->in, cmd->out);
	return (0);
}
