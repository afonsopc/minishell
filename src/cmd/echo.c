/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 12:36:36 by paude-so          #+#    #+#             */
/*   Updated: 2025/04/01 16:17:45 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static bool	check_flag(char *str)
{
	if (!str || *str != '-')
		return (false);
	str++;
	while (*str)
	{
		if (*str != 'n')
			return (false);
		str++;
	}
	return (true);
}

pid_t	execute_echo(t_cmd *cmd)
{
	int		i;

	i = 1;
	while (cmd->args[i] && check_flag(cmd->args[i]))
		i++;
	while (cmd->args[i])
	{
		ft_fputstr(cmd->out, cmd->args[i]);
		if (cmd->args[i + 1])
			ft_fputstr(cmd->out, " ");
		++i;
	}
	if (!check_flag(cmd->args[1]))
		ft_fputstr(cmd->out, "\n");
	terminal()->status = 0;
	ft_close2(cmd->in, cmd->out);
	return (0);
}
