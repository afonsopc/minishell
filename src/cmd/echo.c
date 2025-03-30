/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:36:36 by paude-so          #+#    #+#             */
/*   Updated: 2025/03/29 16:46:55 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static bool	check_flag(char *str)
{
	if (!str || *str != '-')
		return (false);
	str++;
	while (*str == 'n')
		str++;
	return ((*str == '\0'));
}

pid_t	execute_echo(t_cmd *cmd)
{
	bool	flag;
	int		i;

	flag = check_flag(cmd->args[1]);
	i = 0;
	if (flag)
		i++;
	while (cmd->args[++i])
	{
		ft_fputstr(cmd->out, cmd->args[i]);
		if (cmd->args[i + 1])
			ft_fputstr(cmd->out, " ");
	}
	if (!flag)
		ft_fputstr(cmd->out, "\n");
	terminal()->status = 0;
	ft_close2(cmd->in, cmd->out);
	return (0);
}
