/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afonsocoutinho <afonsocoutinho@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 16:55:27 by paude-so          #+#    #+#             */
/*   Updated: 2025/03/23 23:39:29 by afonsocouti      ###   ########.fr       */
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
		ft_fputstr(1, args[i]);
		ft_fputstr(1, "\n");
	}
	terminal()->status = 0;
	ft_exit_free();
}
