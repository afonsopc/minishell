/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 16:55:27 by edos-san          #+#    #+#             */
/*   Updated: 2024/12/23 18:15:17 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

pid_t	execute_unset(t_cmd *cmd, int in, int out)
{
	size_t	i;

	i = 1;
	while (cmd->args[i])
		hashmap(terminal()->env)->remove_key(cmd->args[i++]);
	ft_close(out);
	ft_close(in);
	return (0);
}
