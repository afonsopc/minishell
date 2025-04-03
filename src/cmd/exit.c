/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paude-so <paude-so@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:03:21 by afpachec          #+#    #+#             */
/*   Updated: 2025/04/03 13:34:54 by paude-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

long	legal_number(char *string)
{
	long long	value;

	if (!string || !*string)
		return (ft_set_errno(EINVAL), 0);
	errno = 0;
	value = ft_atoll(string);
	if (errno)
		return (ft_set_errno(EINVAL), 0);
	return (value);
}

int	str_to_status(char *string)
{
	if (!string)
		return (0);
	return (legal_number(string) & 255);
}

pid_t	execute_exit(t_cmd *cmd)
{
	ft_close2(cmd->in, cmd->out);
	errno = 0;
	terminal()->status = str_to_status(cmd->args[1]);
	if (errno)
	{
		terminal()->status = 2;
		ft_fputstr(2, "exit: ");
		ft_fputstr(2, cmd->args[1]);
		ft_fputstr(2, ": numeric argument required\n");
	}
	else if (cmd->args[1] && cmd->args[2])
	{
		terminal()->status = 1;
		ft_fputstr(2, "exit: too many arguments\n");
		return (0);
	}
	ft_exit();
	return (0);
}
