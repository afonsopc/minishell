/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:03:21 by afpachec          #+#    #+#             */
/*   Updated: 2025/04/03 14:00:08 by paude-so         ###   ########.fr       */
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

static void	cd_error(char *str, int errornb)
{
	terminal()->status = errornb;
	ft_fputstr(2, str);
}

static char	*get_target_directory(t_cmd *cmd)
{
	char	*dir;

	dir = NULL;
	if (cmd->args[1])
	{
		if (ft_strequal(cmd->args[1], "-")
			&& ft_hashmap_get_value(terminal()->env, "OLDPWD"))
		{
			dir = ft_hashmap_get_value(terminal()->env, "OLDPWD");
			if (dir)
				ft_fputstr(1, dir);
			ft_fputstr(1, "\n");
		}
		else
			dir = cmd->args[1];
	}
	else
	{
		dir = ft_hashmap_get_value(terminal()->env, "HOME");
		if (!dir)
			cd_error("cd: HOME not set\n", 1);
	}
	return (dir);
}

static void	change_directory(char *dir)
{
	if (chdir(dir) == -1)
	{
		chdir_error(dir);
		terminal()->status = 1;
		return ;
	}
	ft_hashmap_set(terminal()->env, "OLDPWD",
		ft_strdup(ft_hashmap_get_value(terminal()->env, "PWD")), free);
	ft_hashmap_set(terminal()->env, "PWD", get_cwd(), free);
}

pid_t	execute_cd(t_cmd *cmd)
{
	char	*dir;

	ft_close2(cmd->in, cmd->out);
	terminal()->status = 0;
	if (cmd->in != 0 || cmd->out != 1)
		return (0);
	if (cmd->args[0] && cmd->args[1] && cmd->args[2])
		cd_error("cd: too many arguments\n", 1);
	else
	{
		dir = get_target_directory(cmd);
		if (dir)
			change_directory(dir);
	}
	return (0);
}
