/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edos-san <edos-san@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 16:55:27 by edos-san          #+#    #+#             */
/*   Updated: 2024/12/23 18:13:12 by edos-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

pid_t	execute_env(t_cmd *cmd, int in, int out)
{
	size_t	i;
	char	**args;

	i = -1;
	args = hashmap(terminal()->env)->to_array();
	while (args[++i])
	{	
		write(out, args[i], str().size(args[i]));
		write(out, "\n", 1);
	}
	ft_close(out);
	ft_close(in);
	return (0);
}
