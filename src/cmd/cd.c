/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:03:21 by afpachec          #+#    #+#             */
/*   Updated: 2025/03/29 15:20:15 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <execution.h>

static void	chdir_error(char *dir)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_strjoin("cd: ", dir);
	tmp2 = tmp;
	tmp = ft_strjoin(tmp, ": ");
	free(tmp2);
	tmp2 = tmp;
	tmp = ft_strjoin(tmp, strerror(errno));
	free(tmp2);
	tmp2 = tmp;
	tmp = ft_strjoin(tmp, "\n");
	free(tmp2);
	ft_fputstr(2, tmp);
	free(tmp);
}

static void	too_many_args_error(void)
{
	terminal()->status = 1;
	ft_fputstr(2, "cd: too many arguments\n");
}

pid_t	execute_cd(t_cmd *cmd)
{
	char	*dir;

	ft_close2(cmd->in, cmd->out);
	terminal()->status = 0;
	dir = NULL;
	if (cmd->args[0] && cmd->args[1] && cmd->args[2])
		too_many_args_error();
	else if (cmd->args[1])
		dir = cmd->args[1];
	else
		dir = ft_hashmap_get_value(terminal()->env, "HOME");
	if (dir)
	{
		if (chdir(dir) == -1)
		{
			chdir_error(dir);
			terminal()->status = 1;
		}
		ft_hashmap_set(terminal()->env, ft_strdup("PWD"), get_cwd(), free);
	}
	return (0);
}
