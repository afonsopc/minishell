/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 16:55:27 by paude-so          #+#    #+#             */
/*   Updated: 2025/03/23 11:38:53 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	execute_env(t_cmd *cmd)
{
	size_t	i;
	char	**args;

	(void)cmd;
	i = -1;
	args = hashmap(terminal()->env)->to_array();
	while (args[++i])
	{
		(str().fputstr)(1, args[i]);
		(str().fputstr)(1, "\n");
	}
	terminal()->status = 0;
	ft_exit_free();
}
