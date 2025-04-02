/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 16:55:27 by paude-so          #+#    #+#             */
/*   Updated: 2025/04/02 20:54:37 by afpachec         ###   ########.fr       */
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
	ft_strvfree(args);
	terminal()->status = 0;
	ft_close2(cmd->in, cmd->out);
	return (0);
}
