/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:03:21 by afpachec          #+#    #+#             */
/*   Updated: 2025/01/09 02:58:23 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <execution.h>

pid_t	execute_cd(t_cmd *cmd, int in, int out)
{
	char	*dir;

	if (cmd->args[1])
		dir = cmd->args[1];
	else
		dir = hashmap(terminal()->env)->get_key("HOME");
	if (chdir(dir) == -1)
		printf("cd: %s: %s\n", dir, strerror(errno));
	(hashmap(terminal()->env))->put(str().copy("PWD"), get_cwd());
	ft_close(out);
	ft_close(in);
	return (0);
}
