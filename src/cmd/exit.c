/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afpachec <afpachec@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:03:21 by afpachec          #+#    #+#             */
/*   Updated: 2025/02/16 23:57:42 by afpachec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

long	legal_number(char *string)
{
	long long	value;

	if (!string || !*string)
		return (set_errno(EINVAL), 0);
	errno = 0;
	value = str().atoll(string);
	if (errno)
		return (set_errno(EINVAL), 0);
	return (value);
}

int	str_to_status(char *string)
{
	if (!string)
		return (0);
	return (legal_number(string) & 255);
}

pid_t	execute_exit(t_cmd *cmd, int in, int out)
{
	ft_close(out);
	ft_close(in);
	errno = 0;
	if (cmd->args[2])
	{
		terminal()->status = 1;
		(str().fputstr)(2, "exit: too many arguments\n");
		ft_exit();
	}
	terminal()->status = str_to_status(cmd->args[1]);
	if (errno)
	{
		terminal()->status = 255;
		(str().fputstr)(2, "exit: ");
		(str().fputstr)(2, cmd->args[1]);
		(str().fputstr)(2, ": numeric argument required\n");
	}
	ft_exit();
	return (0);
}
