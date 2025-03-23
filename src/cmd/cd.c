/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:03:21 by afpachec          #+#    #+#             */
/*   Updated: 2025/03/23 11:21:46 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <execution.h>

static void	chdir_error(char *dir)
{
	char	*tmp;
	char	*tmp2;

	tmp = str().join("cd: ", dir);
	tmp2 = tmp;
	tmp = str().join(tmp, ": ");
	free(tmp2);
	tmp2 = tmp;
	tmp = str().join(tmp, strerror(errno));
	free(tmp2);
	tmp2 = tmp;
	tmp = str().join(tmp, "\n");
	free(tmp2);
	(str().fputstr)(2, tmp);
	free(tmp);
}

static void	too_many_args_error(void)
{
	terminal()->status = 1;
	(str().fputstr)(2, "cd: too many arguments\n");
}

void	execute_cd(t_cmd *cmd)
{
	char	*dir;

	dir = NULL;
	if (cmd->args[0] && cmd->args[1] && cmd->args[2])
		too_many_args_error();
	else if (cmd->args[1])
		dir = cmd->args[1];
	else
		dir = hashmap(terminal()->env)->get_key("HOME");
	if (dir)
	{
		if (chdir(dir) == -1)
		{
			chdir_error(dir);
			terminal()->status = 1;
		}
		(hashmap(terminal()->env))->put(str().copy("PWD"), get_cwd());
	}
	terminal()->status = 0;
	ft_exit_free();
}
