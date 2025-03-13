/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 16:55:27 by paude-so          #+#    #+#             */
/*   Updated: 2025/03/13 12:31:29 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

pid_t	execute_env(t_cmd *cmd, int in, int out)
{
	size_t	i;
	char	**args;

	(void)cmd;
	i = -1;
	args = hashmap(terminal()->env)->to_array();
	while (args[++i])
	{
		(str().fputstr)(out, args[i]);
		(str().fputstr)(out, "\n");
	}
	ft_close(out);
	ft_close(in);
	return (0);
}
