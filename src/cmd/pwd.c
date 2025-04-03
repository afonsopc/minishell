/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:03:21 by afpachec          #+#    #+#             */
/*   Updated: 2025/04/04 00:26:40 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <execution.h>

pid_t	execute_pwd(t_cmd *cmd)
{
	char	*pwd;

	pwd = get_cwd();
	ft_fputstr(cmd->out, pwd);
	free(pwd);
	ft_fputstr(cmd->out, "\n");
	terminal()->status = 0;
	ft_close2(cmd->in, cmd->out);
	return (0);
}
